#include <iostream>
using namespace std;

class Person
{
  private:
    string strName;
    string strAddress;

  public:
    Person() = default;
    Person(const string &name, const string &address) : strName(name), strAddress(address) {}
    Person(istream &is) { is >> *this; }

    string getName() const { return strName; }
    string getAddress() const { return strAddress; }
};