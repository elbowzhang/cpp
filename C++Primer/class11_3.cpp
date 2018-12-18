#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <fstream>
#include <sstream>
using namespace std;

void ques11_15()
{
    map<int, vector<int>> m;
    //mapped_type是vector<int>
    //key_type是int
    //value_type是pair<const int,vector<int>>
}

void ques11_18()
{
    map<string, int>::iterator iter;
}

void ques11_20()
{
    map<string, int> word_counter;
    string word;
    while(cin >> word){
        auto ret = word_counter.insert({word,1});
        if(!ret.second)
            ++ret.first->second;
    }
}

void print_worker(multimap<string, string> &worker)
{
    for(auto &work:worker)
        cout << work.first << " " << work.second << endl;
}
 
void ques11_31()
{
    multimap<string, string> worker;
    worker.insert({"a","a"});
    worker.insert({"a","b"});
    worker.insert({"a","c"});
    worker.insert({"b","a"});

    print_worker(worker);

    auto pair1 = worker.equal_range("a");
    for (auto beg = pair1.first, end = pair1.second; beg != end; beg++)
        cout << beg->second << endl;
}

const string &
transform(const string &s, const map<string, string> &m)
{
    auto map_it = m.find(s);
    if(map_it != m.cend())
        return map_it->second;
    else
        return s;
}

map<string,string>
buildMap(ifstream &map_file)
{
    map<string, string> trans_map;
    string key;
    string value;
    while(map_file >> key && getline(map_file, value)){
        cout << key << "--" << value << endl;
        if(value.size() > 1)
            trans_map[key] = value.substr(1);
        else
            throw runtime_error("no rule for " + key);
    }
    return trans_map;
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = buildMap(map_file);
    string text;
    while(getline(input,text)){
        istringstream stream(text);
        string word;
        bool firstword = true;
        while(stream >> word){
            if(firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map);
        }
        cout << endl;
    }
}

void ques11_33()
{
    ifstream map_file("map1");
    ifstream input("mess");
    word_transform(map_file,input);
}

int main()
{
    ques11_33();
}