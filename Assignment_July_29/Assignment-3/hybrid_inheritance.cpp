#include<iostream>
using namespace std;

class Student {
protected:
    int roll_number;
public:
    void get_rollnumber(int rno) {
        roll_number = rno;
    }    
    void put_rollnumber() {
        cout << "Roll no: " << roll_number << endl;
    }
};

class Test : public Student {
protected:
    float subject1;
    float subject2;
public:
    void get_marks(float marks1, float marks2) {
        subject1 = marks1;
        subject2 = marks2;
    }    
    void put_marks() {
        cout << "Subject1 = " << subject1 << "    Subject2 = " << subject2 << endl;
    }
};

class Sports {
protected:
    float score;
public:
    void get_score(float scr) {
        score = scr;
    }        
    void put_score() {
        cout << "Score = " << score << endl;
    }
};

class Result : public Test, public Sports {
    float total;
public:
    void display() {
        total = subject1 + subject2;

        Student::put_rollnumber();  // using scope resolution
        Test::put_marks();
        Sports::put_score();

        cout << "Total score (excluding sports) = " << total << endl;
    }
};

int main() {
    Result student;

    student.Student::get_rollnumber(1111);     // explicitly specifying class
    student.Test::get_marks(48.9, 49.2);
    student.Sports::get_score(7.0);

    student.display();

    return 0;
}
