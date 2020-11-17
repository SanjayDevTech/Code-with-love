#include <mpi.h>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <chrono>
#include <omp.h>

#define b sizeof(int)*8           // number of bits for integer
#define g 8            // group of bits for each scan
#define N b / g        // number of passes
#define B (1 << g)     // number of buckets, 2^g

// MPI tags, offset by max bucket to avoid collisions
#define COUNTS_TAG_NUM  B + 1
#define PRINT_TAG_NUM  COUNTS_TAG_NUM + 1
#define NUM_TAG PRINT_TAG_NUM + 1

// structure for buckets with arrays of elements
struct Bucket {
    int* array;
    size_t length;
    size_t capacity;
};

// add item to a dynamic array in a structure
int add_item(Bucket* bucket, int item) {
    if (bucket->length >= bucket->capacity) {
        size_t new_capacity = bucket->capacity * 2;
        int* temp = static_cast<int *>(realloc(bucket->array, new_capacity * sizeof(int)));
        if (!temp) {
            printf("Could not realloc for size %d!\n", (int) new_capacity);
            return 0;
        }
        bucket->array = temp;
        bucket->capacity = new_capacity;
    }

    bucket->array[bucket->length++] = item;

    return 1;
}


// get j bits with offset k bits from the right in x
// e.g. to get rightmost bit of x call bits(x, 0, 1)
unsigned bits(unsigned x, int k, int j) {
    return (x >> k) & ~(~0 << j);
}

// P - total number of processes
// rank - rank of this process
// n - number of elements to be sorted
int* radix_sort(int *a, Bucket* buckets, const int P, const int rank, int * n) {
    int count[B][P];   // array of counts per bucket for all processes
    int l_count[B];    // array of local process counts per bucket
    int l_B = B / P;   // number of local buckets per process
    int p_sum[l_B][P]; // array of prefix sums

    MPI_Request req;
    MPI_Status stat;

    for (int pass = 0; pass < N; pass++) {

        // init counts arrays
        for (int j = 0; j < B; j++) {
            count[j][rank] = 0;
            l_count[j] = 0;
            buckets[j].length = 0;
        }

        // count items per bucket
        for (int i = 0; i < *n; i++) {
            unsigned int idx = bits(a[i], pass*g, g);
            count[idx][rank]++;
            l_count[idx]++;
            if (!add_item(&buckets[idx], a[i])) {
                return nullptr;
            }
        }

        // send counts of this process to others
        for (int p = 0; p < P; p++) {
            if (p != rank) {

                MPI_Isend(
                        l_count,
                        B,
                        MPI_INT,
                        p,
                        COUNTS_TAG_NUM,
                        MPI_COMM_WORLD,
                        &req);
            }
        }

        // receive counts from others
        for (int p = 0; p < P; p++) {
            if (p != rank) {
                MPI_Recv(
                        l_count,
                        B,
                        MPI_INT,
                        p,
                        COUNTS_TAG_NUM,
                        MPI_COMM_WORLD,
                        &stat);

                // distribute counts per bucket for other processes
                for (int i = 0; i < B; i++) {
                    count[i][p] = l_count[i];
                }
            }
        }

        // calculate new size based on values received from all processes
        int new_size = 0;
        for (int j = 0; j < l_B; j++) {
            int idx = j + rank * l_B;
            for (int p = 0; p < P; p++) {
                p_sum[j][p] = new_size;
                new_size += count[idx][p];
            }
        }

        // reallocate array if newly calculated size is larger
        if (new_size > *n) {
            int* temp = static_cast<int *>(realloc(a, new_size * sizeof(int)));
            if (!a) {
                if (rank == 0) {
                    printf("Could not realloc for size %d!\n", new_size);
                }
                return nullptr;
            }
            // reassign pointer back to original
            a = temp;
        }

        // send keys of this process to others
        for (int j = 0; j < B; j++) {
            int p = j / l_B;   // determine which process this buckets belongs to
            int p_j = j % l_B; // transpose to that process local bucket index
            if (p != rank && buckets[j].length > 0) {
                MPI_Isend(
                        buckets[j].array,
                        buckets[j].length,
                        MPI_INT,
                        p,
                        p_j,
                        MPI_COMM_WORLD,
                        &req);
            }
        }

        // receive keys from other processes
        for (int j = 0; j < l_B; j++) {
            // transpose from local to global index
            int idx = j + rank * l_B;
            for (int p = 0; p < P; p++) {

                // get bucket count
                int b_count = count[idx][p];
                if (b_count > 0) {

                    // point to an index in array where to insert received keys
                    int *dest = &a[p_sum[j][p]];
                    if (rank != p) {
                        MPI_Recv(
                                dest,
                                b_count,
                                MPI_INT,
                                p,
                                j,
                                MPI_COMM_WORLD,
                                &stat);

                    } else {
                        // if it is same process, copy from buckets to our array
                        memcpy(dest, &buckets[idx].array[0], b_count*sizeof(int));
                    }
                }
            }
        }

        // update new size
        *n = new_size;
    }

    return a;
}

int main(int argc, char** argv)
{
    int rank, size;
    int length = 1e6;
    std::default_random_engine gen;
    std::uniform_int_distribution<int> dist(0, 1e2);
    gen.seed(std::chrono::system_clock::now().time_since_epoch().count());

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    long long int sum = 0;
    int n = length / size;

    // if n is not divisible by size, make the last process handle the tail
    if (rank == size - 1) {
        int tail = length % size;
        if (tail > 0) {
            n += tail;
        }
    }

    int* a = static_cast<int*>(malloc(sizeof(int)*n));

    int b_capacity = n / B;
    if (b_capacity < B) {
        b_capacity = B;
    }
    //set up buckets
    Bucket* buckets = new Bucket[B];
    for (int j = 0; j < B; j++) {
        buckets[j].array = static_cast<int *>(malloc(b_capacity * sizeof(int)));
        buckets[j].capacity = b_capacity;
    }
    for (int i = 0; i < n; ++i) a[i] = dist(gen);

    MPI_Barrier(MPI_COMM_WORLD);

    a = radix_sort(&a[0], buckets, size, rank, &n);

    MPI_Barrier(MPI_COMM_WORLD);

    // store number of items per each process after the sort
    int* p_n = new int[size];

    // first store our own number
    p_n[rank] = n;

    // distribute number of items among other processes
    MPI_Request req;
    MPI_Status stat;

    for (int i = 0; i < size; i++) {
        if (i != rank) {
            MPI_Isend(
                    &n,
                    1,
                    MPI_INT,
                    i,
                    NUM_TAG,
                    MPI_COMM_WORLD,
                    &req);
        }
    }
    for (int i = 0; i < size; i++) {
        if (i != rank) {
            MPI_Recv(
                    &p_n[i],
                    1,
                    MPI_INT,
                    i,
                    NUM_TAG,
                    MPI_COMM_WORLD,
                    &stat);
        }
    }

    int totlen = 0;
    int *displs = nullptr;
    int *array = nullptr;

    // collecting sorted array on process 0
    if (rank == 0) {
        displs = new int[size];
        displs[0] = 0;
        totlen += p_n[0];
        for (int i=1; i<size; i++) {
            totlen += p_n[i];
            displs[i] = displs[i-1] + p_n[i-1];
        }
        array = new int[totlen];
    }
    MPI_Gatherv(a, p_n[rank], MPI_INT,
                array, p_n, displs, MPI_INT,
                0, MPI_COMM_WORLD);
    if(rank == 0) {
        //check if sorting is correct
//                int sorted_flag = 1;
//                for(int m = 0; m < totlen - 2; m++){
//                    if(array[m] > array[m + 1]){
//                        sorted_flag = 0;
//                    }
//                }
//                if(sorted_flag == 1){
//                    printf("\nSORTING CORRECT\n");
//                }else{
//                    printf("\nSORTING NOT CORRECT\n");
//                }
    }

    // free memory
    delete[] displs;
    delete[] array;
    for (int j = 0; j < B; j++) {
        free(buckets[j].array);
    }
    delete[] buckets;
    free(a); // because we can use realloc
    delete[] p_n;
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
    fclose(pfile);
    return 0;
}

