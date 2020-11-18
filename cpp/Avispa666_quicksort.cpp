#include <random>
#include <chrono>
#include <cstdio>

//main quicksort function
void qs(long *arr, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = arr[(left + right) / 2];
        do
        {
            while (arr[left] < middle) left++;
            while (arr[right] > middle) right--;
            if (left <= right)
            {
                int tmp = arr[left];
                arr[left] = arr[right];
                arr[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        qs(arr, first, right);
        qs(arr, left, last);
    }
}

int main(int argc, char** argv) {
    std::chrono::high_resolution_clock::time_point start, end;
    FILE *pfile;
    int attempts = 1;
    int arrcount = 41e6;
    std::default_random_engine gen;
    std::uniform_int_distribution<int> dist(0, 1e6);
    gen.seed(std::chrono::system_clock::now().time_since_epoch().count());
    pfile = fopen("quicksort-serial.dat", "w"); //can be ploted with gnuplot
    long long int sum = 0;
    long* a = new long[arrcount];
    for (int n = 1000; n < arrcount; n += 4e6) {
        sum = 0;
        for (int i = 0; i < attempts; ++i) {
            for (size_t j = 0; j < n; ++j) a[j] = dist(gen);
            start = std::chrono::high_resolution_clock::now();
            qs(a, 0, n - 1);
            end = std::chrono::high_resolution_clock::now();
            auto elapsed_ns = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
            sum += elapsed_ns.count();
        }
        fprintf(pfile, " %d\t %lld\n", n, sum / attempts);
    }
    delete[] a;
    fclose(pfile);
    return 0;
}
