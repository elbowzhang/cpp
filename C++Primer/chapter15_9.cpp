#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

using line_no = vector<string>::size_type;
using line_it = set<line_no>::const_iterator;

class QueryResult;
class TextQuery
{
    public:
        TextQuery(ifstream&);
        QueryResult query(const string &) const;
    private:
        shared_ptr<vector<string>> file;
        map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
    friend ostream &print(ostream &, const QueryResult &);
    public:
      QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) : 
      sought(s), lines(p), file(f)
      { }
      set<line_no>::size_type size() const{
          return lines->size();
      }
      line_it begin() const {
          return lines->cbegin();
      }
      line_it end() const {
          return lines->cend();
      }
      shared_ptr<vector<string>> get_file(){
          return file;
      }

    private:
        string sought;
        shared_ptr<set<line_no>> lines;
        shared_ptr<vector<string>> file;
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>)
{
    string text;
    while(getline(is, text))
    {
        file->push_back(text);
        int n = file->size() - 1;   //current line number
        istringstream line(text);
        string word;
        while (line >> word)
        {
            auto &lines = wm[word];
            if(!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if(loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

string make_plura(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1) ? word + ending : word;
}

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " " << make_plura(qr.lines->size(), "time", "s") << endl;
    for(auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    return os;
}

class QueryBase{
    friend class Query;
    protected:
        virtual ~QueryBase() = default;
    private:
        virtual QueryResult eval(const TextQuery &) const = 0;
        virtual string rep() const = 0;
};

class WordQuery;
class Query{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
    public:
        inline Query(const string &s) : q(new WordQuery(s)) {
            cout << "Query Constructor" << endl;
        }
        QueryResult eval(const TextQuery &t) const
        {
            return q->eval(t);
        }
        string rep() const
        {
            return q->rep();
        }
    private:
        Query(shared_ptr<QueryBase> query) : q(query){
            cout << "Query private constructor" << endl;
        }
        shared_ptr<QueryBase> q;
};

ostream& operator<<(ostream &os, const Query &query)
{
    return os << query.rep();
}

class WordQuery : public QueryBase{
    friend class Query;
    WordQuery(const string &s) : query_word(s) {
        cout << "WordQuery Constructor" << endl;
    }
    QueryResult eval(const TextQuery &t) const{
        return t.query(query_word);
    }
    string rep() const{
        return query_word;
    }
    string query_word;
};

class NotQuery : public QueryBase{
    friend Query operator~(const Query &);
    NotQuery(const Query &q) : query(q) {
        cout << "NotQuery constructor" << endl;
    }
    string rep() const {
        return "~(" + query.rep() + ")";
    }
    QueryResult eval(const TextQuery &) const;
    Query query;
};

inline Query operator~(const Query &operand)
{
    return shared_ptr<QueryBase>(new NotQuery(operand));
}

QueryResult NotQuery::eval(const TextQuery &text) const
{
    auto result = query.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    auto beg = result.begin(), end = result.end();
    auto sz = result.get_file()->size();
    for (size_t n = 0; n != sz; ++n)
    {
        if(beg == end || *beg != n)
            ret_lines->insert(n);
        else if(beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
}

class BinaryQuery : public QueryBase{
    protected:
        BinaryQuery(const Query &l, const Query &r, string s) : lhs(l), rhs(r), opSym(s){
            cout << "BinaryQuery contructor" << endl;
        }
        string rep() const{
            return "(" + lhs.rep() + opSym + " " + rhs.rep() + ")";
        }
    Query lhs, rhs;
    string opSym;
};

class AndQuery : public BinaryQuery{
    friend Query operator&(const Query &, const Query &);
    AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&") {
        cout << "AndQuery constructor" << endl;
    }
    QueryResult eval(const TextQuery &) const;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

QueryResult AndQuery::eval(const TextQuery &text) const
{
    auto left = lhs.eval(text), right = rhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>();
    set_intersection(left.begin(), left.end(), right.begin(), right.end(), inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

class OrQuery : public BinaryQuery{
    friend Query operator|(const Query &, const Query &);
    OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {
        cout << "OrQuery constructor" << endl;
    }
    QueryResult eval(const TextQuery &) const;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery &text) const
{
    auto right = rhs.eval(text), left = lhs.eval(text);
    auto ret_lines = make_shared<set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}