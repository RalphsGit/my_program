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

class Test : virtual public Student {
protected:
    float subject1;
    float subject2;
public:
    void get_marks(float m1, float m2) {
        subject1 = m1;
        subject2 = m2;
    }
    void put_marks() {
        cout << "Subject1 = " << subject1 << "    Subject2 = " << subject2 << endl;
    }
};

class Sports : virtual public Student {
protected:
    float score;
public:
    void get_score(float s) {
        score = s;
    }
    void put_score() {
        cout << "Sports Score = " << score << endl;
    }
};

class Result : public Test, public Sports {
    float total;
public:
    void display() {
        total = subject1 + subject2 + score;

        Student::put_rollnumber();  // Avoid ambiguity due to virtual inheritance
        Test::put_marks();
        Sports::put_score();

        cout << "Total Score = " << total << endl;
    }
};

int main() {
    Result student;

    student.get_rollnumber(101);      // Student (shared via virtual inheritance)
    student.get_marks(45.0, 49.5);    // Test
    student.get_score(9.5);           // Sports

    student.display();                // Result

    return 0;
}
