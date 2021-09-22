#include <iostream>
using namespace std;

typedef struct SNode *Stack;
struct SNode {
    int Data;
    struct SNode *Next;
};

// initialize 
Stack createStack() {
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

// is empty stack
int isEmpty(Stack S) {
    return S->Next == NULL;
} 

// push
void push(int item, Stack S) {
    struct SNode *tmp;
    tmp = (struct SNode *)malloc(sizeof(struct SNode));
    tmp->Data = item;
    tmp->Next = S->Next;
    S->Next = tmp;
}

// pop
int pop(Stack S) {
    if (isEmpty(S)) {
        cout << "The stack is null." << endl;
    } else {
        struct SNode *firstItem;
        firstItem = S->Next;
        S->Next = firstItem->Next;
        int topData = firstItem->Data;
        free(firstItem);
        return topData;
    }
}

