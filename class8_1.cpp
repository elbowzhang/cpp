#include <iostream>
using namespace std;

istream &f(istream & in)
{
    int v;
    while(in >> v, !in.eof())
    {
        if(in.bad())
            throw runtime_error("IO error");
        if(in.fail()){
            cerr << "data error" << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main()
{
    cout << "input:" << endl;
    f(cin);
    return 1;
}