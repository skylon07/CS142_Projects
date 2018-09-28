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

int main() {
    std::cout << "Hello world!" << std::endl;

    system("read");
    system("clear");
    return 0;
}