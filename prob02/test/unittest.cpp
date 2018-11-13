#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <string>
#include <fstream>
#include "gtest_ext.h"
#include "../teacher.hpp"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;

TEST(Teacher, OutputFormat)
{
  std::ostringstream s, input;

  s << "Please enter the teacher's name: ";
  input << "Paul Inventado" << endl;
  s << "Prepare to enter in master test (Q to quit):" << endl;
  s << "Answer 1: ";
  input << "A" << endl;
  s << "Answer 2: ";
  input << "B" << endl;
  s << "Answer 3: ";
  input << "C" << endl;
  s << "Answer 4: ";
  input << "D" << endl;
  s << "Answer 5: ";
  input << "E" << endl;
  s << "Answer 6: ";
  input << "A" << endl;
  s << "Answer 7: ";
  input << "B" << endl;
  s << "Answer 8: ";
  input << "C" << endl;
  s << "Answer 9: ";
  input << "D" << endl;
  s << "Answer 10: ";
  input << "E" << endl;
  s << "Answer 11: ";
  input << "A" << endl;
  s << "Answer 12: ";
  input << "B" << endl;
  s << "Answer 13: ";
  input << "C" << endl;
  s << "Answer 14: ";
  input << "D" << endl;
  s << "Answer 15: ";
  input << "E" << endl;
  s << "Answer 16: ";
  input << "Q" << endl;
  s << "Please enter the student's name (Q to Quit): ";
  input << "Lonnie Hansen" << endl;
  s << "Prepare to enter student test:" << endl;
  s << "Answer 1: ";
  input << "B" << endl;
  s << "Answer 2: ";
  input << "C" << endl;
  s << "Answer 3: ";
  input << "D" << endl;
  s << "Answer 4: ";
  input << "E" << endl;
  s << "Answer 5: ";
  input << "A" << endl;
  s << "Answer 6: ";
  input << "A" << endl;
  s << "Answer 7: ";
  input << "B" << endl;
  s << "Answer 8: ";
  input << "C" << endl;
  s << "Answer 9: ";
  input << "D" << endl;
  s << "Answer 10: ";
  input << "E" << endl;
  s << "Answer 11: ";
  input << "A" << endl;
  s << "Answer 12: ";
  input << "B" << endl;
  s << "Answer 13: ";
  input << "C" << endl;
  s << "Answer 14: ";
  input << "D" << endl;
  s << "Answer 15: ";
  input << "E" << endl;
  s << "Please enter the student's name (Q to Quit): ";
  input << "Q" << endl;
  s << endl << "Student         Grade" << endl;
  s << "Lonnie Hansen   66.67" << endl;
  ASSERT_DURATION_LE(3, {
    ASSERT_EXECIO_EQ("main", input.str(), s.str());
  });
}

TEST(Teacher, DefaultConstructorTest) {
  teacher t;
  student s;
  string default_teacher_name = "Tea Cher", default_student_name = "Stu Dent";
  int default_num_questions = 0;
  double default_grade = 0;
  ASSERT_EQ(t.name(), default_teacher_name);
  ASSERT_EQ(t.num_questions(), default_num_questions);
  ASSERT_EQ(s.name(), default_student_name);
  ASSERT_EQ(s.num_questions(), default_num_questions);
  ASSERT_EQ(s.grade(), default_grade);
}

TEST(Teacher, ConstructorTest) {
  string constructed_teacher_name = "Paul Inventado",
         constructed_student_name = "Lonnie Hansen";
  char constructed_test[5] = { 'A', 'B', 'C', 'D', 'E' };
  int constructed_num_questions = 5;
  teacher t(constructed_teacher_name, constructed_test,
            constructed_num_questions);
  student s(constructed_student_name, constructed_test,
            constructed_num_questions);
  ASSERT_EQ(t.name(), constructed_teacher_name);
  ASSERT_EQ(t.num_questions(), constructed_num_questions);
  ASSERT_EQ(s.name(), constructed_student_name);
  ASSERT_EQ(s.num_questions(), constructed_num_questions);
  int zero = 0;
  ASSERT_EQ(s.grade(), zero);
}

TEST(Teacher, AccessorAndMutatorTest) {
  teacher t;
  string mutator_teacher_name = "Paul Inventado",
         mutator_student_name = "Andrew Gomez";
  char teacher_test[5] = { 'A', 'B', 'C', 'D', 'E' };
  char student_test[5] = { 'A', 'B', 'A', 'D', 'E' };
  double student_grade = 80;
  int num_questions = 5;
  t.set_name(mutator_teacher_name);
  t.add_master_test(teacher_test, num_questions);
  student *s = new student;
  s->set_name(mutator_student_name);
  s->add_test(student_test, num_questions);
  t.assign_grade(s);
  ASSERT_EQ(t.name(), mutator_teacher_name);
  ASSERT_EQ(t.num_questions(), num_questions);
  ASSERT_EQ(s->name(), mutator_student_name);
  ASSERT_EQ(s->num_questions(), num_questions);
  ASSERT_EQ(s->grade(), student_grade);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
