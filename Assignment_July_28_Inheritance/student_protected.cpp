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

class Test: protected Student
{    
    protected:
        float subject1;
        float subject2;
    public:
        void get_marks(float, float);
        void put_marks();    
};
void Test :: get_marks(float sub1, float sub2){
    subject1 = sub1;
    subject2 = sub2;
}
void Test :: put_marks(){
    cout<<"Marks of subject1: "<<subject1<<endl;
    cout<<"Marks of subject2: "<<subject2<<endl;
}

class Result: protected Test{
        float total;
    public:
        void calculateResult()
        {
            total = subject1 + subject2;
            put_number();
            put_marks();
            cout<<"Result: "<<total<<endl;
        }

        // public methods to access base class functionality externally
        void set_data(int r, float m1, float m2) {
            get_number(r);
            get_marks(m1, m2);
        }
};

int main(){
    Result student1;

    student1.set_data(170672, 78.5, 89.75);
    student1.calculateResult();

    return 0;
}
