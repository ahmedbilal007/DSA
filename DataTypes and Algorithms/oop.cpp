// OOPS IN CPP

#include <iostream>
using namespace std;

class Person{
public:
    string name;
    int age;

    Person(string name, int age){
        this->name = name;
        this->age = age;
    }
};

class Student : public Person{      // Inheritance --> public level inheritance
public:
    int rollNo;
    Student(string name, int age, int rollNO) : Person(name, age){
        this->name = name;
        this->age = age;
        this->rollNo = rollNO;
    }

};

class Graduate : public Student{
public:     // Multilevel Inheritance
    string research;
};


class teachingAssistant : public Student, public Teacher{
    // Multiple Interitance
};



class Teacher{

    // By default, all the attributes are private in cpp
public:
    Teacher(){
        // Constructor
        cout << "constructor" << endl;
    }
    string name;
    string dept;
    string subject;
private:
    double salary;

    void changeDept(string newDept){
        dept = newDept;
    }
};


int main(){
    Teacher t1;             // Creating object
    t1.name = "Ahmed";
    t1.dept = "CS";
    t1.subject = "cpp";
    // t1.salary = 23000;



    return 0;
}