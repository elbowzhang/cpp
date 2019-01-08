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

void findcc()
{
    regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$", regex::icase);
    smatch results;
    string filename;
    while(cin >> filename)
        if(regex_search(filename, results, r))
            cout << results.str() << endl;
}

void catcherror()
{ 
    try
    {
        regex r("[[:alnum:]+\\.(cpp|cxx|cc)$", regex::icase);
    }
    catch(const regex_error e)
    {
        cout << e.what() << "\ncode: " << e.code() << endl;
    }
    
}

int main()
{
    catcherror();
}