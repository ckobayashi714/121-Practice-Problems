#include "dsa.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int main() {
  classroom cpsc121;
  cpsc121.populate("students.txt");
  cpsc121.list();
  return 0;
}
