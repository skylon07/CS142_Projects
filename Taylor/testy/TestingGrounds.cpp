
/*
This is a basic C++ program, doesnt do much
However, its fun to see how basic operations are compiled into Assembly
In console: g++ file.cpp
-S flag: stops compiler at assembly
-c flag: stops compiler at object code
g++ CAN compile from .s/.o files into machine code (ie runnable program)
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <any>
#include "TestingResources.cpp"

// template <typename T> allows dynamic use of types,
// in this case to negate whatever the vector is holding
template <typename T>
// prints the contents of a vector
void PrintVect(std::vector<T> vect, std::string sepString=", ") {
    // print every element (except the last) inside the vector
    for (int i = 0; i < vect.size() - 1; ++i) {
        std::cout << vect.at(i) << sepString;
    }
    std::cout << vect.at(vect.size() - 1); // print last element
    std::cout << std::endl; // end the line
}

// same as class, except by default all members are public
struct Point2D {
    // initialization functions
    Point2D() : x(0), y(0) {}
    Point2D(int x, int y) : x(x), y(y) {}

    // member data
    int x;
    int y;

    // overload << operator (for cout)
        // the "&"s mean "pass by reference", instead of the default (no "&") "pass by value",
        // which is different from "*" which means "pointer type"
        // friend is used to access the private member/operator << of ostream
    friend std::ostream& operator<<(std::ostream& os, const Point2D& a) {
        os << "(" << a.x << ", " << a.y << ")";
        return os;
    }
};

int main() {
    std::cout << "Hello world!" << std::endl;

    // declare variables
    std::vector<Point2D> myVect(2);

    // setting myVect with initial values
    myVect.at(0) = Point2D(3, 4);
    myVect.at(1) = Point2D(5, 6);
    myVect.push_back(Point2D(16, 17));

    // printing the vector with a separator
    PrintVect(myVect, " : ");

    // switches without breaks fall through
    switch (3) {
        default:
        std::cout << 5;
        case 4:
        std::cout << 4;
        case 3:
        std::cout << 3;
        case 2:
        std::cout << 2;
        case 1:
        std::cout << 1;
        break; // not needed, since its last case, but useful to see how it normally is
    }
    std::cout << std::endl;

    // read from a different file entirely
    MyClass classy = MyClass(), classy4 = MyClass(4);

    std::cout << classy.getFoo() << " " << classy4.getFoo() << std::endl;

    // pause the program before exiting
    system("read");
    system("clear");
    return 0;
}
