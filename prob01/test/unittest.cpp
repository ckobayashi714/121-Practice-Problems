#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <iomanip>
#include "gtest_ext.h"
#include "../milktea.hpp"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;

TEST(MilkTea, OutputFormat) {
  std::string unittest_output =
  "Topping: Pudding\n"
  "Cost: $1.00\n"
  "Topping: Pudding\n"
  "Cost: $1.00\n"
  "Flavor: Honey Milk Tea\n"
  "Topping: Aloe\n"
  "Cost: $1.50\n";
  ASSERT_EXECIO_EQ("main", "", unittest_output);
}

TEST(MilkTea, PublicMethodPresent) {
  topping *t1, t2;
  t1 = &t2;
  milktea m1;
  milktea m2("Name", t1);
  m2.flavor();
  m2.set_flavor("F");
  m2.source_topping();
  m2.set_source_topping(t1);
  std::string unittest_output =
  "Flavor: F Milk Tea\n"
  "Topping: Boba\n"
  "Cost: $0.50\n";
  ASSERT_SIO_EQ("", unittest_output, {
    m2.print_milktea();
  });
}

TEST(MilkTea, MutatorsAndAccessors) {
  std::string unittest_name = "Grass Jelly";
  double unittest_cost = 0.75;
  topping t1(unittest_name, unittest_cost), *t2;
  t2 = &t1;
  milktea your_milktea;
  std::string unittest_flavor = generate_string(10);
  your_milktea.set_flavor(unittest_flavor);
  ASSERT_EQ(your_milktea.flavor(), unittest_flavor);
  your_milktea.set_source_topping(t2);
  topping your_topping = your_milktea.source_topping();
  ASSERT_EQ(your_topping.name(), unittest_name);
  ASSERT_EQ(your_topping.cost(), unittest_cost);
}

TEST(MilkTea, DefaultConstructor) {
  milktea your_milktea;
  std::string unittest_output = "Classic";
  ASSERT_EQ(your_milktea.flavor(), unittest_output);
}

TEST(MilkTea, NonDefaultConstructor) {
  std::string unittest_name = "Sea Salt";
  double unittest_cost = 0.25;
  topping t1(unittest_name, unittest_cost), *t2;
  t2 = &t1;
  std::string unittest_flavor = "Flavor";
  milktea your_milktea(unittest_flavor, t2);
  topping your_topping = your_milktea.source_topping();
  ASSERT_EQ(your_milktea.flavor(), unittest_flavor);
  ASSERT_EQ(your_topping.name(), unittest_name);
  ASSERT_EQ(your_topping.cost(), unittest_cost);
}

TEST(MilkTea, PrintMilkTea) {
  srand(time(NULL));
  for(int i = 0; i < 3; i++) {
    std::string unittest_name = generate_string(10);
    double f = (double)rand() / RAND_MAX;
    double unittest_cost = 0.0 + f * (3.00 - 0.0);
    topping t1(unittest_name, unittest_cost), *t2;
    t2 = &t1;
    std::string unittest_flavor = generate_string(10);
    milktea your_milktea(unittest_flavor, t2);
    std::ostringstream unittest_print_output;
    unittest_print_output << "Flavor: " << unittest_flavor << " Milk Tea\n";
    unittest_print_output << "Topping: " << unittest_name << "\n";
    unittest_print_output << "Cost: $" << fixed << setprecision(2)
                          << unittest_cost << "\n";
    ASSERT_SIO_EQ("", unittest_print_output.str(), {
      your_milktea.print_milktea();
    });
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
