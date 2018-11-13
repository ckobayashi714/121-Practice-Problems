#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <string>
#include <fstream>
#include <list>
#include "gtest_ext.h"
#include "../committee.hpp"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;

using namespace std;

TEST(committee, PublicMethodsPresent) {
  std::string input;
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    input += generate_string(10) + "\n" + std::to_string(rand()%100) + "\n";
  }
  input += generate_string(10) + "\n" + generate_string(10) + "\n"
          + generate_string(10) + "\n";

  SIMULATE_CIN(input, {
    committee c;
    c.set_president(generate_string(10));
    c.set_vice_president(generate_string(10));
    c.set_treasurer(generate_string(10));
    c.set_leadership();
    c.get_member_name(0);
    c.president_name();
    c.vice_president_name();
    c.treasurer_name();
  });
}

TEST(committee, set_and_get_leaders) {
  for(int j = 0; j < 10; j++){
    std::string unittest_names[10], input;
    for (int i = 0; i < 10; i++) {
      unittest_names[i] = generate_string(10);
      input += unittest_names[i] + "\n" + std::to_string(rand()%100) + "\n";
    }
    SIMULATE_CIN(input, {
      committee c;
      int index = rand() % 10;
      c.set_president(unittest_names[index]);
      ASSERT_EQ(c.president_name(), unittest_names[index]);
      index = rand() % 10;
      c.set_vice_president(unittest_names[index]);
      ASSERT_EQ(c.vice_president_name(), unittest_names[index]);
      index = rand() % 10;
      c.set_treasurer(unittest_names[index]);
      ASSERT_EQ(c.treasurer_name(), unittest_names[index]);
    });

  }
}

TEST(committee, test_constructor)
{
  stringstream test_output;
  ostringstream test_input;
  test_output << "Lets construct our commitee.\n";
  string name;
  int district;

  string random_name_from_committee;
  for(int i = 0; i < 10;i++){
    test_output << "Who are we adding to the committee? ";
    string name = generate_string(15);
    test_input<<name<<endl;

    test_output << "What is their district number? ";
    test_input << rand()%100<<endl;
    if( i ==4){
      random_name_from_committee = name;
    }
  }
  ASSERT_SIO_EQ(test_input.str(),test_output.str(),{
    committee test;
    ASSERT_EQ(test.get_member_name(4), random_name_from_committee);
  })
}

TEST(committee, test_leadership_and_get_president_name)
{
  ostringstream test_output;
  ostringstream test_input;
  test_output << "Lets construct our commitee.\n";
  string name;
  int district;
  string unittest_president, unittest_vp, unittest_treasurer;
  for(int i =0; i < 10;i++){
    test_output << "Who are we adding to the committee? ";
    string name = generate_string(15);
    test_input<<name<<endl;

    test_output << "What is their district number? ";
    test_input << rand()%100<<endl;

    if( i ==3){
      unittest_president = name;
    }
    else if(i ==5){
      unittest_vp = name;
    }
    else if(i==7){
      unittest_treasurer = name;
    }
  }

  test_output << "Who do you want to make the president? ";
  test_input << unittest_president <<endl;
  test_output << "Who do you want to make the vice-president? ";
  test_input << unittest_vp <<endl;
  test_output << "Who do you want to make the treasurer? ";
  test_input << unittest_treasurer <<endl;

  ASSERT_SIO_EQ(test_input.str(),test_output.str(),{
      committee test;
      test.set_leadership();
      ASSERT_EQ(test.president_name(), unittest_president);
      ASSERT_EQ(test.vice_president_name(), unittest_vp);
      ASSERT_EQ(test.treasurer_name(), unittest_treasurer);
  });
}

TEST(committee, output_format) {
  ostringstream test_output;
  ostringstream test_input;
  test_output << "Lets construct our commitee.\n";
  string name;
  int district;
  string unittest_president, unittest_vp, unittest_treasurer;
  for(int i =0; i < 10;i++){
    test_output << "Who are we adding to the committee? ";
    string name = generate_string(15);
    test_input<<name<<endl;

    test_output << "What is their distric number? ";
    test_input << rand()%100<<endl;

    if( i ==3){
      unittest_president = name;
    }
    else if(i ==5){
      unittest_vp = name;
    }
    else if(i==7){
      unittest_treasurer = name;
    }
  }

  test_output << "Who do you want to make the president? ";
  test_input << unittest_president <<endl;
  test_output << "Who do you want to make the vice-president? ";
  test_input << unittest_vp <<endl;
  test_output << "Who do you want to make the treasurer? ";
  test_input << unittest_treasurer <<endl;

  test_output << "The President is: " << unittest_president<<endl;
  test_output << "The Vice President is: " <<unittest_vp<<endl;
  test_output << "The Treasurer is: "<< unittest_treasurer<<endl;
  std::string your_output = test_input.str();
  std::string unittest_output = test_output.str();
  ASSERT_EXECIO_EQ("main", your_output, unittest_output);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
