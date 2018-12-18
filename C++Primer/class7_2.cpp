#include <iostream>
using namespace std;

class Sales_data
{
    //友元声明
    friend Sales_data add(const Sales_data &, const Sales_data &);
    friend istream &read(istream &, Sales_data &);
    friend ostream &print(ostream &, const Sales_data &);

  public:
    Sales_data() = default;
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) {}
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(istream &);
    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);

  private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double avg_price() const { return units_sold ? revenue / units_sold : 0; }
};

//Sales_data接口的非成员组成部分的声明
Sales_data add(const Sales_data &, const Sales_data &);
istream &read(istream &, Sales_data &);
ostream &print(ostream &, const Sales_data &);