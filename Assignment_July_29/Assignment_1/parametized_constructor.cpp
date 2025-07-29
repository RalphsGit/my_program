#include<iostream>
using namespace std;

class base_class1 {
protected:
    int x;
public:
    base_class1(int a) {      // Added Parameterized constructor
        x = a;
    }
    void display() {
        cout << "x = " << x << endl;
    }
};

class base_class2 {
protected:
    int y;
public:
    base_class2(int b) {      // Added Parameterized constructor
        y = b;
    }
    void display() {
        cout << "y = " << y << endl;
    }
};

class derived_class : public base_class1, public base_class2 {
public:
    derived_class(int a, int b) : base_class1(a), base_class2(b) {}  // Constructor with initializer list
    void display() {
        cout << "X * Y = " << (x * y) << endl;
    }
};

int main() {
    derived_class der(15, 7);  // Call to new parameterized constructor
    der.base_class1::display();
    der.base_class2::display();
    der.display();

    return 0;
}
