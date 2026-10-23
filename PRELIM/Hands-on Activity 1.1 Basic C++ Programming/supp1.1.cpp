#include <iostream>
#include <cmath>

int swapNumbers(int &a, int &b);
double kelvinToFahrenheit(double kelvin);
double distance(double x1, double y1, double x2, double y2);

int main() {
    // Swap numbers function call
    int num1, num2;
    std::cout << "Enter two numbers:\n";
    std::cin >> num1 >> num2;
    swapNumbers(num1, num2);
    std::cout << "After swapping:\n" << num1 << "\n" << num2 << '\n';

    // Kelvin to Fahrenheit function call
    double kelvin;
    std::cout << "Enter temperature in Kelvin: ";  
    std::cin >> kelvin;
    std::cout << kelvin << " Kelvin is equal to " << kelvinToFahrenheit(kelvin) << " Fahrenheit.\n";

    // Distance function call
    double x1, y1, x2, y2;
    std::cout << "Enter coordinates of first point (x1 y1):\n";
    std::cin >> x1 >> y1;
    std::cout << "Enter coordinates of second point (x2 y2):\n";
    std::cin >> x2 >> y2;
    std::cout << "The distance between the two points is: " << distance(x1, y1, x2, y2) << "units. \n";

    return 0;
}

int swapNumbers(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    return 0;
}

double kelvinToFahrenheit(double kelvin) {
    double celsius = kelvin - 273.15;
    double fahrenheit = (celsius * 9/5) + 32;
    return fahrenheit;
}

double distance(double x1, double y1, double x2, double y2) {
    double dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return dist;
}