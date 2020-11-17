#include <mpi.h>
#include <iostream>
#include <functional>
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>
#include <omp.h>

#define SMALL 32

void quickSort_parallel(long *array, int lenArray);
void quickSort_parallel_internal(long *array, int left, int right, int cutoff);
void insertion_sort (long a[], int size);
void quickSort_parallel(long *array, int lenArray){

    int cutoff = 1000;
//    int numThreads = 4;

//#pragma omp parallel num_threads(numThreads)
#pragma omp parallel
    {
#pragma omp single nowait
        {
            quickSort_parallel_internal(array, 0, lenArray-1, cutoff);
        }
    }

}

void quickSort_parallel_internal(long *array, int left, int right, int cutoff)
{

    int i = left, j = right;
    int tmp;
    int pivot = array[(left + right) / 2];
    if((right - left) <= SMALL) {
        insertion_sort(array, right - left + 1);
        return;
    }
    {
        /* PARTITION PART */
        while (i <= j) {
            while (array[i] < pivot)
                i++;
            while (array[j] > pivot)
                j--;
            if (i <= j) {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
                i++;
                j--;
            }
        }

    }


    if ( ((right-left)<cutoff) ){
        if (left < j){ quickSort_parallel_internal(array, left, j, cutoff); }
        if (i < right){ quickSort_parallel_internal(array, i, right, cutoff); }

    }else{
#pragma omp task
        { quickSort_parallel_internal(array, left, j, cutoff); }
#pragma omp task
        { quickSort_parallel_internal(array, i, right, cutoff); }
    }

}

void insertion_sort(long *a, int size) {
    int i;
    for (i = 0; i < size; i++)
    {
        int j, v = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] <= v)
                break;
            a[j + 1] = a[j];
        }
        a[j + 1] = v;
    }
}


void division(long* arr, long left, long right, long &t){
    long x = arr[left];
    t = left;
    for(long i = left + 1; i <= right; i++) {
        if(arr[i] < x) {
         t++;
         std::swap(arr[t], arr[i]);
        }
    }
    std::swap(arr[left], arr[t]);
}



void qs(long* arr, long left, long right) {
    if((right - left) <= SMALL) {
        insertion_sort (arr, right - left + 1);
    } else {
         long t = 0;
         division(arr, left, right, t);
         qs(arr, left, t);
         qs(arr, t + 1, right);
    }
}

int main(int argc, char** argv) {
    long* array;
    int size = 0, rank = 0;
    int arrsize = 1e6;
    std::default_random_engine gen;
    std::uniform_int_distribution<int> dist(0, 1e6);
    gen.seed(std::chrono::system_clock::now().time_since_epoch().count());
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Status status;
    long long int sum = 0;
    if (rank == 0) array = new long[arrsize];
    long* part = new long[arrsize];
    if (rank == 0) {
        for (int i = 0; i < length; ++i) array[i] = dist(gen);
    }
    long first = 0;
    long plength = length;
    part = array;
    long current = rank;
    long lastrank = size - 1;

    if (rank != 0) {
        MPI_Recv(&first, 1, MPI_LONG, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(&plength, 1, MPI_LONG, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
        part = new long[plength];
        //receiving our part of array
        MPI_Recv(part, plength, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
        MPI_Recv(&lastrank, 1, MPI_LONG, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &status);
    }
    long l = 0;
    long r = plength - 1;
    long m;
    //calculating next process to which we will send data
    long dest = current + (lastrank - current + 1) / 2;
    long templast = lastrank;
    //while there are free processes
    while (dest > current) {
        //divide array by pivot
        division(part, l, r, m);
        long pos = 0;
        long count = 0;
        //dealing with different part lengths
        if (m - l + 1 <= r - m) {
            pos = l;
            count = m - l + 1;
            l = m + 1;
        } else {
            pos = m + 1;
            count = r - m;
            r = m;
        }
        MPI_Send(&pos, 1, MPI_LONG, dest, 0, MPI_COMM_WORLD);
        MPI_Send(&count, 1, MPI_LONG, dest, 0, MPI_COMM_WORLD);
        //sending the smallest part to next process
        MPI_Send(part + pos, count, MPI_INT, dest, 0, MPI_COMM_WORLD);
        MPI_Send(&templast, 1, MPI_LONG, dest, 0, MPI_COMM_WORLD);
        //decrementing the number of free processes
        templast = dest - 1;
        //calculating next process to send data
        dest = current + (templast - current + 1) / 2;
    }
    //sorting our part locally
//            qs(part, l, r);
    quickSort_parallel(part+l, r - l );
    dest = current + (lastrank - current + 1) / 2;
    while (dest > current) {
        long pos;
        long count;
        MPI_Recv(&pos, 1, MPI_LONG, dest, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        MPI_Recv(&count, 1, MPI_LONG, dest, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        //receiving back sorted data
        MPI_Recv(part + pos, count, MPI_INT, dest, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        dest = current + (dest - current) / 2;
    }
    if (rank != 0) {
        //sending sorted data to previous process
        MPI_Send(&first, 1, MPI_LONG, status.MPI_SOURCE, 0, MPI_COMM_WORLD);
        MPI_Send(&plength, 1, MPI_LONG, status.MPI_SOURCE, 0, MPI_COMM_WORLD);
        MPI_Send(part, plength, MPI_INT, status.MPI_SOURCE, 0, MPI_COMM_WORLD);
//                delete[] part;
    } else {
        end = std::chrono::high_resolution_clock::now();
        auto elapsed_ns = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        sum += elapsed_ns.count();

    }
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
    fclose(pfile);
    return 0;
}

