#include <iostream>
#include "TestingResources.cpp"

int main() {
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
    }
    std::cout << endl;

    int num1, num2;
    char colon;

    std::cout << "Enter num1:num2" << endl;
    std::cin >> num1 >> colon >> num2;

    std::cout << "Hello World!" << endl << num1 << "_" << num2 << endl << endl;

    MyClass classy = MyClass(), classy4 = MyClass(4);

    std::cout << classy.getFoo() << " " << classy4.getFoo() << endl;

    return 0;
}