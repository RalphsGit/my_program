#include<iostream>
using namespace std;

class base1 {
public:
    base1() {
        cout << "base1 constructor called" << endl;
    }
};

class base2 {
public:
    base2() {
        cout << "base2 constructor called" << endl;
    }
};

// -------- Case 1 --------
class derived1 : public base1, public base2 {
public:
    derived1() {
        cout << "derived1 constructor called" << endl;
    }
};

// -------- Case 2 --------
class derived2 : public base1, virtual public base2 {
public:
    derived2() {
        cout << "derived2 constructor called" << endl;
    }
};

// -------- Case 3 --------
class derived3 : virtual public base1, public base2 {
public:
    derived3() {
        cout << "derived3 constructor called" << endl;
    }
};

// -------- Case 4 --------
class derived4 : virtual public base1, virtual public base2 {
public:
    derived4() {
        cout << "derived4 constructor called" << endl;
    }
};

int main() {
    // Block 1: Case 1
    {
        cout << "\n Case 1: public base1, public base2 \n";
        derived1 d1;
    }

    // Block 2: Case 2
    {
        cout << "\n Case 2: public base1, virtual public base2 \n";
        derived2 d2;
    }

    // Block 3: Case 3
    {
        cout << "\n Case 3: virtual public base1, public base2 \n";
        derived3 d3;
    }

    // Block 4: Case 4
    {
        cout << "\n Case 4: virtual public base1, virtual public base2 \n";
        derived4 d4;
    }

    return 0;
}


// Case 1: public base1, public base2 
// base1 constructor called
// base2 constructor called
// derived1 constructor called

//  Case 2: public base1, virtual public base2 
// base2 constructor called
// base1 constructor called
// derived2 constructor called

//  Case 3: virtual public base1, public base2 
// base1 constructor called
// base2 constructor called
// derived3 constructor called

//  Case 4: virtual public base1, virtual public base2 
// base1 constructor called
// base2 constructor called
// derived4 constructor called
