#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;
void heapify(int* arr, int n, int root)
{
    int largest = root; 
    int l = 2 * root + 1;
    int r = 2 * root + 2; 

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != root)
    {
        swap(arr[root], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int* arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}
void displayArray(int* arr, int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    long long dur = 0;
    ofstream fout("MergeSortResults.txt");
    for (int k = 1; k <= 1000; k++) {
        int* arr = new int[10000000];
        for (int i = 0; i < 10000000; i++) {
            arr[i] = rand();
        }
        auto arr_size = 10000000;

        auto start = high_resolution_clock::now();

        heapSort(arr, arr_size);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        dur += duration.count();

        fout << k << " попытка " << duration.count() << " микросекунд" << endl;
        cout << k << " попытка " << duration.count() << " микросекунд" << endl;

        delete[] arr;
    }

    fout << "среднее значение " << dur / 1000;
    cout << "среднее значение " << dur / 1000;

    return 0;
}
