#include <iostream>
using namespace std;
#define MAXSIZE 1000

// definition
typedef struct SNode *Stack;
struct SNode {
    int Data[MAXSIZE];
    int Top;
};

// push
void push(Stack PtrS, int item) {
    if (PtrS->Top == MAXSIZE-1) {
        cout << "The stack is full." << endl;
    } else {
        PtrS->Data[++(PtrS->Top)] = item;
        return;
    }
}

// pop
int pop(Stack PtrS) {
    if (PtrS->Top == -1) {
        cout << "The stack is null." << endl;
    } else {
        return (PtrS->Data[(PtrS->Top)--]);
    }
}

