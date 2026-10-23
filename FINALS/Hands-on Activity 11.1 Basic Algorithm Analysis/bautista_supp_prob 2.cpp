#include <iostream>
#include <vector>
#include <chrono>

long long rpower(int x, int n) {
    if (n == 0) return 1;
    return x * rpower(x, n - 1);
}

long long brpower(int x, int n) {
    if (n == 0) return 1;
    if (n % 2 != 0) {
        long long y = brpower(x, (n - 1) / 2);
        return x * y * y;
    } else {
        long long y = brpower(x, n / 2);
        return y * y;
    }
}

int main() {
    int x = 2;
    std::vector<int> exponents = {100, 500, 1000, 5000};
    const int iterations = 10000;

    for (int n : exponents) {
        auto begin1 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < iterations; i++) {
            volatile long long res = rpower(x, n % 30);
        }
        auto end1 = std::chrono::high_resolution_clock::now();
        auto dur1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1).count();

        auto begin2 = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < iterations; i++) {
            volatile long long res = brpower(x, n % 30);
        }
        auto end2 = std::chrono::high_resolution_clock::now();
        auto dur2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2).count();

        std::cout << "n = " << n 
                  << " | rpower: " << dur1 / (double)iterations << " ns"
                  << " | brpower: " << dur2 / (double)iterations << " ns" << std::endl;
    }

    return 0;
}