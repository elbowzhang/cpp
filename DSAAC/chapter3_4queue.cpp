#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct QueneRecord *Quene;
#define MinQueneSize (5)

struct QueneRecord{
    int capacity;
    int front;
    int rear;
    int size;
    ElementType *array;
};

bool isEmpty(Quene q)
{
    return q->size == 0;
}

bool isFull(Quene q)
{
    return q->size == q->capacity;
}

void makeEmpty(Quene q)
{
    q->size = 0;
    q->front = 1;
    q->rear = 0;
}

Quene createQuene(int queneSize)
{
    Quene q = (Quene)malloc(sizeof(Quene));
    if(q == NULL){
        cout << "out of space";
        return NULL;
    }

    q->array = (ElementType*)malloc(sizeof(ElementType) * queneSize);
    if(q->array == NULL)
    {
        cout << "out of space";
        return NULL;
    }

    q->capacity = queneSize;
    makeEmpty(q);
    return q;
}

void disposeQuene(Quene q)
{
    if(q != NULL)
    {
        free(q->array);
        free(q);
    }
}

static int succ(int value, Quene q)
{
    if(++value == q->capacity)
        value = 0;
    return value;
}

void enquene(ElementType e, Quene q)
{
    if(isFull(q))
    {
        cout << "quene full";
        return;
    }
    else{
        q->size ++;
        q->rear = succ(q->rear, q);
        q->array[q->rear] = e;
    }
}

ElementType front(Quene q)
{
    return q->array[q->front];
}

void dequene(Quene q)
{
    if(isEmpty(q))
    {
        cout << "empty quene";
        return;
    }
    else
    {
        q->size--;
        if(q->rear == 0)
        {
            q->rear = q->size - 1;
        }
        else
            q->rear--;
    }
}

int main()
{

}