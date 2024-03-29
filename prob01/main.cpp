#include "milktea.hpp"
#include <iostream>
#include <string>
using namespace std;
int main() {
  // Create an instance of the topping object using its non-default constructor
  // Use the variable name t1, give it a name of Pudding and a cost of 1.00
  topping t1("Pudding", 1.00);
  // Create a pointer to a topping object and called it t2.
  topping *t2;

  // Have `t2` point to the address of `t1`
  t2 = &t1;

  // Print name and cost of `t1`
  t1.print_topping();

  // Print the name and cost if `t2` (should be the same as `t1`)
  t2->print_topping();

  // Change the name of t1 to Aloe and its cost to 1.50
  t1.set_name("Aloe");
  t1.set_cost(1.50);

  // Create an instance of the milktea object using its non-default constructor
  // Set its name to Honey and its topping to t2
  milktea mt("Honey", t2);

  // Print the flavor, name, and cost of the milktea object
  mt.print_milktea();

  return 0;
}
