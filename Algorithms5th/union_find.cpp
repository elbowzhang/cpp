#include <iostream>
#include <vector>
using namespace std;

//基本数据
class UF{
public:
    UF(int N);
    void union1(int p, int q);
    int find(int p);
    bool connected(int p, int q);
    int count();
};

//eager approach 贪婪算法
//使用简单的数组遍历方式实现
//缺点：合并十分浪费时间
class QuickFindUF{
    public:
      QuickFindUF(int N);
      bool connected(int p, int q);
      void union1(int p, int q);

    private:
      vector<int> id;
};

QuickFindUF::QuickFindUF(int N)
{
    for (int i = 0; i < N; i++)
    {
        id.push_back(i);
    }
}

bool QuickFindUF::connected(int p, int q)
{
    return id[p] == id[q];
}

void QuickFindUF::union1(int p, int q)
{
    int pid = id[p];
    int qid = id[q];

    for (int i = 0; i < id.size(); i++)
    {
        if(id[i] == pid)
            id[i] = qid;
    }
}

//lazy approach     懒惰算法    快速合并算法
//使用树结构实现
//缺点：树可能过高，此时查找操作十分浪费时间
class QuickUnionUF{
    public:
      QuickUnionUF(int N);
      bool connected(int p, int q);
      void union1(int p, int q);

    private:
      vector<int> id;
      int root(int i);      //设为私有函数
};

QuickUnionUF::QuickUnionUF(int N)
{
    for(int i = 0; i < N; i++)
    {
        id.push_back(i);
    }
}

int QuickUnionUF::root(int i)
{
    while(i != id[i]){
        i = id[i];
    }
    return i;
}

bool QuickUnionUF::connected(int p, int q)
{
    return root(p) == root(q);
}

void QuickUnionUF::union1(int p, int q)
{
    id[root(p)] = root(q);
}

//加权下的快速合并算法
//1，避开创建出过高的树
//2，保持每棵树的大小（对象数）
//3，将小树连接到大树下面（有效控制树的高度）
class QuickUnionUFWithWeighting{
    public:
      QuickUnionUFWithWeighting(int N);
      bool connected(int p, int q);
      void union1(int p, int q);

    private:
      vector<int> id;
      vector<int> sz;
      int root(int i);      //设为私有函数
};

QuickUnionUFWithWeighting::QuickUnionUFWithWeighting(int N)
{
    for(int i = 0; i < N; i++){
        id.push_back(i);
        sz.push_back(1);
    }
}

int QuickUnionUFWithWeighting::root(int i)
{
    while(i != id[i])       //add path compression, just add one line in while loop
        i = id[i];          //id[i] = id[id[i]];
    return i;
}

bool QuickUnionUFWithWeighting::connected(int p, int q)
{
    return id[p] == id[q];
}

void QuickUnionUFWithWeighting::union1(int p, int q)
{
    int i = root(p);
    int j = root(q);
    if(i == j)
        return;
    if(sz[i] < sz[j])
    {
        id[i] = j;
        sz[j] += sz[i];
    }
    else
    {
        id[j] = i;
        sz[i] += sz[j];
    }
}
