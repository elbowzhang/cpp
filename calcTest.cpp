#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

bool isNum(char ch)
{
    if (ch >= '0' && ch <= '9')
        return true;
    else
        return false;
}

bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getLevel(char ch)
{
    switch (ch)
    {
    case '(':
        return 5;
    case '*':
    case '/':
        return 4;
    case '+':
    case '-':
        return 3;
    case ')':
        return 2;
    }
}

double string2Digit(string s)
{
    if (s.length() == 0)
        return __INT_MAX__;
    bool flag = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (i == 0 && s[i] == '-')
            continue;
        else if (s[i] == '.' && !flag)
        {
            if (i > 0 && isNum(s[i - 1]))
            {
                flag = true;
                continue;
            }
            else
                return __INT_MAX__;
        }
        else if (isNum(s[i]))
            continue;
        else
            return __INT_MAX__;
    }
    double result = atof(s.c_str());
    return result;
}

vector<string> prefix2Suffix(string s)
{
    stack<char> stackOperator;
    vector<string> suffix;
    int i = 0;
    while (i < s.length())
    {
        if (isNum(s[i]))
        {
            string str = "";
            while (isNum(s[i]) || s[i] == '.')
            {
                str += s[i];
                i++;
            }
            suffix.push_back(str);
        }
        else if (isOperator(s[i]))
        {
            //复数情况
            if (s[i] == '-' && i > 0 && !isNum(s[i - 1]))
            {
                string str = "-";
                i++;
                while (isNum(s[i] || s[i] == '.'))
                {
                    str += s[i];
                    i++;
                }
                suffix.push_back(str);
            }
            else
            {
                if (stackOperator.empty())
                {
                    stackOperator.push(s[i]);
                    i++;
                }
                else
                {
                    int initial = getLevel(s[i]);
                    if (initial == 2)
                    {
                        while (getLevel(stackOperator.top()) != 5 && !stackOperator.empty()) 
                        {
                            string str = "";
                            str += stackOperator.top();
                            suffix.push_back(str);
                            stackOperator.pop();
                        }
                        if (stackOperator.top() == '(')
                            stackOperator.pop();
                            i++;
                    }
                    else
                    {
                        while ((!stackOperator.empty()) && (initial <= getLevel(stackOperator.top())) && (getLevel(stackOperator.top())) != 5)
                        {
                            string str = "";
                            str += stackOperator.top();
                            suffix.push_back(str);
                            stackOperator.pop();
                        }
                        stackOperator.push(s[i]);
                        i++;
                    }
                }
            }
        }
        else
        {
            cout << "error" << endl;
            suffix.clear();
            return suffix;
        }
    }
    while (!stackOperator.empty())
    {
        string str = "";
        str += stackOperator.top();
        stackOperator.pop();
        suffix.push_back(str);
    }
    return suffix;
}

double calc(vector<string> suffix)
{
    stack<double> stackValue;
    for (int i = 0; i < suffix.size(); i++)
    {
        if (suffix[i].length() == 1 && isOperator(suffix[i][0]))
        {
            double a = 0, b = 0;
            if (!stackValue.empty())
            {
                a = stackValue.top();
                stackValue.pop();
            }
            else
                return __INT_MAX__;

            if (!stackValue.empty())
            {
                b = stackValue.top();
                stackValue.pop();
            }
            else
                return __INT_MAX__;

            switch (suffix[i][0])
            {
            case '+':
                stackValue.push(b + a);
                break;
            case '-':
                stackValue.push(b - a);
                break;
            case '*':
                stackValue.push(b * a);
                break;
            case '/':
                stackValue.push(b / a);
                break;
            default:
                return __INT_MAX__;
            }
        }
        else
        {
            if (string2Digit(suffix[i]) == __INT_MAX__)
                return __INT_MAX__;
            else
                stackValue.push(string2Digit(suffix[i]));
        }
    }
    if (stackValue.empty())
        return __INT_MAX__;
    double value = stackValue.top();
    stackValue.pop();
    return value;
}

int main()
{
    string s = "1+2*3";
    vector<string> suffix;

    suffix = prefix2Suffix(s);
    for (auto str : suffix)
        cout << str << endl;

    double value = calc(suffix);
    cout << value << endl;
}
