#include <iostream>
#include <vector>
#include <chrono>

bool Unique(const std::vector<int>& A) {
    int n = A.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector<int> sizes = {1000, 5000, 10000, 20000};

    for (int n : sizes) {
        std::vector<int> A(n);
        for (int i = 0; i < n; i++) A[i] = i;

        auto begin = std::chrono::high_resolution_clock::now();
        bool result = Unique(A);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
        std::cout << "n = " << n << " | Time: " << duration << " microseconds" << std::endl;
    }

    return 0;
}