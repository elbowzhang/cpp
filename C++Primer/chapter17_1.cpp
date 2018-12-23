#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

void code()
{
    auto item = make_tuple("123", 3, 23.0);
    cout << get<0>(item);

    typedef decltype(item) trans;
    size_t sz = tuple_size<trans>::value;
    tuple_element<1, trans>::type cnt = get<1>(item);

    tuple<string, vector<string>, pair<string, int>> t;
}

class Sales_data{
    private:
        string bookNo;
    
    public:
        friend ostream& operator<<(ostream&, Sales_data&);
        friend Sales_data &operator+(Sales_data &, Sales_data &);
        Sales_data();
        Sales_data(const string &s) : bookNo(s) { }
        string isbn() const
        {
            return bookNo;
        }
};

ostream& operator<<(ostream &os, Sales_data &rhs)
{
    os << rhs.bookNo << endl;
    return os;
}

Sales_data& operator+(Sales_data &lhs, Sales_data &rhs)
{
    return lhs;
}

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

typedef tuple<vector<Sales_data>::size_type, vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator> matches;

vector<matches> findBook(const vector<vector<Sales_data>> &files, const string book)
{
    vector<matches> ret;
    for (auto it = files.cbegin(); it != files.cend(); ++it)
    {
        auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if(found.first != found.second) //this store has sales
            ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
    }
    return ret;
}

void reportResults(istream &in, ostream &os, const vector<vector<Sales_data>> &files)
{
    string s;
    
    while(in >> s){
        auto trans = findBook(files, s);
        if(trans.empty()){
            cout << s << " not found in any stores" << endl;
            continue;
        }
        for(const auto &store : trans){
            os << "store " << get<0>(store) << " sales: " << accumulate(get<1>(store), get<2>(store), Sales_data(s)) << endl;
        }
    }
}

int main()
{
    code();
}