#include "athlete.hpp"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
  // Create an array of 100 athlete objects called athlete, and create an
  // athlete object called temp_athlete

  string sport, style, color;
  double size;
  int height, weight, num_athletes = 0;

  do {
    cout << "Please enter the athlete's sport (q to quit): ";
    getline(cin, sport);
    if (sport == "q") {
      continue;
    }
    cout << "Please enter the athlete's height (in): ";
    cin >> height;
    cout << "Please enter the athlete's weight (lbs): ";
    cin >> weight;
    cout << "Please enter the shoe style: ";
    cin.ignore();
    getline(cin, style);
    cout << "Please enter the shoe color: ";
    getline(cin, color);
    cout << "Please enter the shoe size (in): ";
    cin >> size;
    cin.ignore();
    // Dynamically allocate an athletic_shoe object using the user's input
    // and store its location into a pointer whose name is shoe

    // Use the rest of the user's input to update the values of the
    // temp_athlete object

    // Store the temp_athlete object inside the athletes array. Don't
    // forget to update your index so that the next object is store in the
    // correct location

  } while (sport != "q");

  cout << "Printing Athletes:" << endl;
  for (int a = 0; a < num_athletes; a++) {
    cout << "Athlete " << a + 1 << endl;
    // Display information about each athlete object in athletes using
    // its print member function
  }

  return 0;
}
