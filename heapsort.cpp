#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <string>
using namespace std;
using namespace std::chrono;
const int N = 1000000;

void heapify(vector<double>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<double>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Ket qua headsort (Don vi: ms) \n";
    for (int fileIdx = 1; fileIdx <= 10; ++fileIdx) {
        ifstream fin("test" + to_string(fileIdx) + ".txt");
        vector<double> data(N);
        for (int i = 0; i < N; ++i) fin >> data[i];
        fin.close();

        auto start = high_resolution_clock::now();
        heapSort(data);
        auto end = high_resolution_clock::now();

        double elapsed = duration<double, milli>(end - start).count();
        cout << "Day " << fileIdx << ": " << elapsed << " ms\n";
    }
    return 0;
}
