#include "teacher.hpp"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string name;
  char test[100], answer;
  int num_questions = 0, num_students = 0;

  cout << "Please enter the teacher's name: ";
  getline(cin, name);
  cout << "Prepare to enter in master test (Q to quit):" << endl;
  do {
    cout << "Answer " << num_questions + 1 << ": ";
    cin >> answer;
    if (answer != 'Q') {
      test[num_questions++] = answer;
    }
  } while (answer != 'Q');
  // Create a teacher object and provide the necessary data required by its
  // constructor.
  teacher t1("John Smith", test, num_questions);

  // Create an array of 100 student pointer variables
  // Hint:
  // Step 1. Create an array of 100 integer variables? (Don't use new)
  // Step 2. If we want to create an array of student pointers, what should we
  //         use to replace int (from Step 1)?
  student *arr[100];
  char array[100];

  do {
    cout << "Please enter the student's name (Q to Quit): ";
    cin.ignore();
    getline(cin, name);
    if (name == "Q") {
      continue;
    }
    cout << "Prepare to enter student test:" << endl;
    for (int a = 0; a < num_questions; a++) {
      cout << "Answer " << a + 1 << ": ";
      cin >> answer;
      array[a] = answer;
    }
    // Dynamically create a student object using the user input
    // student *ptrstudent = new student(name, answer, num_questions);

    // Store the pointer to the student object into the array of student
    // pointers. Don't forget to increment num_students
    arr[num_students] = new student(name, array, num_questions);
    num_students++;

  } while (name != "Q");
  cout << endl
       << setw(16) << left << "Student"
       << "Grade" << endl;
  for (int a = 0; a < num_students; a++) {
    // Call the assign_grade member function of the teacher object and pass a
    // student pointer as its argument
    t1.assign_grade(arr[a]);

    string student_name;
    double student_grade;
    // Store the student object's name in student_name, and the student's grade
    // in student_grade. Take note that the array contains pointers to student
    // objects therefore you need to dereference it accordingly.
    student_name = arr[a]->name();
    student_grade = arr[a]->grade();

    cout << setw(16) << left << student_name << fixed << setprecision(2)
         << student_grade << endl;
  }

  return 0;
}
