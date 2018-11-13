#include "manager.hpp"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// A valid ssn has 9 digits
// This function will return false if the length of the string is not 9...
// ...or if there is a non-digit character in the string.
bool check_valid_ssn(string ssn) {
  int len = ssn.length();
  if (len != 9) {
    return false;
  }
  for (int i = 0; i < len; i++) {
    if (!isdigit(ssn[i])) {
      return false;
    }
  }
  return true;
}

// Given an array of valid projects...
// This function will return true if the string passed in matches...
// ...any of the 6 strings in the array.
bool check_valid_project(string project) {
  string proj_arr[6] = {"Research",           "Security",   "Web Application",
                        "Mobile Development", "Blockchain", "NULL"};
  for (int i = 0; i < 6; i++) {
    if (project == proj_arr[i]) {
      return true;
    }
  }
  return false;
}

// Set default values for each member variable in `employee`
employee::employee() {
  _name = "Bob";
  _ssn = "123456789";
  _project = "Research";
  _dept_num = 1;
  _hours_worked = 40.0;
  _salary = 55000.00;
}

// Set values for each member variable in `employee` to the values passed in
employee::employee(string name, string ssn, string project, int dept_num,
                   double hours_worked, double salary) {
  _name = name;
  _ssn = ssn;
  _project = project;
  _dept_num = dept_num;
  _hours_worked = hours_worked;
  _salary = salary;
}

// Write your code below...
