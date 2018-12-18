#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;
using namespace std::placeholders;

inline void output_words(vector<string> &words)
{
    for (auto iter = words.begin(); iter != words.end(); iter++)
        cout << *iter << " ";
    cout << endl;
}

inline void output_words(vector<string>::iterator beg, vector<string>::iterator end)
{
    for (auto iter = beg; iter != end; iter++)
        cout << *iter << " ";
    cout << endl;
}

bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}

void ques10_11()
{
    vector<string> svec = {"fox","jumps","over","quick","red","red","slow","red","the","the","turtle"};
    output_words(svec);

    sort(svec.begin(), svec.end());
    output_words(svec);

    auto end_unique = unique(svec.begin(),svec.end());
    output_words(svec);

    svec.erase(end_unique,svec.end());
    output_words(svec);

    //stable_sort(svec.begin(),svec.end(),isShorter);
    stable_sort(svec.begin(), svec.end(), [](const string &s1, const string &s2) { return s1.size() < s2.size(); });
    output_words(svec);
}

bool five_or_more(const string &s)
{
    return s.size() >= 5;
}

void ques10_12()
{
    vector<string> words = {"qwert", "asdfgh", "q", "aaa", "zxczxv"};
    output_words(words.begin(), words.end());

    auto iter = partition(words.begin(), words.end(), five_or_more);
    output_words(words.begin(), iter);
}

//put words in alphabet order and remove duplicates
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    output_words(words);
    auto end_unique = unique(words.begin(), words.end());
    output_words(words);
    words.erase(end_unique,words.end());
    output_words(words);
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

void biggies(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    output_words(words);
    stable_sort(words.begin(),words.end(),isShorter);

    auto wc = find_if(words.begin(), words.end(), [sz](const string &s) { return s.size() >= sz; });
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length " << sz << " or longer " << endl;

    for_each(wc, words.end(), [](const string &s) { cout << s << " "; });
    cout << endl;
}

void ques10_14()
{
    auto sum = [](const int &i1, const int &i2) { return i1 + i2; };
    cout << sum(1, 1) << endl;
}

void ques10_15()
{
    int i1 = 1;
    auto sum = [i1](const int &i2) { return i1 + i2; };
    cout << sum(1) << endl;
}

bool check_size(const string &s, string::size_type sz);
void ques10_18()
{
    vector<string> words = {"fox","jumps","over","quick","red","red","slow","red","the","the","turtle"};
    elimDups(words);
    stable_sort(words.begin(),words.end(),isShorter);
    output_words(words);
    int sz = 4;
    //auto iter = partition(words.begin(), words.end(), [sz](const string &s) { return s.size() >= sz; });
    // auto iter = stable_partition(words.begin(), words.end(), [sz](const string &s) { return s.size() >= sz; });
    auto iter = partition(words.begin(), words.end(), bind(check_size, _1, sz));
    output_words(words.begin(),iter);
}

void ques10_20()
{
    vector<string> words = {"fox","jumps","over","quick","red","red","slow","red","the","the","turtle"};
    int sz = 3;
    auto cnt = count_if(words.begin(), words.end(), [sz](const string &s) { return s.size() > sz; });
    cout << cnt << endl;
}

void ques10_21()
{
    int num = 10;
    auto f = [num]() mutable -> bool { if(num > 0){ num--; return false;} else return true; };

    for (int i = 0; i < 11; i++)
        cout << f() << endl;
}

bool check_size(const string &s, string::size_type sz)
{
    return s.size() >= sz;
}

void ques10_22()
{
    vector<string> words = {"fox","jumps","over","quick","red","red","slow","red","the","the","turtle"};
    auto cnt = count_if(words.begin(), words.end(), bind(check_size,_1,4));
    cout << cnt << endl;
}

bool check_size1(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}

void ques10_24()
{
    vector<int> vc = {1,2,3,4,5,6,7,8,9};
    string s = "helo";
    auto p = find_if(vc.begin(), vc.end(), bind(check_size1, s, _1));
    cout << *p;
}

int main()
{
    //ques10_11();
    //vector<string> words = {"fox","jumps","over","quick","red","red","slow","red","the","the","turtle"};
    //biggies(words,4);
    //ques10_18();

    //vector<int> vi;
    //transform(vi.begin(), vi.end(), vi.begin(), [](int i) -> int { if (i < 0) return -i; else return i; });
    ques10_18();
}