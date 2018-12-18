#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

istream &f(istream &in)
{
    string v;
    while (in >> v, !in.eof())
    {
        if (in.bad())
            throw runtime_error("IO stream error");
        if (in.fail())
        {
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

//8.9
// int main()
// {
//     ostringstream msg;
//     msg << "c++ primer" << endl;
//     istringstream in(msg.str());
//     f(in);
//     return 0;
// }

//8.10
// int main()
// {
//     ifstream in("data");
//     if (!in)
//     {
//         cerr << "cannot open file" << endl;
//         return -1;
//     }
//     string line;
//     vector<string> words;

//     while(getline(in,line)){
//         words.push_back(line);
//     }
//     in.close();
//     vector<string>::const_iterator it = words.begin();

//     while(it != words.end()){
//         istringstream line_str(*it);
//         string word;

//         while(line_str >> word){
//             cout << word << "-";
//         }
//         cout << endl;
//         ++it;
//     }

//     return 0;
// }

//8.13
struct PersonInfo
{
    string name;
    vector<string> phones;
};

string format(const string &s)
{
    return s;
}

bool valid(const string &s)
{
    return true;
}

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record;

    ifstream in("people");
    if (!in)
    {
        cerr << "cannot open file" << ends;
        return -1;
    }
    while (getline(in, line))
    {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        while (record >> word)
        {
            info.phones.push_back(word);
        }
        people.push_back(info);
    }
    ostringstream os;
    for (const auto &entry : people)
    {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones)
        {
            if (!valid(nums))
                badNums << " " << nums;
            else
                formatted << " " << format(nums);
        }
        if (badNums.str().empty())
            os << entry.name << " " << formatted.str() << endl;
        else
            cerr << "input error:" << entry.name << " invalid number(s) " << badNums.str() << endl;
    }
    cout << os.str() << endl;
    return 0;
}