#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <string>
#include <fstream>
#include "gtest_ext.h"
#include "../athlete.hpp"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;

TEST(Athlete, OutputFormat)
{
  std::ostringstream s, input;

  s << "Please enter the athlete's sport (q to quit): ";
  input << "Baseball" << endl;
  s << "Please enter the athlete's height (in): ";
  input << "74" << endl;
  s << "Please enter the athlete's weight (lbs): ";
  input << "195" << endl;
  s << "Please enter the shoe style: ";
  input << "Cleats" << endl;
  s << "Please enter the shoe color: ";
  input << "Red & White" << endl;
  s << "Please enter the shoe size (in): ";
  input << "12.5" << endl;
  s << "Please enter the athlete's sport (q to quit): ";
  input << "Basketball" << endl;
  s << "Please enter the athlete's height (in): ";
  input << "66" << endl;
  s << "Please enter the athlete's weight (lbs): ";
  input << "150" << endl;
  s << "Please enter the shoe style: ";
  input << "Basketball" << endl;
  s << "Please enter the shoe color: ";
  input << "Blue & Gold" << endl;
  s << "Please enter the shoe size (in): ";
  input << "9" << endl;
  s << "Please enter the athlete's sport (q to quit): ";
  input << "q" << endl;
  s << "Printing Athletes:\n";
  s << "Athlete 1\n";
  s << "Sport:  Baseball\n";
  s << "Height: 74in\n";
  s << "Weight: 195lbs\n";
  s << "Shoe:\n";
  s << "  Style:  Cleats\n";
  s << "  Color:  Red & White\n";
  s << "  Size:   12.5in\n";
  s << "Athlete 2\n";
  s << "Sport:  Basketball\n";
  s << "Height: 66in\n";
  s << "Weight: 150lbs\n";
  s << "Shoe:\n";
  s << "  Style:  Basketball\n";
  s << "  Color:  Blue & Gold\n";
  s << "  Size:   9in\n";
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("main", input.str(), s.str());
  });
}

TEST(Athlete, DefaultConstructorTest) {
  athlete a;
  std::string default_sport = "Cross-Country",
         default_style = "Running",
         default_color = "Blue";
  int default_height = 72, default_weight = 180;
  double default_size = 12;
  ASSERT_EQ(a.shoe()->style(), default_style);
  ASSERT_EQ(a.shoe()->color(), default_color);
  ASSERT_EQ(a.shoe()->size(), default_size);
  ASSERT_EQ(a.sport(), default_sport);
  ASSERT_EQ(a.height(), default_height);
  ASSERT_EQ(a.weight(), default_weight);
  std::string print_output = "Sport:  Cross-Country\n"
                             "Height: 72in\n"
                             "Weight: 180lbs\n"
                             "Shoe:\n"
                             "  Style:  Running\n"
                             "  Color:  Blue\n"
                             "  Size:   12in\n";
  ASSERT_SIO_EQ("", print_output, {
    a.print();
  });
}

TEST(Athlete, ConstructorTest) {
  std::string constructed_style = "Tennis",
         constructed_color = "Black",
         constructed_sport = "Tennis";
  int constructed_height = 70, constructed_weight = 170;
  double constructed_size = 11.5;
  athletic_shoe *s = new athletic_shoe(constructed_style,constructed_color,
                                       constructed_size);
  athlete a(constructed_sport, s, constructed_height, constructed_weight);
  ASSERT_EQ(a.shoe()->style(), constructed_style);
  ASSERT_EQ(a.shoe()->color(), constructed_color);
  ASSERT_EQ(a.shoe()->size(), constructed_size);
  ASSERT_EQ(a.sport(), constructed_sport);
  ASSERT_EQ(a.height(), constructed_height);
  ASSERT_EQ(a.weight(), constructed_weight);
  std::string print_output = "Sport:  Tennis\n"
                             "Height: 70in\n"
                             "Weight: 170lbs\n"
                             "Shoe:\n"
                             "  Style:  Tennis\n"
                             "  Color:  Black\n"
                             "  Size:   11.5in\n";
  ASSERT_SIO_EQ("", print_output, {
    a.print();
  });
}

TEST(Athlete, AccessorAndMutatorTest) {
  athlete a;
  athletic_shoe *as = new athletic_shoe;
  std::string mutator_style = "Flats",
         mutator_color = "Beige",
         mutator_sport = "Ballet";
  int mutator_height = 62, mutator_weight = 110;
  double mutator_size = 6.5;
  as->set_style(mutator_style);
  as->set_color(mutator_color);
  as->set_size(mutator_size);
  a.set_sport(mutator_sport);
  a.set_shoe(as);
  a.set_height(mutator_height);
  a.set_weight(mutator_weight);
  ASSERT_EQ(a.shoe()->style(), mutator_style);
  ASSERT_EQ(a.shoe()->color(), mutator_color);
  ASSERT_EQ(a.shoe()->size(), mutator_size);
  ASSERT_EQ(a.sport(), mutator_sport);
  ASSERT_EQ(a.height(), mutator_height);
  ASSERT_EQ(a.weight(), mutator_weight);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
