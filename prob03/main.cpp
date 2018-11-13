#include "player_log.hpp"
#include <iostream>
using namespace std;
int main() {
  // Create an instance of `player` using the default constructor
  player p1;
  // Create an instance of `player` using the non-default constructor
  player p2("Marie", "Mage", 30);
  // Create an instance of `player` using the non-default constructor
  player p3("Jack", "Assassin", 150);
  // Create an instance of `player` using the non-default constructor
  player p4("Bob", "Cleric", 100);
  // Create an instance of `player` using the default constructor
  player p5;
  // Create an instance of `player_log` using the non-default constructor
  player_log pl(4);
  // Call the `add_player` method to add `player` objects into the array
  pl.add_player(p1);
  pl.add_player(p2);
  pl.add_player(p3);
  pl.add_player(p4);
  pl.add_player(p5);
  cout << endl;
  // Call the `show_log` method
  pl.show_log();
  // Call the `show_fight_result` method
  pl.show_fight_result();
  return 0;
}
