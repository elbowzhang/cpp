#include <iostream>
using namespace std;

//base class
class Quote{
    public:
        Quote() = default;
        Quote(const string &book, double sales_price) : bookNo(book), price(sales_price) { }
        string isbn() const { return bookNo; }
        virtual double net_price(size_t n) const { return n * price; }
        virtual ~Quote() = default;

    private:
        string bookNo;
    protected:
        double price = 0.0;
};

//derived class
//纯虚基类只能用来继承，不能创建对象
class Disc_Quote : public Quote{
    public:
        Disc_Quote() = default;
        Disc_Quote(const string &book, double price, size_t qty, double disc) : Quote(book, price), quantity(qty), discount(disc) { }
        double net_price(size_t) const = 0; //纯虚函数
    
    protected:
        size_t quantity;
        double discount = 0.0;
};

class Bulk_Quote : public Disc_Quote{
    public:
        Bulk_Quote() = default;
        Bulk_Quote(const string &book, double price, size_t qty, double disc) : Disc_Quote(book, price, qty, disc) { }
        double net_price(size_t cnt) const override    //实现基类纯虚函数
        {
            if(cnt >= quantity)
                return cnt * (1 - discount) * price;
            else
                return cnt * price;
        }
};

class Limited_Quote : public Disc_Quote{
    public:
        Limited_Quote(const string &book = "", double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0) 
        : Disc_Quote(book, sales_price, qty, disc_rate) { }
        double net_price(size_t cnt) const override
        {
            if(cnt <= quantity)
                return cnt * (1 - discount) * price;
            else
                return quantity * (1 - discount) * price + (cnt - quantity) * price;
        }
};

class Base{
    public:
        void public_mem();
    protected:
        int prot_mem;
    private:
        char priv_mem;
};

struct Pub_Derv : public Base{
    int f()
    {
        return prot_mem;
    }
    char g()
    {
        //return priv_mem;
    }
};

struct Priv_Derv : private Base{
    int f1()
    {
        return prot_mem;
    }
};

int main()
{
    Pub_Derv d1;
    Priv_Derv d2;
    d1.public_mem();
    //d2.public_mem();
}
