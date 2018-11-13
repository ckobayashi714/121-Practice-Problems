#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <iomanip>
#include "gtest_ext.h"
#include "../manager.hpp"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;

TEST(Manager, OutputFormat) {
  std::string unittest_output =
  "Name: Bill\n"
  "SSN: 1\n"
  "Project: Nothing\n"
  "Department Number: 2\n"
  "Hours Worked: -40.0\n"
  "Salary: 10000.00\n\n"

  "Checking Valid SSN...\n"
  "Not Valid SSN. Changing SSN to a temporary one.\n"
  "Checking Valid Project...\n"
  "Not Valid Project. Changing Project to NULL.\n"
  "Checking Hours Worked...\n"
  "Not Valid Number of Hours Worked. Changing Hours Worked to 0.\n"
  "Checking Salary...\n"
  "Cutting Salary in Half.\n\n"

  "Name: Bill\n"
  "SSN: 000000000\n"
  "Project: NULL\n"
  "Department Number: 2\n"
  "Hours Worked: 0.0\n"
  "Salary: 5000.00\n\n"

  "Name: Bob\n"
  "SSN: 123456789\n"
  "Project: Research\n"
  "Department Number: 1\n"
  "Hours Worked: 40.0\n"
  "Salary: 55000.00\n\n"

  "Checking Valid SSN...\n"
  "Valid SSN!\n"
  "Checking Valid Project...\n"
  "Valid Project!\n"
  "Checking Hours Worked...\n"
  "Valid Number of Hours Worked!\n"
  "Checking Salary...\n"
  "Doubling the Salary!\n\n"

  "Name: Bob\n"
  "SSN: 123456789\n"
  "Project: Research\n"
  "Department Number: 1\n"
  "Hours Worked: 40.0\n"
  "Salary: 110000.00\n";

  ASSERT_EXECIO_EQ("main", "", unittest_output);
}

TEST(Manager, PublicMethodPresent) {
  employee e1, *e2;
  e2 = &e1;
  manager m(e2);
  m.source_employee();
  std::string unittest_output =
  "Checking Valid SSN...\n"
  "Valid SSN!\n"
  "Checking Valid Project...\n"
  "Valid Project!\n"
  "Checking Hours Worked...\n"
  "Valid Number of Hours Worked!\n"
  "Checking Salary...\n"
  "Doubling the Salary!\n"
  "Name: Bob\n"
  "SSN: 123456789\n"
  "Project: Research\n"
  "Department Number: 1\n"
  "Hours Worked: 40.0\n"
  "Salary: 110000.00\n";

  ASSERT_SIO_EQ("", unittest_output, {
    m.change_ssn();
    m.change_project();
    m.change_hours_worked();
    m.change_salary();
    m.display_employee();
  });
}

TEST(Manager, AccessorAndNonDefaultConstructor) {
  std::string unittest_name = "Mary";
  std::string unittest_ssn = "5";
  std::string unittest_project = "Hello";
  int unittest_dept_num = 3;
  double unittest_hours_worked = 5.0;
  double unittest_salary = 3000.00;
  employee e1(unittest_name, unittest_ssn, unittest_project, unittest_dept_num,
              unittest_hours_worked, unittest_salary), *e2;
  e2 = &e1;
  manager your_manager(e2);
  employee your_employee = your_manager.source_employee();
  ASSERT_EQ(your_employee.name(), unittest_name);
  ASSERT_EQ(your_employee.ssn(), unittest_ssn);
  ASSERT_EQ(your_employee.project(), unittest_project);
  ASSERT_EQ(your_employee.dept_num(), unittest_dept_num);
  ASSERT_EQ(your_employee.hours_worked(), unittest_hours_worked);
  ASSERT_EQ(your_employee.salary(), unittest_salary);
}

TEST(Manager, ChangeEmployeeSSN) {
  employee e1, *e2;
  e2 = &e1;
  manager your_manager(e2);
  std::string unittest_output1 = "Checking Valid SSN...\nValid SSN!\n";
  ASSERT_SIO_EQ("", unittest_output1, {
    your_manager.change_ssn();
  });
  employee your_employee = your_manager.source_employee();
  std::string unittest_ssn = "123456789";
  ASSERT_EQ(your_employee.ssn(), unittest_ssn);

  e1.set_ssn("123");
  std::string unittest_output2 = "Checking Valid SSN...\n"
  "Not Valid SSN. Changing SSN to a temporary one.\n";
  ASSERT_SIO_EQ("", unittest_output2, {
    your_manager.change_ssn();
  });
  your_employee = your_manager.source_employee();
  unittest_ssn = "000000000";
  ASSERT_EQ(your_employee.ssn(), unittest_ssn);

  e1.set_ssn("12345678a");
  std::string unittest_output3 = "Checking Valid SSN...\n"
  "Not Valid SSN. Changing SSN to a temporary one.\n";
  ASSERT_SIO_EQ("", unittest_output3, {
    your_manager.change_ssn();
  });
  your_employee = your_manager.source_employee();
  unittest_ssn = "000000000";
  ASSERT_EQ(your_employee.ssn(), unittest_ssn);
}

TEST(Manager, ChangeEmployeeProject) {
  std::string proj_arr[6] = {"Research", "Security", "Web Application",
                             "Mobile Development", "Blockchain", "NULL"};
  employee e1, *e2;
  e2 = &e1;
  manager your_manager(e2);
  std::string unittest_output1 = "";
  for(int i = 0; i < 6; i++) {
    if(e1.project() == proj_arr[i]) {
      unittest_output1 = "Checking Valid Project...\nValid Project!\n";
      break;
    }
  }
  if(unittest_output1 == "") {
    unittest_output1 = "Checking Valid Project...\n"
    "Not Valid Project. Changing Project to NULL.\n";
  }
  ASSERT_SIO_EQ("", unittest_output1, {
    your_manager.change_project();
  });
  employee your_employee = your_manager.source_employee();
  std::string unittest_project = "Research";
  ASSERT_EQ(your_employee.project(), unittest_project);

  e1.set_project("123");
  std::string unittest_output2 = "";
  for(int i = 0; i < 6; i++) {
    if(e1.project() == proj_arr[i]) {
      unittest_output2 = "Checking Valid Project...\nValid Project!\n";
      break;
    }
  }
  if(unittest_output2 == "") {
    unittest_output2 = "Checking Valid Project...\n"
    "Not Valid Project. Changing Project to NULL.\n";
  }
  ASSERT_SIO_EQ("", unittest_output2, {
    your_manager.change_project();
  });
  your_employee = your_manager.source_employee();
  unittest_project = "NULL";
  ASSERT_EQ(your_employee.project(), unittest_project);

  e1.set_project("NULL");
  std::string unittest_output3 = "";
  for(int i = 0; i < 6; i++) {
    if(e1.project() == proj_arr[i]) {
      unittest_output3 = "Checking Valid Project...\nValid Project!\n";
      break;
    }
  }
  if(unittest_output3 == "") {
    unittest_output3 = "Checking Valid Project...\n"
    "Not Valid Project. Changing Project to NULL.\n";
  }
  ASSERT_SIO_EQ("", unittest_output3, {
    your_manager.change_project();
  });
  your_employee = your_manager.source_employee();
  unittest_project = "NULL";
  ASSERT_EQ(your_employee.project(), unittest_project);
}

TEST(Manager, ChangeEmployeeHoursWorked) {
  employee e1, *e2;
  e2 = &e1;
  manager your_manager(e2);
  std::string unittest_output1 = "Checking Hours Worked...\n"
  "Valid Number of Hours Worked!\n";
  ASSERT_SIO_EQ("", unittest_output1, {
    your_manager.change_hours_worked();
  });

  e1.set_hours_worked(-5.0);
  std::string unittest_output2 = "Checking Hours Worked...\n"
  "Not Valid Number of Hours Worked. Changing Hours Worked to 0.\n";
  ASSERT_SIO_EQ("", unittest_output2, {
    your_manager.change_hours_worked();
  });
  employee your_employee = your_manager.source_employee();
  double unittest_hours_worked = 0.0;
  ASSERT_EQ(your_employee.hours_worked(), unittest_hours_worked);
}

TEST(Manager, ChangeEmployeeSalary) {
  employee e1, *e2;
  e2 = &e1;
  manager your_manager(e2);
  std::string unittest_output1 = "Checking Salary...\n"
  "Doubling the Salary!\n";
  ASSERT_SIO_EQ("", unittest_output1, {
    your_manager.change_salary();
  });
  employee your_employee = your_manager.source_employee();
  double unittest_salary = 110000.00;
  ASSERT_EQ(your_employee.salary(), unittest_salary);

  e1.set_hours_worked(39.9);
  e1.set_salary(55000.00);
  std::string unittest_output2 = "Checking Salary...\n"
  "Cutting Salary in Half.\n";
  ASSERT_SIO_EQ("", unittest_output2, {
    your_manager.change_salary();
  });
  your_employee = your_manager.source_employee();
  unittest_salary = 27500.00;
  ASSERT_EQ(your_employee.salary(), unittest_salary);
}

TEST(Manager, PrintEmployee) {
  srand(time(NULL));
  for(int i = 0; i < 20; i++) {
    std::string unittest_name = generate_string(10);
    std::string unittest_ssn = generate_string(10);
    std::string unittest_project = generate_string(10);
    int unittest_dept_num = rand() % 10 + 1;
    double f = (double)rand() / RAND_MAX;
    double unittest_hours_worked = 0.0 + f * (100.0 - 0.0);
    double unittest_salary = 1000.00 + f * (1000000.00 - 1000.00);
    employee e1(unittest_name, unittest_ssn, unittest_project, unittest_dept_num,
                unittest_hours_worked, unittest_salary), *e2;
    e2 = &e1;
    manager your_manager(e2);
    std::ostringstream unittest_print_output;
    unittest_print_output << "Name: " << unittest_name << "\n";
    unittest_print_output << "SSN: " << unittest_ssn << "\n";
    unittest_print_output << "Project: " << unittest_project << "\n";
    unittest_print_output << "Department Number: " << unittest_dept_num << "\n";
    unittest_print_output << "Hours Worked: " << fixed << setprecision(1)
                          << unittest_hours_worked << "\n";
    unittest_print_output << "Salary: " << fixed << setprecision(2)
                          << unittest_salary << "\n";
    ASSERT_SIO_EQ("", unittest_print_output.str(), {
      your_manager.display_employee();
    });
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
