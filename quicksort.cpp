#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <string>
using namespace std;
using namespace std::chrono;
const int N = 1000000;

int partition(vector<double>& arr, int low, int high) {
    int pivotIdx = low + rand() % (high - low + 1);
    swap(arr[pivotIdx], arr[high]);
    double pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<double>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << " Ket qua quicksort (Don vi: ms) \n";
    for (int fileIdx = 1; fileIdx <= 10; ++fileIdx) {
        ifstream fin("test" + to_string(fileIdx) + ".txt");
        vector<double> data(N);
        for (int i = 0; i < N; ++i) fin >> data[i];
        fin.close();

        auto start = high_resolution_clock::now();
        quickSort(data, 0, N - 1);
        auto end = high_resolution_clock::now();

        double elapsed = duration<double, milli>(end - start).count();
        cout << "Day " << fileIdx << ": " << elapsed << " ms\n";
    }
    return 0;
}
