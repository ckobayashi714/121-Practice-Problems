
#include <string>
#include <iostream>
using namespace std;

class member {
private:
  string _name;
  int _district_number;

public:
  member() {
    _name = "";
    _district_number = -1;
  }
  member(string name, int district_number) {
    _name = name;
    _district_number = district_number;
  }
  string name() { return _name; }
  int district_number() { return _district_number; }

  void set_name(string name) { _name = name; }
  void set_district_number(int district_number) {
    _district_number = district_number;
  }
};

class committee {
private:
  // Data members here

  //dont forget to make int find_person(string name) a private helper function.

public:
  committee();
  // add all other member functions below
};
