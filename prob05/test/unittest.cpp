#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <string>
#include <fstream>
#include <list>
#include "gtest_ext.h"
#include "../doctors_schedule.hpp"
using ::testing::HasSubstr;
using ::testing::MatchesRegex;
using ::testing::ContainsRegex;

using namespace std;
const std::string RANDOM_TIMES[10] = {"5:40p.m.", "4:15p.m", "3:10p.m", "8:00a.m.", "10:45a.m.", "2:10p.m.", "11:20a.m.", "9:25a.m", "6:50p.m.", "7:00p.m."};
void generate_inputset(string &output,string &input, string name[] ,string location[],string times[],int num){
  std::ostringstream test_output;
  std::ostringstream test_input;
  for(int i = 0; i <num;i++){
    test_output << "Who is this appointment with?: ";
    name[i] = generate_string(30);
    test_input << name[i]<<endl;
    test_output << "Where is this appointment?: ";
    location[i] = generate_string(30);
    test_input << location[i]<<endl;
    test_output << "What time is this appointment?: ";
    times[i] = RANDOM_TIMES[rand()%10];
    test_input << times[i]<<endl;
    test_output << "\n\n";
  }
  input = test_input.str();
  output = test_output.str();
}


TEST(doctors_schedule, constructor_test) {
  std::string test_input;
  std::string test_output;
  std::string name[5];
  std::string location[5];
  std::string times[5];
  generate_inputset(test_output,test_input,name,location,times,5);


  ASSERT_SIO_EQ(test_input, test_output,{
    doctors_schedule test(5);
    ASSERT_EQ(test.current_appointment_num(),0);
    ASSERT_EQ(test.num_of_appointments(),5)<< "Did you forget to initialize the \"_num_of_appointments\" variable to the value we passed into the contructor?";
  });
}

TEST(doctors_schedule, current_appointment_test){
  std::string function_input;
  std::string function_output;
  std::string name[5];
  std::string location[5];
  std::string times[5];
  generate_inputset(function_output,function_input,name,location,times,5);
  std::ostringstream curr1;
  curr1 <<"You have an appointment with " << name[0] << " at "<<times[0]<<", "<<location[0] << "\n";
  ASSERT_SIO_EQ(function_input, function_output,{
    doctors_schedule test(5);
    std::string test_output = curr1.str();
    ASSERT_EQ(test.current_appointment(), test_output);
  });
}

TEST(doctors_schedule, next_appointment_test){
  std::string test_input;
  std::string test_output;
  std::string name[2];
  std::string location[2];
  std::string times[2];
  generate_inputset(test_output,test_input,name,location,times,2);
  std::ostringstream curr1;
  curr1 <<"You have an appointment with " << name[0] << " at "<<times[0]<<", "<<location[0] << "\n";
  std::ostringstream curr2;
  curr2 <<"You have an appointment with " << name[1] << " at "<<times[1]<<", "<<location[1] << "\n";
  ASSERT_SIO_EQ(test_input, test_output,{
    doctors_schedule test(2);
    std::string test_output1 = curr1.str();
    ASSERT_EQ(test.current_appointment(), test_output1);
    test.next_appointment();
    std::string test_output2 = curr2.str();
    ASSERT_EQ(test.current_appointment(), test_output2);
  });
}

TEST(doctors_schedule, is_finished_test){
  std::string test_input;
  std::string test_output;
  std::string name[5];
  std::string location[5];
  std::string times[5];
  generate_inputset(test_output,test_input,name,location,times,5);
  std::ostringstream curr1;
  curr1 <<"You have an appointment with " << name[0] << " at "<<times[0]<<", "<<location[0] << "\n";
  std::ostringstream curr2;
  curr2 <<"You have an appointment with " << name[1] << " at "<<times[1]<<", "<<location[1] << "\n";
  ASSERT_SIO_EQ(test_input, test_output,{
    doctors_schedule test(5);
    test.next_appointment();
    test.next_appointment();
    test.next_appointment();
    test.next_appointment();
    test.next_appointment();
    ASSERT_EQ(test.finished(), true) << "This should have returned true if we were finished with all of our appointments for the day";
  });
}

TEST(doctors_schedule, output_format){
  std::ostringstream test_output;
  std::ostringstream test_input;


  srand(time(NULL));
  int num = rand()%10;
  std::string name[num];
  std::string location[num];
  std::string times[num];
  test_output << "How many appointments does the doctor have?: ";
  test_input << num << endl;
  for(int i = 0; i <num;i++){
    test_output << "Who is this appointment with?: ";
    name[i] = generate_string(30);
    test_input << name[i]<<endl;
    test_output << "Where is this appointment?: ";
    location[i] = generate_string(30);
    test_input << location[i]<<endl;
    test_output << "What time is this appointment?: ";
    times[i] = RANDOM_TIMES[rand()%10];
    test_input << times[i]<<endl;
    test_output << "\n\n";
  }
  for( int i = 0; i <num;i++){
    test_output <<"You have an appointment with " << name[i] << " at "<<times[i]<<", "<<location[i] << "\n";
    test_output << "Press enter to move on to the next appointment";
    test_input << endl;
  }
  test_output << "Good work today, doctor!\n";
  ASSERT_EXECIO_EQ("main",test_input.str(), test_output.str());

}




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
