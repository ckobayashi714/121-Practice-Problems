#include "doctors_schedule.hpp"
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
  int num;
  cout << "How many appointments does the doctor have?: ";
  cin >> num;
  cin.ignore();

  // contruct the doctors_schedule object here using the input we just got
  // store it in a variable called schedule

  // The following loop should:
  // 1st, output the doctor's current appointment
  // 2nd, waits until the user hits enter to move on to the next appointment
  while ( /* check if appointments are not yet finished */) {
    // output the current_appointment using schedule

    // This block pauses the loop until the user hits enter.
    cout << "Press enter to move on to the next appointment";
    cin.get();

    // use schedule to move to the next appointment
  }
  cout << "Good work today, doctor!\n";

  return 0;
}
