#include<iostream>
using namespace std;

typedef struct LNode *List;
struct LNode {
    int Data;
    List Next;
};

// length
int getLength(List PtrL) {
    List p = PtrL;
    int len = 0;
    while (p != NULL) {
        p = p->Next;
        len++;
    }
    return len;
}

// find kth
List findKth(int K, List PtrL) {
    List p = PtrL;
    int i = 1;
    while (p != NULL && i < K) {
        p = p->Next;
        i++;
    }
    if (i == K) return p;
    else return NULL;
}

// insertion
List insertion(int X, int i, List PtrL) {
    List p, s;
    if (i == 1) {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = PtrL;
        return s;
    }
    p = findKth(i - 1, PtrL);
    if (p == NULL) {
        cout << "i is wrong.";
        return PtrL;
    } else {
        s = (List)malloc(sizeof(struct LNode));
        s->Data = X;
        s->Next = p->Next;
        p->Next = s;
        return PtrL;
    }
}

// deletion, delete the ith item
List deleteItem(int i, List PtrL) {
    List p, s;
    if (i == 1) {
        s = PtrL;
        if (PtrL != NULL) PtrL = PtrL->Next;
        else return NULL;
        free(s);
        return PtrL;
    }
    p = findKth(i - 1, PtrL);
    if (p == NULL) {
        cout << i-1 << "th element is not exists.";
        return NULL;
    } else if (p->Next == NULL) {
        cout << i << "th element is not exists.";
        return NULL;
    } else {
        s = p->Next;
        p->Next = s->Next;
        free(s);
        return PtrL;
    }
}








int main() {

    return 0;
}