#include<iostream>
using namespace std;

class base_class1 {
protected:
    int x;
public:
    base_class1(int a) {  // Parameterized constructor
        x = a;
        cout << "base_class1 constructor called with x = " << x << endl;
    }
};

class base_class2 {
protected:
    int y;
public:
    base_class2() {  // Default constructor
        y = 0;
        cout << "base_class2 default constructor called, y = " << y << endl;
    }
};

class derived_class : public base_class1, public base_class2 {
public:
    derived_class(int a) : base_class1(a) {  // Only base_class1 constructor is called
        cout << "derived_class constructor called" << endl;
    }

    void display() {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
};

int main() {
    derived_class obj(10);  // Only base_class1 gets an argument
    obj.display();

    return 0;
}
