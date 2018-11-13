#pragma once
#include <string>
using namespace std;

// Prototype functions
bool check_valid_ssn(string);
bool check_valid_project(string);

// Create a class called `employee`
class employee {
private:
  // Create private member variables
  string _name;
  string _ssn;
  string _project;
  int _dept_num;
  double _hours_worked;
  double _salary;

public:
  // Create default constructor
  employee();
  // Create non-default constructor
  employee(string, string, string, int, double, double);
  // Create accessors and mutators
  string name() { return _name; }
  void set_name(string name) { _name = name; }
  string ssn() { return _ssn; }
  void set_ssn(string ssn) { _ssn = ssn; }
  string project() { return _project; }
  void set_project(string project) { _project = project; }
  int dept_num() { return _dept_num; }
  void set_dept_num(int dept_num) { _dept_num = dept_num; }
  double hours_worked() { return _hours_worked; }
  void set_hours_worked(double hours_worked) { _hours_worked = hours_worked; }
  double salary() { return _salary; }
  void set_salary(double salary) { _salary = salary; }
};

// Create your manager class below...
