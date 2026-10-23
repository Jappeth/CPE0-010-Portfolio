#include <iostream>
#include <string.h>

class Student{
    private:
        std::string studentName;
        int studentAge;
    public:
        //constructor
        Student(std::string newName = "Jane Doe", int newAge = 18) {
            studentName = std::move(newName);
            studentAge = newAge;
            std::cout << "Constructor called!\n";
        };

        //destructor
        ~Student() {
            std::cout << "Destructor called!\n";
        }

        //copy constructor
        Student(const Student &copyStudent) {
            std::cout << "Copy constructor called!\n";
            studentName = copyStudent.studentName;
            studentAge = copyStudent.studentAge;
        }

        //copy assignment operator
        Student& operator=(const Student &caoStudent) {
            std::cout << "Copy assignment operator called!\n";
            if(this != &caoStudent) {
                studentName = caoStudent.studentName;
                studentAge = caoStudent.studentAge;
            }
            return *this;
        }

        //display attributes
        void printDetails() {
            std::cout << this->studentName << " " << this->studentAge << '\n';
        }

};

int main() {
    /*
    Student student1("Ezio" , 60);
    Student student2(student1);
    Student student3;
    student3 = student2;
    */
    
    const size_t j = 5;

    Student studentList[j] = {};
    std::string nameList[j] = {"Connor", "Edward", "Arno", "Jacob", "Bayek"};
    int ageList[j] = {20, 33, 25, 28, 35};

    for(int i = 0; i < j; i++) { //Loop A
        Student *ptr = new Student(nameList[i], ageList[i]);
        studentList[i] = *ptr;
    }

    for(int i = 0; i < j; i++) {//Loop B
        studentList[i].printDetails();
    }
    
    return 0;
}