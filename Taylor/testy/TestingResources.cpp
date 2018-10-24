#pragma once

class MyClass {
    private:
    int foo;
    
    public:
    MyClass();
    MyClass(int);
    int getFoo();
    void setFoo(int);
};

MyClass::MyClass() {
    foo = 0;
}

MyClass::MyClass(int n) {
    foo = n;
}

int MyClass::getFoo() {
    return foo;
}

void MyClass::setFoo(int n) {
    foo = n;
}
