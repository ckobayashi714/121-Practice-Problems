#include <iostream>
#include <string>
using namespace std;

class appointment {
private:
  string _name;
  string _location;
  string _time;

public:
  appointment() : appointment("", "", "12:00pm") {}
  appointment(string name, string location, string time) {
    _name = name;
    _location = location;
    _time = time;
  }
  string name() { return _name; }
  string location() { return _location; }
  string time() { return _time; }
  void set_name(string name) { _name = name; }
  void set_location(string location) { _location = location; }
  void set_time(string time_input) { _time = time_input; }
  string to_string() {
    string output = "You have an appointment with " + _name + " at " + _time +
                    ", " + _location + "\n";
    return output;
  }
};

class doctors_schedule {
private:
  // data members here
public:
  doctors_schedule(int num_of_appointments);
  // member functions here
};
