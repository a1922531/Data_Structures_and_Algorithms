// COMP 2017 - Practical 1
//
// I declare this submission is my own work and has not been copied from any other source.
// Name: Luke Humphris
// a#: a1922531
//

#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0; // no input
    if (n <= 0) { cout << "0\n"; return 0; }

    vector<int> v(static_cast<size_t>(n));
    for (int i = 0; i < n; ++i) v[i] = i;

    // seed RNG
    srand(static_cast<unsigned int>(time(nullptr)));

    const int accesses = 1000;
    volatile long long sum = 0; // volatile to discourage optimization-out of the loop

    // Measure the time taken to perform `accesses` random lookups
    auto start = chrono::high_resolution_clock::now();
    for (int i = 0; i < accesses; ++i) {
        int idx = rand() % n;
        sum += v[idx];
    }
    auto end = chrono::high_resolution_clock::now();

    // total elapsed time in microseconds
    auto total_us = chrono::duration_cast<chrono::microseconds>(end - start).count();
    double average_us = static_cast<double>(total_us) / accesses;

    // Output only the average access time (single number, in microseconds)
    cout << fixed << setprecision(6) << average_us << '\n';

    // Use sum in a way that prevents it being optimized out (noop)
    (void)sum;
    return 0;
}

