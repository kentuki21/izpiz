#include<iostream> 
#include<stdio.h> 
#include <cmath> 
#include <cstring> 
#include<string> 
#include <vector> 
#include<algorithm>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;
void insertionSort(int* arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    long long dur = 0;
    ofstream fout("output.txt");
    for (int k = 1; k <= 1000; k++) {
        int* arr = new int[10000000];
        for (int i = 0; i < 10000000; i++) {
            arr[i] = rand();
        }
        auto arr_size = 10000000;

        auto start = high_resolution_clock::now();

        insertionSort(arr, arr_size);

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<microseconds>(stop - start);

        dur += duration.count();

        fout << k << " Попытка " << duration.count() << "Микросек" << endl;
        cout << k << " Попытка " << duration.count() << " Микросекунд" << endl;

        delete[] arr;
    }

    fout << "Среднее значение " << dur / 1000;
    cout << "Среднее значение " << dur / 1000;
}