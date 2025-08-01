#include<iostream>
using namespace std;

class Employee {
    static int counter;
    int empid;
    char *name;
    double salary;

public:
    void getdata(char *ename, double sal) {
        empid = ++counter;
        name = ename;
        salary = sal;
    }

    void printEmployee(void) {
        cout << "\nEmpid : " << empid << endl;
        cout << "Name : " << name << endl;
        cout << "salary: " << salary << endl;
    }

    Employee compareSalary(Employee other) {
        if (this->salary > other.salary) {
            cout << name << " has a higher salary than " << other.name << "." << endl;
            return *this;
        }
            
        else if (this->salary < other.salary) {
            cout << other.name << " has a higher salary than " << name << "." << endl;
            return other;
        }
            
        else {
            cout << name << " and " << other.name << " have the same salary." << endl;
            return *this;
        }
            
    }

    static void generateEmpid() {
        counter = 2000;
    }
};

int Employee::counter;

int main() {
    Employee e1, e2, e3;
    Employee::generateEmpid();

    char* name1 = new char[100];
    char* name2 = new char[100];
    char* name3 = new char[100];
    double sal;

    cout << "Enter name for employee 1: ";
    cin >> name1;
    cout << "Enter salary for employee 1: ";
    cin >> sal;
    e1.getdata(name1, sal);

    cout << "Enter name for employee 2: ";
    cin >> name2;
    cout << "Enter salary for employee 2: ";
    cin >> sal;
    e2.getdata(name2, sal);

    cout << "Enter name for employee 3: ";
    cin >> name3;
    cout << "Enter salary for employee 3: ";
    cin >> sal;
    e3.getdata(name3, sal);

    e1.printEmployee();
    e2.printEmployee();
    e3.printEmployee();

    cout << "\nSalary comparison:\n";
    e1.compareSalary(e2);
    e2.compareSalary(e3);
    e1.compareSalary(e3);

    delete[] name1;
    delete[] name2;
    delete[] name3;

    return 0;
}
