#include <iostream>
using namespace std;

class Quote{
    public:
        Quote() = default;
        Quote(const string &book = "", double sales_price = 0.0) : bookNo(book), price(sales_price){
            cout << "Quote constructor is running" << endl;
        }
        string isbn() const
        {
            return bookNo;
        }
        virtual double net_price(size_t cnt) const
        {
            return cnt * price;
        }
        virtual void debug()
        {
            cout << "bookNo = " << bookNo << " price = " << price << endl;
        }
        virtual ~Quote()
        {
            cout << "Quote destructor is running" << endl;
        }

        friend ostream &operator<<(ostream &, Quote &);

    private:
        string bookNo;
    protected:
        double price;
};

ostream& operator << (ostream &os, Quote &e)
{
    os << "\t using operator <<(ostream&, Quote&);" << endl;
    return os;
}

class Bulk_Quote : public Quote{
    public:
        Bulk_Quote(const string &book = "", double sales_price = 0.0, size_t qty = 0, double disc = 0) : 
        Quote(book, sales_price), min_qty(qty), discount(disc)
        {
            cout << "Bulk_Quote constructor is running" << endl;
        }
        double net_price(size_t cnt) const
        {
            if(cnt >= min_qty)
                return (1 - discount) * cnt * price;
            else
                return cnt * price;
        }
        ~Bulk_Quote()
        {
            cout << "Bulk_Quote destructor is running" << endl;
        }

    private:
        size_t min_qty;
        double discount;
};

class Disc_Quote : public Bulk_Quote{
    public:
        using Bulk_Quote::Bulk_Quote;       //继承基类的构造函数
};

int main()
{
    //Quote base("c++ primer", 129.0);
    Disc_Quote derive("c++ primer", 12.0, 12, 0.2);
    //cout << base << endl;
    //cout << derive << endl;
}