#pragma once
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Create class called `topping`
class topping {
private:
  // Create private member variables
  string _name;
  double _cost;

public:
  // Create default constructor
  topping() {
    _name = "Boba";
    _cost = 0.50;
  }
  // Create non-default constructor
  topping(string name, double cost) {
    _name = name;
    _cost = cost;
  }
  // Create accessors and mutators
  string name() { return _name; }
  void set_name(string name) { _name = name; }
  double cost() { return _cost; }
  void set_cost(double cost) { _cost = cost; }
  // Create member function to print out name and cost of the topping
  void print_topping() {
    cout << "Topping: " << _name << endl;
    cout << "Cost: $" << fixed << setprecision(2) << _cost << endl;
  }
};

// Create the milktea class below...
