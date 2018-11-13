#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <iomanip>
#include "gtest_ext.h"
#include "../player_log.hpp"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;

TEST(PlayerLog, OutputFormat) {
  std::string unittest_output =
  "Billy Registered\n"
  "Marie Registered\n"
  "Jack Registered\n"
  "Bob Registered\n"
  "List is full. Cannot register player.\n\n"

  "Player 1\n"
  "Name: Billy\n"
  "Job: Warrior\n"
  "Level: 100\n\n"

  "Player 2\n"
  "Name: Marie\n"
  "Job: Mage\n"
  "Level: 30\n\n"

  "Player 3\n"
  "Name: Jack\n"
  "Job: Assassin\n"
  "Level: 150\n\n"

  "Player 4\n"
  "Name: Bob\n"
  "Job: Cleric\n"
  "Level: 100\n\n"

  "Billy defeated Marie\n"
  "Billy lost to Jack\n"
  "Billy and Bob were evenly matched\n"
  "Marie lost to Jack\n"
  "Marie lost to Bob\n"
  "Jack defeated Bob\n";

  ASSERT_EXECIO_EQ("main", "", unittest_output);
}

TEST(PlayerLog, PlayerPublicMethodsPresent) {
  player p1, p2("Bob", "None", 20);
  std::string unittest_output =
  "Name: Billy\n"
  "Job: Warrior\n"
  "Level: 100\n"
  "Name: Bob\n"
  "Job: None\n"
  "Level: 20\n";
  ASSERT_SIO_EQ("", unittest_output, {
    p1.display_player();
    p2.display_player();
  });
  p1.fight(p2);
}

TEST(PlayerLog, Accessors) {
  player_log your_player_log1, your_player_log2(5);
  int unittest_size = 3;
  ASSERT_EQ(your_player_log1.size(), unittest_size);
  unittest_size = 5;
  ASSERT_EQ(your_player_log2.size(), unittest_size);
  int unittest_counter = 0;
  ASSERT_EQ(your_player_log1.counter(), unittest_counter);
}

TEST(PlayerLog, DefaultConstructor) {
  player_log your_player_log;
  int unittest_size = 3;
  int unittest_counter = 0;
  ASSERT_EQ(your_player_log.size(), unittest_size);
  ASSERT_EQ(your_player_log.counter(), unittest_counter);
}

TEST(PlayerLog, NonDefaultConstructor) {
  player_log your_player_log(10);
  int unittest_size = 10;
  int unittest_counter = 0;
  ASSERT_EQ(your_player_log.size(), unittest_size);
  ASSERT_EQ(your_player_log.counter(), unittest_counter);
}

TEST(PlayerLog, AddPlayer) {
  player_log your_player_log(2);
  player p1;
  player p2("Hi", "Hi", 1);
  player p3("Bye", "Bye", 2);
  std::string unittest_output =
  "Billy Registered\n"
  "Hi Registered\n"
  "List is full. Cannot register player.\n";
  ASSERT_SIO_EQ("", unittest_output, {
    your_player_log.add_player(p1);
    your_player_log.add_player(p2);
    your_player_log.add_player(p3);
  });
}

TEST(PlayerLog, ShowLog) {
  player_log your_player_log;
  player p1;
  std::string unittest_output =
  "Billy Registered\n";
  ASSERT_SIO_EQ("", unittest_output, {
    your_player_log.add_player(p1);
  });
  unittest_output =
  "Player 1\n"
  "Name: Billy\n"
  "Job: Warrior\n"
  "Level: 100\n\n";
  ASSERT_SIO_EQ("", unittest_output, {
    your_player_log.show_log();
  });
}

TEST(PlayerLog, ShowFightResult) {
  std::stringstream ss;
  player p1("Hi", "Hi", 2);
  player p2("Bye", "Bye", 3);
  player p3("Hello", "Hello", 2);
  player p4("World", "World", 1);
  player_log your_player_log(4);
  auto old_cout = std::cout.rdbuf(ss.rdbuf());
  your_player_log.add_player(p1);
  your_player_log.add_player(p2);
  your_player_log.add_player(p3);
  your_player_log.add_player(p4);
  std::cout.rdbuf(old_cout);
  std::string unittest_output =
  "Hi lost to Bye\n"
  "Hi and Hello were evenly matched\n"
  "Hi defeated World\n"
  "Bye defeated Hello\n"
  "Bye defeated World\n"
  "Hello defeated World\n";
  ASSERT_SIO_EQ("", unittest_output, {
    your_player_log.show_fight_result();
  });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
