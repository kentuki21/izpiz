#include <iostream>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

using namespace std::chrono;

int shellSort(int* arr, int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];

            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
int main() {
    srand(time(0));
    long long dur = 0;
    ofstream fout("ShellSortResoults.txt");
    for (int k = 1; k <= 1000; k++) {
        int* arr = new int[10000000];
        for (int i = 0; i < 10000000; i++) {
            arr[i] = rand();
        }
        auto arr_size = 10000000;

        auto start = high_resolution_clock::now();

        shellSort(arr, arr_size);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        dur += duration.count();

        fout << k << " try " << duration.count() << " microseconds" << endl;
        cout << k << " try " << duration.count() << " microseconds" << endl;

        delete[] arr;
    }

    fout << "average value " << dur / 1000;
    cout << "average value " << dur / 1000;

    return 0;
}