#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <iomanip>
#include <string>
using namespace std;
const int N = 1000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mt19937 rng(42);
    uniform_real_distribution<double> dist(0.0, 1000000.0);

    cout << "Dang sinh du lieu\n";
    for (int fileIdx = 1; fileIdx <= 10; ++fileIdx) {
        vector<double> a(N);
        if (fileIdx == 1) {
            for (int i = 0; i < N; ++i) a[i] = i + 1.0;
        } else if (fileIdx == 2) {
            for (int i = 0; i < N; ++i) a[i] = N - i;
        } else {
            for (int i = 0; i < N; ++i) a[i] = dist(rng);
        }

        ofstream fout("test" + to_string(fileIdx) + ".txt");
        fout << fixed << setprecision(2);
        for (int i = 0; i < N; ++i) {
            fout << a[i] << (i == N - 1 ? "" : " ");
        }
        fout.close();
        cout << "Da tao xong test" << fileIdx << ".txt\n";
    }
    cout << "Hoan tat sinh du lieu\n";
    return 0;
}
