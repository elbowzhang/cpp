#include <iostream>
#include <string>
using namespace std;

#if 0
struct Node;
typedef struct Node *ptrToNode;
typedef ptrToNode Stack;
typedef int ElementType;

struct Node
{
    ElementType element;
    ptrToNode next;
};

int isEmpty(Stack s)
{
    return s->next == NULL;
}

void pop(Stack s)
{
    ptrToNode firstNode;

    if(isEmpty(s)){
        cout << "empty stack";
        return;
    }
    else
    {
        firstNode = s->next;
        s->next = s->next->next;
        free(firstNode);
    }   
}

void makeEmpty(Stack s)
{
    if(s == NULL)
        cout << "must use createStack first";
    else
        while(!isEmpty(s))
            pop(s);
}

Stack createStack()
{
    Stack S;

    S = (Stack)malloc(sizeof(struct Node));
    if(S == NULL)
        cout << "out of space";
    S->next = NULL;
    makeEmpty(S);
    return S;
}

void push(ElementType e, Stack s)
{
    ptrToNode tmpNode;

    tmpNode = (ptrToNode)malloc(sizeof(struct Node));
    if(tmpNode == NULL)
        cout << "out of space";
    else{
        tmpNode->element = e;
        tmpNode->next = s->next;
        s->next = tmpNode;
    }
}

ElementType top(Stack s)
{
    if(!isEmpty(s))
        return s->next->element;
    cout << "empty stack";
    return NULL;
}
#endif

#if 1
struct StackRecord;
typedef char ElementType;
typedef struct StackRecord *Stack;
#define EmptyTOS (-1)
#define FullTOS (99)
#define MinStackSize (5)

struct StackRecord
{
    int capacity;
    int topOfStack;
    ElementType *Array;
};

int isEmpty(Stack S)
{
    return S->topOfStack == EmptyTOS;
}

int isFull(Stack S)
{
    return S->topOfStack == FullTOS;
}

void makeEmpty(Stack S)
{
    S->topOfStack = EmptyTOS;
}

Stack createStack(int stackSize)
{
    Stack S;
    if(stackSize < MinStackSize){
        cout << "stack size too small";
        return NULL;
    }

    S = (Stack)malloc(sizeof(struct StackRecord));
    if(S == NULL)
    {
        cout << "out of space";
        return NULL;
    }

    S->Array = (ElementType *)malloc(sizeof(ElementType) * stackSize);
    if(S->Array == NULL)
    {
        cout << "out of space";
        return NULL;
    }

    S->capacity = stackSize;
    makeEmpty(S);
    return S;
}

//释放栈
void disposeStack(Stack S)
{
    if(S != NULL)
    {
        free(S->Array);
        free(S);
    }
}

void push(ElementType e, Stack S)
{
    if(isFull(S))
    {
        cout << "full stack";
        return;
    }
    else
        S->Array[++S->topOfStack] = e;
}

void pop(Stack S)
{
    if(isEmpty(S)){
        cout << "empty stack";
        return;
    }
    else
        S->topOfStack--;
}

ElementType top(Stack S)
{
    if(isEmpty(S))
    {
        cout << "empty stack";
        return NULL;
    }
    else
        return S->Array[S->topOfStack];
}

ElementType topAndpop(Stack S)
{
    if(isEmpty(S))
    {
        cout << "empty Stack";
        return NULL;
    }
    else
        return S->Array[S->topOfStack--];
}

#endif

//平衡符号例程
bool isLeagal(string &s, Stack stack)
{
    for(auto c:s)
    {
        if(c == '{' || c == '(')
            push(c, stack);
        else if(c == ')')
        {
            if(isEmpty(stack))
            {
                cout << "string error";
                return false;
            }
            else
            {
                if (topAndpop(stack) != '(')
                {
                    cout << "error in )";
                    return false;
                }
            }
        }
        else if(c == '}')
        {
            if(isEmpty(stack))
            {
                cout << "string error";
                return false;
            }
            else
            {
                if (topAndpop(stack) != '{')
                {
                    cout << "error in }";
                    return false;
                }
            }
        }
        else
        {}
    }
    if(!isEmpty(stack))
    {
        cout << "error";
        return false;
    }
    return true;
}

bool isLeagalOnline(Stack stack)
{
    char c;
    
    while(cin >> c){
        if(c == '{' || c == '(')
            push(c, stack);
        else if(c == ')')
        {
            if(isEmpty(stack))
            {
                cout << "string error";
                return false;
            }
            else
            {
                if (topAndpop(stack) != '(')
                {
                    cout << "error in )";
                    return false;
                }
            }
        }
        else if(c == '}')
        {
            if(isEmpty(stack))
            {
                cout << "string error";
                return false;
            }
            else
            {
                if (topAndpop(stack) != '{')
                {
                    cout << "error in }";
                    return false;
                }
            }
        }
        else
        {}
    }
    return true;
}

int main()
{
    Stack S = createStack(100);
    string s = "{{{()}}}";
    isLeagal(s, S);
    isLeagalOnline(S);
}