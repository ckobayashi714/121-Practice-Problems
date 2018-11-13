#include <string>
using namespace std;
class wallet {
private:
  string _owner;
  double _balance;
public:
  wallet(string owner , double balance) {
    _owner = owner;
    _balance = balance;
  }
  void make_purchase(double purchase) { _balance -= purchase; }
  double balance() { return _balance; }
  string owner() { return _owner; }
};

//MAKE THE buffet CLASS BELOW
