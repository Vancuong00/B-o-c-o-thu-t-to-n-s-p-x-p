#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>
#include <string>

using namespace std;
using namespace std::chrono;

const int N = 1000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "Ket qua ham sort (Don vi: ms)\n";
    for (int fileIdx = 1; fileIdx <= 10; ++fileIdx) {
        ifstream fin("test" + to_string(fileIdx) + ".txt");
        vector<double> data(N);
        for (int i = 0; i < N; ++i) fin >> data[i];
        fin.close();

        auto start = high_resolution_clock::now();
        sort(data.begin(), data.end());
        auto end = high_resolution_clock::now();

        double elapsed = duration<double, milli>(end - start).count();
        cout << "Day " << fileIdx << ": " << elapsed << " ms\n";
    }
    return 0;
}
