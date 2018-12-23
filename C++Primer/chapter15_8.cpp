#include <iostream>
#include <vector>
#include <memory>
#include <set>
using namespace std;

class Quote{
    public:
        Quote() = default;
        Quote(const string &book = "", double sales_price = 0.0) : bookNo(book), price(sales_price){ }
        string isbn() const
        {
            return bookNo;
        }
        virtual double net_price(size_t cnt)
        {
            return cnt * price;
        }

        //
        virtual Quote* clone() const & {
            return new Quote(*this);
        }
        virtual Quote *clone() &&{
            return new Quote(move(*this));
        }

      private:
        string bookNo;

    protected:
        double price;
};

class Bulk_Quote : public Quote{
    public:
        Bulk_Quote(const string &book = "", double sales_price = 0.0, size_t qty = 0, double disc = 0.0) :
        Quote(book, sales_price), min_qty(qty), discount(disc){ }

        double net_price(size_t cnt) override
        {
            if(cnt >= min_qty)
                return (1 - discount) * price * cnt;
            else
                return price * cnt;
        }

        //
        Bulk_Quote* clone() const& override{
            return new Bulk_Quote(*this);
        }
        Bulk_Quote* clone() && override{
            return new Bulk_Quote(move(*this));
        }

    private:
        size_t min_qty;
        double discount;
};

class Basket{
    public:
        void add_item(const shared_ptr<Quote> &sale)
        {
            items.insert(sale);
        }
        void add_item(const Quote &sale){   //拷贝给定的对象
            items.insert(shared_ptr<Quote>(sale.clone()));
        }
        void add_item(Quote &&sale){        //移动给定的对象
            items.insert(shared_ptr<Quote>(move(sale).clone()));
        }
        double total_receipt(ostream &) const;

    private:
        static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs)
        {
            return lhs->isbn() < rhs->isbn();
        }
        multiset<shared_ptr<Quote>, decltype(compare) *> items { compare };
};

double print_total(ostream &os, Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " total due: " << ret << endl;
    return ret;
}

double Basket::total_receipt(ostream &os) const
{
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter))     //upper_bound直接指向当前的尾后元素
    {
        sum += print_total(os, **iter, items.count(*iter)); 
    }
    os << "Total Sale: " << sum << endl;
    return sum;
}

void ques15_28()
{
    vector<Quote> quoteVec;
    quoteVec.push_back(Quote("C++ primer", 124.0));
    quoteVec.push_back(Bulk_Quote("C primer", 12.0, 8, 0.5));

    cout << (quoteVec.end() - 1) ->net_price(10) << endl;

    vector<shared_ptr<Quote>> ptrVec;
    ptrVec.push_back(make_shared<Quote>("c++", 124.0));
    ptrVec.push_back(make_shared<Bulk_Quote>("c++", 12.0, 8, 0.5));
    cout << ptrVec.back()->net_price(10) << endl;
}



int main()
{
    Basket bsk;
    bsk.add_item(make_shared<Quote>("456", 1.0));
    bsk.add_item(make_shared<Quote>("456", 1.0));
    bsk.add_item(make_shared<Bulk_Quote>("123", 12.0, 2, 0.5));
    bsk.add_item(make_shared<Bulk_Quote>("123", 12.0, 2, 0.5));
    bsk.add_item(make_shared<Bulk_Quote>("123", 12.0, 2, 0.5));
    bsk.add_item(make_shared<Bulk_Quote>("123", 12.0, 2, 0.5));
    bsk.add_item(make_shared<Bulk_Quote>("123", 12.0, 2, 0.5));
    bsk.total_receipt(cout);
}
