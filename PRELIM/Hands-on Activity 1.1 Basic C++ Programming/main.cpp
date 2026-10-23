#include <iostream>
#include <type_traits>
#include <cmath>


int sumOfTwo(int x, int y);
bool isGreater(float a, float b);
template <typename T1, typename T2>
bool boolOperations(T1 a, T2 b);

class Triangle{
    private:
        double totalAngle, angleA, angleB, angleC;
    public:
        Triangle(double A, double B, double C);
        void setAngles(double A, double B, double C);
        const bool validateTriangle();
        double areaOfTriangle(double sideA);
        double perimeter(double sideA);
        const bool isObtuse();
};

int main() {
    //sum function call
    int x = 3, y = 4;
    std::cout << x << " + " << y << " = " << sumOfTwo(x,y) << '\n';

    //comparing numbers function call
    int A = 67;
    int B = 69;
    if(isGreater(A, B)) {
        std::cout << A << " is greater than " << B << '\n';
    }
    else {
        std::cout << A << " is not greater than " << B << '\n';
    }

    //bool operation function call
    auto argA = true;
    auto argB = false;
    if(boolOperations(argA, argB)) {
        std::cout << "SUCCESS!\n";
    }else {
        std::cout << "FAIL!\n";
    }

    //ILO 2 Function call
    int angleA, angleB, angleC;
    std::cout << "Enter the three angles of a triangle: ";
    std::cin >> angleA >> angleB >> angleC;
    Triangle tri1(angleA, angleB, angleC);
    if(tri1.validateTriangle()) {
        std::cout << "The triangle is valid.\n";
    }else {
        std::cout << "The triangle is not valid.\n";
    }

    double sideA;
    std::cout << "Enter the length of side opposite of angle A: ";
    std::cin >> sideA;
    std::cout << "The area of the triangle is: " << tri1.areaOfTriangle(sideA) << " square units.\n";
    std::cout << "The perimeter of the triangle is: " << tri1.perimeter(sideA) << " units.\n";
    std::cout << "The triangle is " << (tri1.isObtuse() ? "obtuse." : "not obtuse.") << '\n';

    return 0;
}

int sumOfTwo(int x, int y) {
    int sum = x + y;
    return sum;
}


bool isGreater(float a, float b) {
    if(a > b) {return true;
    }else {return false;}
}

template <typename T1, typename T2>
bool boolOperations(T1 a, T2 b) {
    if(std::is_same<T1, bool>::value && std::is_same<T2, bool>::value) {
        if(a && b) {std::cout << "AND = True\n"; //AND operation
        }else {std::cout << "AND = False\n";}


        if(a || b) {std::cout << "OR = True\n"; //OR operation
        }else {std::cout << "OR = False\n";}


        if(!(a && b)) {std::cout << "NAND = True\n"; //NAND operation
        }else {std::cout << "NAND = False\n";}


        if(!(a || b)) {std::cout << "NOR = True\n"; //NOR operation
        }else {std::cout << "NOR = False\n";}


        if(a != b) {std::cout << "XOR = True\n"; //XOR operation
        }else {std::cout << "XOR = False\n";}


        return true;
    } else {
        return false;
    }
}


Triangle::Triangle(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
};


void Triangle::setAngles(double A, double B, double C) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A+B+C;
};


const bool Triangle::validateTriangle(){
    return (totalAngle == 180);
};

double Triangle::areaOfTriangle(double sideA) {
    if (!validateTriangle()) {
        std::cout << "The triangle is not valid. Cannot calculate area.\n";
        return -1;
    }else {
        double area = (pow(sideA, 2) * sin(angleB* M_PI / 180) * sin(angleC * M_PI / 180)) / (2 * sin(angleA * M_PI / 180));
        return area;
    }
};

double Triangle::perimeter(double sideA) {
    if (!validateTriangle()) {
        std::cout << "The triangle is not valid. Cannot calculate perimeter.\n";
        return -1;
    }else {
        double sideB = (sideA * sin(angleB * M_PI / 180)) / sin(angleA * M_PI / 180);
        double sideC = (sideA * sin(angleC * M_PI / 180)) / sin(angleA * M_PI / 180);
        double perimeter = sideA + sideB + sideC;
        return perimeter;
    }
};

const bool Triangle::isObtuse() {
    if (!validateTriangle()) {
        std::cout << "The triangle is not valid. Cannot determine if it is obtuse.\n";
        return false;
    }else {
        return (angleA > 90 || angleB > 90 || angleC > 90);
    }
};

