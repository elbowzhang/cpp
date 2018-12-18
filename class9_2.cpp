#include <iostream>
#include <vector>
#include <list>
using namespace std;

bool search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val)
{
    while(beg != end){
        if(*beg == val)
            return true;
        beg++;
    }
    return false;
}

vector<int>::iterator search_vec_iter(vector<int>::iterator beg, vector<int>::iterator end, int val)
{
    while(beg != end){
        if(*beg == val)
            return beg;
        beg++;
    }
    return end;
}

void test_container()
{
    list<int> ilist = {1,2,3,4,5,6,7};
    vector<int> ivector = {7,6,5,4,3,2,1};

    //容器类型不同，不能使用拷贝初始化
    //vector<double> dvector(ilist);
    //元素类型相同，可以使用范围初始化
    vector<double> dvector(ilist.begin(), ilist.end());
    cout << dvector.capacity() << " " << dvector.size() << " " << dvector[0] << " " << dvector[dvector.size() - 1] << endl;

    vector<double> dvector1(ivector.begin(), ivector.end());
    cout << dvector1.capacity() << " " << dvector1.size() << " " << dvector1[0] << " " << dvector1[dvector1.size() - 1] << endl;

    //9.14
    list<const char *> slist = {"hello", "world", "!"};
    vector<string> svec;

    svec.assign(slist.begin(), slist.end());

    cout << svec.capacity() << " " << svec.size() << " " << svec[0] << " " << svec[svec.size() - 1] << endl;
}

int main()
{
    vector<int> ilist = {1,2,3,4,5,6,7};

    //6中创建vector对象的方法
    vector<int> ilist1;         //为空
    vector<int> ilist2(ilist1); //初始化为ilist1的拷贝
    vector<int> ilist3 = {1,2,3};
    vector<int> ilist4(ilist3.begin(), ilist3.end());
    vector<int> ilist5(7);
    vector<int> ilist6(7, 2);

    test_container();

    cout << search_vec(ilist.begin(), ilist.end(), 3) << endl;
    cout << search_vec(ilist.begin(), ilist.end(), 8) << endl;

    cout << search_vec_iter(ilist.begin(), ilist.end(), 2) - ilist.begin() << endl;

}