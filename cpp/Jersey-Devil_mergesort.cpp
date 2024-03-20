//
// Created by Ilia Mavrin on 15/02/2020.
//
#include <random>
#include <chrono>
#include <iostream>
#include <stdio.h>
#include <mpi.h>
//Switch to insertinon sort for small arrays
#define SMALL 32

void insertion_sort (int* a, int size);
void merge(int* a, int size, int* temp);

void mergesort_serial(int* a, int size, int* temp)
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
    merge(a, size, temp);
}


void insertion_sort(int *a, int size) {
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

void merge(int *a, int size, int *temp) {
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

int main(int argc, char** argv) {
    int arrsize = 1e6
    std::default_random_engine gen;
    std::uniform_int_distribution<int> dist(0, 1e6);
    gen.seed(std::chrono::system_clock::now().time_since_epoch().count());
    int* a = new int[arrsize];
    //initialize buffer at the beginning
    int* temp = new int[arrsize];
    long long int sum = 0;
    for (size_t j = 0; j < n; ++j) a[j] = dist(gen);
    mergesort_serial(a, n, temp);
    delete[] a;
    delete[] temp;
    return 0;
}


