#include <iomanip>
#include <iostream>
#include "buffet.hpp"
using namespace std;

int main() {
  string name;
  double balance;
  cout << "Hello welcome to the buffet, What is your name?: ";
  getline(cin, name);

  cout << "How much money is in your wallet?: ";
  cin >> balance;

  // Construct the wallet object.

  // Create a buffet with a lunch price of 13.00
  // and a dinner price of 18.50

  double dinner, lunch;
  // Use the buffet object to retrieve the price for dinner and store it in the
  // dinner variable and the price for lunch in the lunch variable

  int option;
  cout << "What are you buying?" <<  endl;
  cout << "1 - Dinner - " << fixed << setprecision(2) << dinner << "\n";
  cout << "2 - Lunch - " << fixed << setprecision(2) << lunch << "\n";
  cout << "Selection: ";
  cin >> option;
  if (option == 1) {
    // Charge the appropriate amount to the wallet
  } else if (option == 2) {
    // Charge the appropriate amount to the wallet
  } else {
    cout << "Invalid choice, try again\n";
  }

  string owner;
  double wallet_balance;
  // Use the wallet object to retrieve the name of the owner and store it in
  // the variable owner and the remaining balance to the variable wallet_balance

  cout << "Thank you for your purchase " << owner << ". You have "
       << wallet_balance << " left on your account\n";

  return 0;
}
