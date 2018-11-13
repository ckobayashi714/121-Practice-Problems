#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <string>
#include <fstream>
#include <list>
#include "gtest_ext.h"
#include "../buffet.hpp"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;

using namespace std;


TEST(buffet, default_constructor) {
  buffet test;
  ASSERT_EQ(test.dinner_price(),18.00) <<"Either your constructor did not set the dinner price to 18.00, or your accessor dinner_price() was not working correctly";
  ASSERT_EQ(test.lunch_price(), 12.00) << "Either your constructor did not set the lunch price to 12.00, or your accessorr lunch_price was not working correctly";
}

TEST(buffet, non_default_constructor_test)
{
  buffet test(20.00, 14.00);
  ASSERT_EQ(test.dinner_price(),20.00) <<"Either your constructor did not set the dinner price to 18.00, or your accessor dinner_price() was not working correctly";
  ASSERT_EQ(test.lunch_price(), 14.00) << "Either your constructor did not set the lunch price to 12.00, or your accessorr lunch_price was not working correctly";
}


TEST(buffet, charge_wallet)
{
  srand(time(NULL));
  std::string name = generate_string(20);
  double walletInput =  static_cast<double>(rand()%100+18) + (static_cast<double>(rand()%100)/100.0);
  wallet test_wallet(name, walletInput);
  double balance = test_wallet.balance();
  buffet test_resturaunt;

  test_resturaunt.charge_lunch(&test_wallet);
  ASSERT_EQ(test_wallet.balance(),balance - 12.00) << "The charge was not correctly calculated for charge_lunch\n";

  balance = test_wallet.balance();
  test_resturaunt.charge_dinner(&test_wallet);
  ASSERT_EQ(test_wallet.balance(),balance - 18.00) << "The charge was not correctly calculated for charge_dinner\n";

}

TEST(buffet, output_format)
{
  std::ostringstream test_output;
  std::ostringstream test_input;
  std::string name = generate_string(15);
  double walletInput =  static_cast<double>(rand()%100+18) + (static_cast<double>(rand()%100)/100.0);
  test_output << "Hello welcome to the buffet, What is your name?: ";
  test_input << name<<endl;

  test_output << "How much money is in your wallet?: ";
  test_input << walletInput <<endl;

  test_output << "What are you buying?" <<endl;
  test_output << "1 - Dinner - "<<"18.50"<<"\n";
  test_output << "2 - Lunch - " <<"13.00"<<"\n";
  test_output << "Selection: ";
  int option = rand()%2+1;
  test_input << option <<endl;
  double balance = walletInput;
  if(option == 1){
    balance -=18.50;
  }
  else if(option == 2){
    balance -= 13.00;
  }
  else{
    test_output << "Invalid choice, try again\n";
  }

  test_output<< "Thank you for your purchase "<<name<<". You have " << balance<< " left on your account\n";

  ASSERT_EXECIO_EQ("main", test_input.str(), test_output.str());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
