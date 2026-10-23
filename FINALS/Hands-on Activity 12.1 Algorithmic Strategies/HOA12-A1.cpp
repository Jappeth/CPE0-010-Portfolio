#include <iostream>
#include <algorithm>

int memo[100];
int getMinSteps(int n) {
        if (n == 1) {
            return 0;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        int r = 1 + getMinSteps(n - 1);
        if(n%2 == 0) {
            r = std::min(r, 1 + getMinSteps(n/2));
        }
        if(n%3 == 0) {
            r = std::min(r, 1 + getMinSteps(n/3));
        }
        memo[n] = r;
        return r;
}

int main() {
    for(int i = 0; i < 100; i++) {
        memo[i] = -1;
    }

    std::cout << "\nSteps to 1: " << getMinSteps(1);
    std::cout << "\nSteps to 4: " << getMinSteps(4);
    std::cout << "\nSteps to 7: " << getMinSteps(7);

    return 0;
}
