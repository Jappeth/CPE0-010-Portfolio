#include <iostream>
#include <chrono>

bool Unique(int *A, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (A[i] == A[j]) {
                return false;
            }
        }
    }
    return true;
}

int rpower(int x, int n) {
    if(n == 0) {
        return 1;
    }else {
        return x*rpower(x, n-1);
    }
}

int brpower(int x, int n) {
    int y;
    if(n == 0) {
        return 1;
    }else if (n % 2 == 1) {
        y = brpower(x, (n-1)/2);
        return x*y*y;
    }else {
        y = brpower(x, n/2);
        return y*y; 
    }
}

int main() {
    /*
    int n = 50;
    int arr[50] = {
        34, 12, 48, 3, 27, 19, 41, 8, 32, 15,
        22, 39, 5, 31, 46, 17, 2, 29, 38, 10,
        43, 24, 7, 33, 16, 49, 21, 36, 11, 45,
        1, 28, 42, 14, 25, 37, 9, 50, 20, 44,
        6, 30, 18, 40, 13, 35, 26, 4, 47, 23
    };

     // To measure the time taken, start the clock
    std::chrono::steady_clock::time_point begin =
    std::chrono::steady_clock::now();
    bool allUnique = Unique(arr, n);

    // Stop the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time taken to search = " << 
    std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << 
    " microseconds" << std::endl;

    if(allUnique) {
        std::cout << "All elements are unique\n";
    }else {
        std::cout << "There are copy elements\n";
    }
    */

    int x = 1; //make sure the number never exceeds the int limit
    int n = 100000;

    // To measure the time taken, start the clock
    std::chrono::steady_clock::time_point begin =
    std::chrono::steady_clock::now();
    int result = rpower(x , n) + brpower(x, n);

    // Stop the clock
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time taken to run = " << 
    std::chrono::duration_cast<std::chrono::microseconds> (end - begin).count() << 
    " microseconds" << std::endl;
    
    std::cout << result << std::endl;

    return 0;
}