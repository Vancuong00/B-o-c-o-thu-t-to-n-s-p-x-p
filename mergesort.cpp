#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

const int N = 1000000;

void merge(vector<double>& arr, int l, int m, int r) {
    vector<double> left(arr.begin() + l, arr.begin() + m + 1);
    vector<double> right(arr.begin() + m + 1, arr.begin() + r + 1);

    int i = 0, j = 0, k = l;
    while (i < left.size() && j < right.size()) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < left.size()) arr[k++] = left[i++];
    while (j < right.size()) arr[k++] = right[j++];
}

void mergeSort(vector<double>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Ket qua mergesort (Don vi: ms) \n";
    for (int fileIdx = 1; fileIdx <= 10; ++fileIdx) {
        ifstream fin("test" + to_string(fileIdx) + ".txt");
        vector<double> data(N);
        for (int i = 0; i < N; ++i) fin >> data[i];
        fin.close();

        auto start = high_resolution_clock::now();
        mergeSort(data, 0, N - 1);
        auto end = high_resolution_clock::now();

        double elapsed = duration<double, milli>(end - start).count();
        cout << "Day " << fileIdx << ": " << elapsed << " ms\n";
    }
    return 0;
}
