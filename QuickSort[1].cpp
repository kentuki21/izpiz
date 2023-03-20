#include <iostream>
#include <random>
#include <chrono>
#include <clocale>
#include <fstream>

using namespace std;
using namespace std::chrono;

void QuickSort(int arr[], const int left, const int right) {
    int i = left, j = right;
    int tmp;
    int middle = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < middle) i++;
        while (arr[j] > middle) j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    if (left < j)
        QuickSort(arr, left, j);
    if (i < right)
        QuickSort(arr, i, right);
}


int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    long long dur = 0;
    ofstream fout("QickSortResults.txt");
    for (int k = 1; k <= 1000; k++) {
        int* arr = new int[10000000];
        for (int i = 0; i < 10000000; i++) {
            arr[i] = rand();
        }
        auto arr_size = 10000000;

        auto start = high_resolution_clock::now();

        QuickSort(arr, 0, arr_size - 1);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        dur += duration.count();

        fout << k << " попытка " << duration.count() << " микросекунд" << endl;
        cout << k << " попытка " << duration.count() << " микросекунд" << endl;

        delete[] arr;
    }

    fout << "Среднее значение " << dur / 1000;
    cout << "Среднее значение " << dur / 1000;

    return 0;
}
