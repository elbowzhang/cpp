#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct BinaryTreeNode *ptrToNode;
typedef ptrToNode BinaryTree;
typedef BinaryTree SearchTree;
typedef ptrToNode Position;

struct BinaryTreeNode
{
    ElementType Element;
    BinaryTree LeftChild;
    BinaryTree RightChild;
};

//建立一颗空树
SearchTree makeEmpty(SearchTree T)
{
    if(T != NULL)
    {
        makeEmpty(T->LeftChild);
        makeEmpty(T->RightChild);
        free(T);
    }
    return NULL;
}

//在查找树中查找某个数值的操作是很快速的
Position find(ElementType e, SearchTree T)
{
    if(T == NULL)
        return NULL;
    if(e < T->Element)
        return find(e, T->LeftChild);
    else if(e > T->Element)
        return find(e, T->RightChild);
    else
        return T;
}

//在查找树中寻找最小的值，递归实现
Position findMin(SearchTree T)
{
    if(T == NULL)
        return NULL;
    else if(T->LeftChild == NULL)
        return T;
    else
        return findMin(T->LeftChild);
}

//在查找树中寻找最大的值，非递归实现
Position findMax(SearchTree T)
{
    if(T != NULL)
    {
        while(T->RightChild != NULL)
            T = T->RightChild;
    }
    return T;
}

//将一个元插入到查找树中
SearchTree insert(ElementType e, SearchTree T)
{
    if(T == NULL)
    {
        T = (SearchTree)malloc(sizeof(struct BinaryTreeNode));
        if(T == NULL)
        {
            cout << "out of space";
            return NULL;
        }
        else
        {
            T->Element = e;
            T->LeftChild = T->RightChild = NULL;
        }
    }
    else if(e < T->Element)     //插入到左孩子树上
    {
        T->LeftChild = insert(e, T->LeftChild);
    }
    else if(e > T->Element)
    {
        T->RightChild = insert(e, T->RightChild);
    }
    else
        ;   //e已经存在于树中，什么都不做
    return T;
}

//从查找树中删除一个元素
SearchTree deleteNode(ElementType e, SearchTree T)
{
    Position tmpNode;
    if(T == NULL)
    {
        cout << "element not found";
        return NULL;
    }
    else if(e < T->Element)
    {
        T->LeftChild = deleteNode (e, T->LeftChild);
    }
    else if(e > T->Element)
    {
        T->RightChild = deleteNode (e, T->RightChild);
    }
    //找到需要删除的元素
    else if(T->LeftChild && T->RightChild)  //有两个孩子
    {
        //使用右子树中最小的元素替换
        tmpNode = findMin(T->RightChild);
        T->Element = tmpNode->Element;
        T->RightChild = deleteNode (T->Element, T->RightChild);
    }
    else//有一个或者0个孩子
    {
        tmpNode = T;
        if(T->LeftChild == NULL)
            T = T->RightChild;
        else if(T->RightChild == NULL)
            T = T->LeftChild;
        free(tmpNode);
    }
    return T;
}

void printElement(ElementType e)
{

}

//遍历树
void printTree(SearchTree T)
{
    if(T != NULL)
    {
        printTree(T->LeftChild);
        printElement(T->Element);
        printTree(T->RightChild);
    }
}

int main()
{

}
