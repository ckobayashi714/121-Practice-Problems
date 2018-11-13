#include "manager.hpp"
#include <iostream>
using namespace std;
int main() {
  // Create an instance of employee using the non-default constructor
  // Use the variable name e1, give it a name of Bill, an ssn of 1, a project...
  // ...name of Nothing, a department number of 2, a number of hours worked...
  // ...of -40.0, and a salary of 10000.00

  // Create a pointer to an employee object and call it e2

  // Have `e2` point to the address of `e1`

  // Create an instance of manager using the non-default constructor
  // Use the variable name m1 and pass in the pointer `e2`

  // Using `m1`...
  // ... call the display_employee method

  cout << endl;
  // ... call the change_ssn method

  // ... call the change_project method

  // ... call the change_hours_worked method

  // ... call the change_salary method

  cout << endl;
  // ... call display_employee method

  cout << endl;
  // Create an instance of employee using the default constructor
  // Use the variable name e3

  // Have `e2` point to the address of `e3`

  // Create an instance of manager using the non-default constructor
  // Use the variable name m2 and pass in the pointer `e2`

  // Using `m1`...
  // ... call the display_employee method

  cout << endl;
  // ... call the change_ssn method

  // ... call the change_project method

  // ... call the change_hours_worked method

  // ... call the change_salary method

  cout << endl;
  // ... call display_employee method

  return 0;
}
