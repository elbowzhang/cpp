#include <iostream>
#include "list.h"
using namespace std;

List makeEmpty(List L)
{
    Position p,tmpNode;
    p = L->Next;
    L->Next = NULL;

    while(p != NULL){
        tmpNode = p->Next;
        free(p);
        p = tmpNode;
    }
    
    return L;
}

//返回列表是否为空
int isEmpty(List L)
{
    return L->Next == NULL;
}

//判断节点是否为最后一个节点
int isLast(Position p, List L)
{
    return p->Next == NULL;
}

//在list中寻找节点
Position find(ElementType e, List L)
{
    Position p;

    p = L->Next;
    
    while(p != NULL && p->Element != e){
        p = p->Next;
    }

    return p;
}

//寻找节点的前驱节点
Position findPrevious(ElementType e, List L)
{
    Position p;
    p = L;
    
    while(p->Next != NULL && p->Next->Element != e){
        p = p->Next;
    }
    return p;
}

//在list中删除元素第一次出现的节点
void deleteFromList(ElementType e, List L)
{
    Position p,tmpNode;
    p = findPrevious(e, L);

    if(!isLast(p,L))
    {
        tmpNode = p->Next;
        p->Next = tmpNode->Next;
        free(tmpNode);
    }
}

//在P之后插入新元素
void insertToList(ElementType e, List L, Position p)
{
    Position tmpNode;
    tmpNode = (Position)malloc(sizeof(struct Node));
    if(tmpNode == NULL)
        cout << "out of space";

    tmpNode->Element = e;
    tmpNode->Next = p->Next;
    p->Next = tmpNode;
}

void deleteList(List L)
{
    Position p, tmpNode;

    p = L->Next;
    L->Next = NULL;

    while(p != NULL){
        tmpNode = p->Next;
        free(p);
        p = tmpNode;
    }
}

void printList(List L)
{
    Position p;
    p = L->Next;

    while(p != NULL){
        cout << p->Element << " ";
        p = p->Next;
    }
    cout << endl;
}



int main()
{

}