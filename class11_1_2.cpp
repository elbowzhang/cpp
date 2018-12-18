#include <iostream>
#include <map>
#include <string>
#include <set>
#include <list>
#include <vector>
#include <fstream>
#include <sstream>
#include <utility>

using namespace std;

void mapExample()
{
    map<string, size_t> word_count;
    string word;
    while(cin >> word)
        ++word_count[word]; //如果word不在map中，就创建一个新元素，关键字为word
    for(const auto &w:word_count)
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times " : " time ") << endl;
}

void setExample()
{
    map<string, size_t> word_count;
    set<string> exclude = {"The", "But", "And", "Or"};
    string word;
    while(cin >> word)
        if (exclude.find(word) == exclude.end())
            ++word_count[word];
    for(const auto &w:word_count)
        cout << w.first << " occurs " << w.second << ((w.second > 1) ? " times " : " time ") << endl;
}

void add_family(map<string, vector<string>> &families, const string &family)
{
    // if (families.find(family) == families.end())
    //     families[family] = vector<string>();
    families[family];   //也可以这么写
}

void add_child(map<string, vector<string>> &families, const string &family, const string &child)
{
    families[family].push_back(child);
}

void ques11_7()
{
    map<string, vector<string>> families;

    add_family(families,"A");
    add_child(families,"A","a");
    add_child(families,"A","b");
    add_family(families,"B");
    add_child(families,"B","a");

    for(auto f:families){
        cout << f.first << " childs: ";
        for(auto c:f.second)
            cout << c << " ";
        cout << endl;
    }
}

void ques11_9()
{
    ifstream in("data");
    map<string, list<int>> word_lineno;
    string line;
    string word;
    int lineno = 0;
    while(getline(in,line)){
        lineno++;
        istringstream l_in(line);
        while(l_in >> word){
            word_lineno[word].push_back(lineno);
        }
    }
}

void ques11_10()
{
    //有序容器要求关键字类型必须支持比较操作<
    map<vector<int>::iterator, int> m1;     //可以，vector的迭代器支持比较操作
    map<list<int>::iterator, int> m2;       //不可以，list元素不是连续存储，迭代器不支持比较操作
}

pair<string, int>
process(vector<string> &v)
{
    if(!v.empty())
        return {v.back(), v.back().size()};
    //return pair<string, int>(v.back(), v.back().size());
    //return make_pair(v.back(),v.back().size());
    else
        return pair<string, int>();
}

void ques11_12()
{
    ifstream in("data");
    vector<pair<string, int>> data;
    string s;
    int v;
    while(in >> s && in >> v)
        data.push_back(pair<string, int>(s,v));
        // data.push_back({s,v});
        // data.push_back(make_pair(s,v));

    for (const auto &d : data)
        cout << d.first << "&" << d.second << endl;
}

int main()
{
    ques11_12();
}