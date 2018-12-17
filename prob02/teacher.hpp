#pragma once
#include <iostream>
using namespace std;

class student {
private:
  string _name;
  char *_test;
  int _num_questions;
  double _grade;

public:
  student() {
    _name = "Stu Dent";
    _num_questions = 0;
    _grade = 0;
    _test = nullptr;
  }
  student(string name, char test[], int num_questions) {
    _grade = 0;
    _name = name;
    _num_questions = num_questions;
    _test = new char[_num_questions];
    for (int i = 0; i < _num_questions; i++) {
      (*(_test + i)) = (*(test + i));
    }
  }
  ~student() {
    delete[] _test;
    _test = nullptr;
  }
  string name() { return _name; }
  int num_questions() { return _num_questions; }
  char *test() { return _test; }
  double grade() { return _grade; }
  void set_name(string name) { _name = name; }
  void set_num_questions(int num_questions) { _num_questions = num_questions; }
  void set_grade(double grade) { _grade = grade; }
  void add_test(char array[], int num) {
    for (int i = 0; i < num; i++) {
      if ((*(array + i)) == 'A' || (*(array + i)) == 'B' ||
          (*(array + i)) == 'C' || (*(array + i)) == 'D' ||
          (*(array + i)) == 'E') {
        continue;
      }
      cout << "Not Valid";
    }
    _test = array;
    _num_questions = num;
  }
};

class teacher {
private:
  string _name;
  char *_master_test;
  int _num_questions;

public:
  teacher() {
    _name = "Tea Cher";
    _num_questions = 0;
  }
  teacher(string name, char master[], int num_questions) {
    _name = name;
    _num_questions = num_questions;
    _master_test = new char[_num_questions];
    for (int i = 0; i < _num_questions; i++) {
      (*(_master_test + i)) = (*(master + i));
    }
  }
  ~teacher() {
    delete[] _master_test;
    _master_test = nullptr;
  }
  string name() { return _name; }
  int num_questions() { return _num_questions; }
  void set_name(string name) { _name = name; }
  void set_num_questions(int num_questions) { _num_questions = num_questions; }
  void add_master_test(char master[], int num) {
    if (_master_test != nullptr) {
      delete[] _master_test;
      _master_test = nullptr;
    }
    _master_test = new char[num];
    for (int i = 0; i < num; i++) {
      (*(_master_test + i)) = (*(master + i));
    }
    _num_questions = num;
  }
  void assign_grade(student *ptrStudent) {
    if (ptrStudent->num_questions() == _num_questions) {
      int temp = 0;
      for (int i = 0; i < _num_questions; i++) {
        // cout << "student " << (*(ptrStudent->test() + i)) << "\n";
        // cout << "teacher " << (*(_master_test + i)) << "\n";
        if ((*(ptrStudent->test() + i)) == (*(_master_test + i))) {
          temp++;
        } else {
          ptrStudent->set_grade(0);
        }
      }
      // cout << temp << " num questions " << _num_questions<< "\n";
      ptrStudent->set_grade(
          (static_cast<double>(temp) / static_cast<double>(_num_questions)) *
          100);
    }
  }
};
