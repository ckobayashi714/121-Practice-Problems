#pragma once
#include <string>
using namespace std;

// Create a class called `player`
class player {
private:
  // Create private member variables
  string _name;
  string _job;
  int _level;

public:
  // Create a default constructor
  player() {
    _name = "Billy";
    _job = "Warrior";
    _level = 100;
  }
  // Create a non-default constructor
  player(string name, string job, int level) {
    _name = name;
    _job = job;
    _level = level;
  }
  // Create accessors and mutators
  string name() { return _name; }
  void set_name(string name) { _name = name; }
  string job() { return _job; }
  void set_job(string job) { _job = job; }
  int level() { return _level; }
  void set_level(int level) { _level = level; }
  // Create the member functions below...

};

// Create the `player_log` class below...
