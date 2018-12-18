#include <iostream>
using namespace std;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0.0;

    Sales_data() = default;
    Sales_data(const string &s) : bookNo(s) {}
    Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p*n) {}
    Sales_data(istream &);

    string isbn() const { return bookNo; }
    Sales_data &combine(const Sales_data &);
    double avg_price() const;
};

Sales_data add(const Sales_data &, const Sales_data &);
ostream &print(ostream &, const Sales_data &);
istream &read(istream &, Sales_data &);

double Sales_data::avg_price() const
{
    if (units_sold)
        return revenue / units_sold;
    else
        return 0;
}

Sales_data::Sales_data(istream &is)
{
    read(is, *this);
}

//usage: total.combine(trans)
Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum.combine(rhs);
    return sum;
}

istream &read(istream &is, Sales_data &item)
{
    is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
    return is;
}

ostream &print(ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.sellingprice << " " << item.saleprice << " " << item.discount;
    return os;
}

// class Sale_item
// {
//   private:
//     string bookNo;
//     unsigned units_sold = 0;
//     double sellingprice = 0.0;
//     double saleprice = 0.0;
//     double discount = 0.0;

//   public:
//     string isbn() const { return bookNo; }
//     Sale_item &combine(const Sale_item &rhs)
//     {
//         units_sold += rhs.units_sold;
//         saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / units_sold;
//         if (sellingprice != 0)
//             discount = saleprice / sellingprice;
//         return *this;
//     }
// };

int main()
{
    Sales_data total;

    if (read(cin, total))
    {
        Sales_data trans;
        while (read(cin, trans))
        {
            if (total.isbn() == trans.isbn())
            {
                total = add(total, trans);
            }
            else
            {
                print(cout, total);
                cout << endl;
                total = trans;
            }
        }
        print(cout, total);
        cout << endl;
    }
    else
    {
        return -1;
    }
    return 0;
}