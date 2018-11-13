#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <string>
#include <fstream>
#include "gtest_ext.h"
#include "../dsa.hpp"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;

TEST(student, publicMethods) {
  student s;
  s.name();
  s.id();
  s.set_name(generate_string(10));
  s.set_id(rand());
}

TEST(student, defaultConstructor) {
  student your_student;
  ASSERT_EQ(your_student.name(), "Stu Dent");
  ASSERT_EQ(your_student.id(), 123456789);
}

TEST(student, nondefaultConstructor) {
  std::string unittest_name = generate_string(10);
  int unittest_id = rand() % 1000;
  student your_student(unittest_name, unittest_id);
  ASSERT_EQ(your_student.name(), unittest_name);
  ASSERT_EQ(your_student.id(), unittest_id);
}

TEST(classroom, publicMethods) {
  classroom c;
  c.students();
  c.num_students();
  c.populate("students.txt");
  std::string unittest_output = "Student list\n1. 505895605 Lonnie Hansen\n"
                         "2. 265588505 Sunny To\n3. 161732427 Leah Smith\n"
                         "4. 877254949 San Tran\n5. 644480729 Andrew Gomez\n";
  ASSERT_SIO_EQ("", unittest_output, {
    c.list();
  });
}

TEST(classroom, defaultConstructor) {
  classroom your_classroom;
  ASSERT_EQ(your_classroom.num_students(), 0);
}

TEST(classroom, nondefaultConstructor) {
  std::string unittest_name = generate_string(10);
  int unittest_id = rand() % 1000;
  student your_student(unittest_name, unittest_id);
  ASSERT_EQ(your_student.name(), unittest_name);
  ASSERT_EQ(your_student.id(), unittest_id);
}

TEST(classroom, populateAndAccessor) {
  classroom your_classroom;
  your_classroom.populate("students.txt");
  student* your_students = your_classroom.students();
  ASSERT_EQ(your_classroom.num_students(), 5);
  std::string unittest_names[5] = {"Lonnie Hansen", "Sunny To", "Leah Smith",
                                  "San Tran", "Andrew Gomez"};
  int unittest_ids[5] = {505895605, 265588505, 161732427, 877254949, 644480729};
  for (int i = 0; i < 5; i++) {
    ASSERT_EQ(your_students[i].name(), unittest_names[i]);
    ASSERT_EQ(your_students[i].id(), unittest_ids[i]);
  }
}

TEST(classroom, List)
{
  std::string unittest_output = "Student list\n1. 505895605 Lonnie Hansen\n"
                         "2. 265588505 Sunny To\n3. 161732427 Leah Smith\n"
                         "4. 877254949 San Tran\n5. 644480729 Andrew Gomez\n";
  ASSERT_EXECIO_EQ("main", "", unittest_output);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
