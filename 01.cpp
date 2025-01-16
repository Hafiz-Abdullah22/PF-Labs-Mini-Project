#include<iostream>
#include<vector>
#include<string>

using namespace std;

	// Structure to hold student information
struct Student{
    string name;
    int id;
    string department;
};

	// Class manage the student records
class StudentManagementSystem{
private:
    vector<Student> students; 

public:
    
	// Function to add a new student
    void addStudent(){
        Student newStudent;
        cout<<"Enter student name: ";
        cin>>newStudent.name;
        cout<<"Enter student ID: ";
        cin>>newStudent.id;
        cout<<"Enter student department: ";
        cin>>newStudent.department;
        students.push_back(newStudent); // Add new student
        cout<<"Student added successfully!"<<endl;
    }
	
	// Function to display all students
    void displayAllStudents(){
        if (students.empty()){
            cout<<"No students available."<<endl;
            return;
        }
        cout<<"List of Students:"<<endl;
        for (const auto& student : students){
            cout<<"Name: "<<student.name<<", ID: "<<student.id<<", Department: "<<student.department<<endl;
        }
    }
	
	// Function search for a student by ID
    void searchStudentByID(int id){
        for (const auto& student : students){
            if (student.id == id){
                cout<<"Student found: Name: "<< student.name<<", ID: "<< student.id<<", Department: "<<student.department<<endl;
                return;
            }
        }
        cout<<"Student with ID "<<id<< " not found."<<endl;
    }
	
	// Function to update student information
    void updateStudentByID(int id){
        for (auto& student : students){
            if (student.id == id){
                cout<<"Updating information for student ID "<<id<<endl;
                cout<<"Enter new name: ";
                cin>>student.name;
                cout<<"Enter new department: ";
                cin>>student.department;
                cout<<"Student information updated successfully!"<<endl;
                return;
            }
        }
        cout<<"Student with ID "<<id<<" not found."<<endl;
    }
	
	// Function to delete a student by ID
    void deleteStudentByID(int id){
        for (auto it = students.begin(); it != students.end(); ++it){
            if (it->id == id){
                students.erase(it); // Remove the student
                cout<<"Student with ID "<<id<<" deleted successfully!"<<endl;
                return;
            }
        }
        cout<<"Student with ID "<<id<<" not found."<<endl;
    }
};

    // Main function to run the Student Management System
int main() {
    StudentManagementSystem sms;
    int choice, id;

    do {
        cout<<"Student Management System Menu:"<<endl;
        cout<<"1. Add Student"<<endl;
        cout<<"2. Display All Students"<<endl;
        cout<<"3. Search Student by ID"<<endl;
        cout<<"4. Update Student Information"<<endl;
        cout<<"5. Delete Student"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice){
            case 1:
                sms.addStudent();
                break;
            case 2:
                sms.displayAllStudents();
                break;
            case 3:
                cout<<"Enter student ID to search: ";
                cin>>id;
                sms.searchStudentByID(id);
                break;
            case 4:
                cout<<"Enter student ID to update: ";
                cin>>id;
                sms.updateStudentByID(id);
                break;
            case 5:
                cout<<"Enter student ID to delete: ";
                cin>>id;
                sms.deleteStudentByID(id);
                break;
            case 6:
                cout<<"Thank You."<<endl;
                break;
            default:
                cout<<"Invalid choice."<<endl;
        }
    } while(choice != 6);
		
	return 0;
}