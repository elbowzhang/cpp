#include <iostream>
#include <regex>
using namespace std;

//regular expressions
//i before e except after c
void findi()
{
    string pattern("[^c]ei");
    pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
    regex r(pattern);
    smatch results;
    string test = "receipt freind theif receive";
    if(regex_search(test, results, r))
        cout << results.str() << endl;
}

int main()
{
    findi();
}