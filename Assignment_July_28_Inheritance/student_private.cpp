#include<iostream>
using namespace std;

class Student{
    protected:
        int roll_number;
    public:
        void get_number(int);
        void put_number();    
};

void Student :: get_number(int rno){
    roll_number = rno;
}
void Student :: put_number(){
    cout<<"Roll Number : "<<roll_number<<endl;
}

class Test: private Student
{    
    protected:
        float subject1;
        float subject2;
    public:
        void get_marks(float, float);
        void put_marks();

        // Added wrappers to access Student's methods
        void set_number(int r) {
            get_number(r);
        }
        void show_number() {
            put_number();
        }
};
void Test :: get_marks(float sub1, float sub2){
    subject1 = sub1;
    subject2 = sub2;
}
void Test :: put_marks(){
    cout<<"Marks of subject1: "<<subject1<<endl;
    cout<<"Marks of subject2: "<<subject2<<endl;
}

class Result: private Test{
        float total;
    public:
        void calculateResult()
        {
            total = subject1 + subject2;
            show_number();    // Replaced put_number with wrapper
            put_marks();
            cout<<"Result: "<<total<<endl;
        }

        // Wrapper to set everything
        void set_data(int r, float m1, float m2) {
            set_number(r);    // all wrapper instead of get_number
            get_marks(m1, m2);
        }
};

int main(){
    Result student1;

    student1.set_data(170672, 78.5, 89.75);
    student1.calculateResult();

    return 0;
}
