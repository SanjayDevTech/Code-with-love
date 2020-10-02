//
//  MPI and OpenMP hybrid merge sort
//  How to run (for 4 core machine): mpiexec -n 2 -cores 2 main.exe
//

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <random>
#include <chrono>
#include <mpi.h>
#include <omp.h>

// switch to insertion sort for small arrays
#define SMALL    32
#define CUTOFF 1000

void merge (int a[], int size, int temp[]);
void insertion_sort (int a[], int size);
void mergesort_serial (int a[], int size, int temp[]);
void mergesort_parallel (int *a, int size, int *temp,
                         int level, int my_rank, int max_rank,
                         int tag, MPI_Comm comm);
int my_topmost_level_mpi (int my_rank);
void exec_master (int *a, int size, int *temp, int max_rank, int tag,
                  MPI_Comm comm);
void exec_slaves (int my_rank, int max_rank, int tag, MPI_Comm comm);

void mergesort_parallel_omp (int a[], int size, int temp[])
{
    if (size < CUTOFF) {
        mergesort_serial(a, size, temp);
        return;
    }
#pragma omp task
    mergesort_parallel_omp(a, size/2, temp);
#pragma omp task
    mergesort_parallel_omp(a + size/2, size - size/2, temp + size/2);

#pragma omp taskwait
    merge(a, size, temp);
}

int main (int argc, char *argv[])
{
    int arrsize = 1e6;
    std::default_random_engine gen;
    gen.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> dist(0, 1e6);
    int *a;
    int *temp;
    MPI_Init (&argc, &argv);
    int size;
    MPI_Comm_size (MPI_COMM_WORLD, &size);
    int rank;
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    int max_rank = size - 1;
    int tag = 123;
    long long int sum = 0;
    if (rank == 0) {
        a = new int[arrsize];
        temp = new int[arrsize];
    }
    if (rank == 0) {
        for (int i = 0; i < length; i++) a[i] = dist(gen); //generate random values
        //running algorithm
        exec_master(a, length, temp, max_rank, tag, MPI_COMM_WORLD);
    }
    else
    {
        //running algorithm for slave processes
        exec_slaves (rank, max_rank, tag, MPI_COMM_WORLD);
    }
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
    return 0;
}

void exec_master(int a[], int size, int temp[], int max_rank, int tag, MPI_Comm comm)
{
    int my_rank;
    MPI_Comm_rank (comm, &my_rank);
    mergesort_parallel (a, size, temp, 0, my_rank, max_rank, tag, comm);
}

void exec_slaves (int my_rank, int max_rank, int tag, MPI_Comm comm)
{
    int level = my_topmost_level_mpi (my_rank);
    // probe for a message and determine its size and sender
    MPI_Status status;
    int size;
    MPI_Probe (MPI_ANY_SOURCE, tag, comm, &status);
    MPI_Get_count (&status, MPI_INT, &size);
    int parent_rank = status.MPI_SOURCE;
    int* a = new int[size];
    int *temp = new int[size];
    MPI_Recv (a, size, MPI_INT, parent_rank, tag, comm, &status);
    mergesort_parallel (a, size, temp, level, my_rank, max_rank, tag, comm);
    // Send sorted array to parent process
    MPI_Send (a, size, MPI_INT, parent_rank, tag, comm);
}

// Calculate number of next process to send data (root is always 0)
int my_topmost_level_mpi (int my_rank)
{
    int level = 0;
    while (pow (2, level) <= my_rank)
        level++;
    return level;
}

// MPI merge sort
void mergesort_parallel (int a[], int size, int temp[],
                        int level, int my_rank, int max_rank,
                        int tag, MPI_Comm comm)
{
    int helper_rank = my_rank + pow (2, level);
    if (helper_rank > max_rank)
    {				// no more processes available
//        printf("rank: %d, sorting %d element by myself\n", my_rank, size);
        #pragma omp parallel
        #pragma omp single
        mergesort_parallel_omp(a, size, temp);
    }
    else
    {
        MPI_Request request;
        MPI_Status status;
        // Send second half, asynchronous
//        printf("rank: %d, send %d element to %d\n", my_rank, size - size / 2, helper_rank);
        MPI_Isend (a + size / 2, size - size / 2, MPI_INT, helper_rank, tag,
                   comm, &request);
        // Sort first half
        mergesort_parallel (a, size / 2, temp, level + 1, my_rank, max_rank,
                                tag, comm);
        MPI_Request_free (&request);
        // Receive second half sorted
        MPI_Recv (a + size / 2, size - size / 2, MPI_INT, helper_rank, tag,
                  comm, &status);
        // Merge the two sorted sub-arrays through temp
        merge(a, size, temp);
    }
}

void mergesort_serial(int a[], int size, int temp[])
{
    // Switch to insertion sort for small arrays
    if (size <= SMALL)
    {
        insertion_sort (a, size);
        return;
    }
    mergesort_serial (a, size / 2, temp);
    mergesort_serial (a + size / 2, size - size / 2, temp);
    // Merge the two sorted subarrays into a temp array
    merge (a, size, temp);
}

//merge in serial way
void merge(int a[], int size, int temp[])
{
    int i1 = 0;
    int i2 = size / 2;
    int tempi = 0;
    while (i1 < size / 2 && i2 < size)
    {
        if (a[i1] < a[i2])
        {
            temp[tempi] = a[i1];
            i1++;
        }
        else
        {
            temp[tempi] = a[i2];
            i2++;
        }
        tempi++;
    }
    while (i1 < size / 2)
    {
        temp[tempi] = a[i1];
        i1++;
        tempi++;
    }
    while (i2 < size)
    {
        temp[tempi] = a[i2];
        i2++;
        tempi++;
    }
    // Copy sorted temp array into main array, a
    memcpy(a, temp, size * sizeof (int));
}

void insertion_sort (int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int j, v = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] <= v) break;
            a[j + 1] = a[j];
        }
        a[j + 1] = v;
    }
}
