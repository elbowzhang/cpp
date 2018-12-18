#ifndef _LIST_H_
#define _LIST_H_

struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

//list
struct Node
{
    ElementType Element;
    Position Next;
};

List makeEmpty(List L);
int isEmpty(List L);
int isLast(Position P, List L);
Position find(ElementType e, List L);
void deleteFromList(ElementType e, List L);
Position findPrevious(ElementType e, List L);
void insertToList(ElementType e, List L, Position p);
void deleteList(List L);
Position header(List L);
Position first(List L);
Position advance(Position p);
ElementType retrieve(Position p);
void printList(List L);

#endif