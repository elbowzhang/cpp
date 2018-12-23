#include <iostream>
using namespace std;

//base class
class Quote{
    public:
        Quote() = default;
        Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) { }
        string isbn() const { return bookNo; }
        virtual double net_price(size_t n) const { return n * price; }
        virtual void debug()
        {
            cout << "bookNo = " << bookNo << " price = " << price << endl;
        }
        virtual ~Quote() = default;

    private:
        string bookNo;
    protected:
        double price = 0.0;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << endl;
    return ret;
}

class Bulk_Quote : public Quote{
    public:
        Bulk_Quote() = default;
        Bulk_Quote(const string & book, double p, size_t qty, double disc) : Quote(book, p), min_qty(qty), discount(disc) { }
        double net_price(size_t) const override;
        virtual void debug() override final
        {
            Quote::debug();
            cout << "min_qty = " << min_qty << " discount = " << discount << endl;
        }
        
    private:
        size_t min_qty = 0;
        double discount = 0.0;
};

double Bulk_Quote::net_price(size_t cnt) const
{
    if(cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

int main()
{
    Quote base("123",2);
    Bulk_Quote derive("2345",2,5,0.3);
    base.debug();
    derive.debug();
}