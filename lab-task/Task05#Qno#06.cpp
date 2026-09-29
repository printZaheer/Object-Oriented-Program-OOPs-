#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int rollNumber;
    double gpa;
};
class StudentDirectory {
private:
    Student** students;
    int count;
    int capacity;
    void grow() {
        int newCapacity = (capacity == 0) ? 2 : capacity * 2;
        Student** newArray = new Student*[newCapacity];
        for (int i = 0; i < count; i++)
            newArray[i] = students[i];
        delete[] students;
        students = newArray;
        capacity = newCapacity;
    }
public:
    StudentDirectory() {
        students = NULL;
        count = 0;
        capacity = 0;
    }
    ~StudentDirectory() {
        for (int i = 0; i < count; i++)
            delete students[i];

        delete[] students;
    }
    Student* addStudent(string name, int rollNumber, double gpa) {
        if (count == capacity)
            grow();
        Student* newStudent = new Student;
        newStudent->name = name;
        newStudent->rollNumber = rollNumber;
        newStudent->gpa = gpa;
        students[count] = newStudent;
        count++;
        return newStudent;
    }
    Student* searchByRoll(int rollNumber) {
        for (int i = 0; i < count; i++) {
            if (students[i]->rollNumber == rollNumber)
                return students[i];
        }
        return NULL;
    }
    void printAll() {
        cout << "--- Student Directory ---" << endl;
        for (int i = 0; i < count; i++) {
            cout << "Roll " << students[i]->rollNumber << ": "
                 << students[i]->name << " | GPA: "
                 << students[i]->gpa << endl;
        }
    }
};
int main() {
    StudentDirectory dir;
    dir.addStudent("Ali", 101, 3.8);
    dir.addStudent("Ahmed", 102, 3.5);
    dir.addStudent("Hassan", 103, 3.9);
    dir.addStudent("Usman", 104, 3.2);
    dir.printAll();
    Student* found = dir.searchByRoll(103);
    if (found != NULL) {
        cout << "\nFound roll 103: " << found->name
             << " (GPA " << found->gpa << ")" << endl;
    } else {
        cout << "\nRoll 103 not found." << endl;
    }
    return 0;
}

