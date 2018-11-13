#include "committee.hpp"

committee::committee() {
  // set all pointers to nullptr

  cout << "Lets construct our commitee.\n";
  string name;
  int district;
  for (int i = 0; i < 10; i++){
    cout << "Who are we adding to the committee? ";
    getline(cin,name);
    cout << "What is their distric number? ";
    cin >> district;
    cin.ignore();
    // Assign the name and district number to this index of the array.

  }
}

//Make your find person function here

void committee::set_leadership() {
  string pres_name,vp_name,treasurer_name;
  cout << "Who do you want to make the president? ";
  getline(cin, pres_name);
  // use pres_name and another function to help you set your _president pointer

  cout << "Who do you want to make the vice-president? ";
  getline(cin, vp_name);
  // use vp_name and another function to help you set your _vice_president
  // pointer

  cout << "Who do you want to make the treasurer? ";
  getline(cin, treasurer_name);
  // use treasurer_name and another function to help you set your _treasurer
  // pointer
}
