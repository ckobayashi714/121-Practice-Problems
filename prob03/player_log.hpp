#pragma once
#include <iostream>
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
  void display_player() {
    cout << "Player 1\n"
         << "Name: " << _name << "\n"
         << "Job: " << _job << "\n"
         << "Level: " << _level;
  }
  int fight(player person) {
    if (_level >= person.level()) {
      return 1;
    } else if (_level <= person.level()) {
      return 2;
    } else {
      return 3;
    }
  }
};
// Create the `player_log` class below...
class player_log {
private:
  player *_source_player;
  int _size;
  int _counter;

public:
  player_log() {
    _counter = 0;
    _size = 3;
    _source_player = new player *[_size];
  }
  player_log(int size) {
    _counter = 0;
    _size = size;
    _source_player = new player *[_size];
  }
  int size() { return _size; }
  int counter() { return _counter; }
  void add_player(player person) {
    for (int i = 0; i < _size; i++) {
      _source_player[i] = person;
    }
    cout << "List is full. Cannot register player.";
  }
  void show_log() {
    for (int i = 0; i < _size; i++) {
      _source_player[i]->display_player();
    }
  }
  void show_fight_result() {
    // for (int i = 0; i < _size; i++)
    // _source_player[i]
    cout << "fight goes here";
  }
  ~player_log() {
    for (int i = 0; i < _size; i++) {
      delete (*(_source_player + i));
      (*(_source_player + i)) = nullptr;
    }
    delete[] _source_player;
    _source_player = nullptr;
  }
};
