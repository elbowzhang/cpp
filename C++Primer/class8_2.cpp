#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ifstream in("data");
    if(!in)
    {
        cerr << "cannot open file" << endl;
        return -1;
    }

    string line;
    vector<string> words;
    while(getline(in, line)){
        words.push_back(line);
    }

    in.close();
    for(auto i : words)
        cout << i << endl;
}