#include <iostream>
using namespace std;
#define MAXSIZE 1000

// definition
typedef struct LNode *List;
struct LNode {
    int Data[MAXSIZE];
    int Last;
};

// initilize
List makeEmpty() {
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL->Last = -1;
    return PtrL;
}

// find
int find(int X, List PtrL) {
    int i = 0;
    while (i <= PtrL->Last && PtrL->Data[i] != X) {
        ++i;
    }
    if (i > PtrL->Last) return -1;
    else return i;
}

// insertion
void insert(int X, int i, List PtrL) {
    if (PtrL->Last == MAXSIZE-1) {
        cout << "List is full, insertion failed.";
        return;
    }
    if (i < 1 || i > PtrL->Last+2) {
        cout << "Position is invalid.";
        return;
    }
    for (int j = PtrL->Last; j >= i-1; j--) {
        PtrL->Data[j+1] = PtrL->Data[j];
    }
    PtrL->Data[i-1] = X;
    PtrL->Last++;
    return;
}

// deletion
void deleteItem(int i, List PtrL) {
    if (i < 1 || i > PtrL->Last+1) {
        cout << "The" << i << "th element not exists.";
        return;
    }
    for (int j = i; j <= PtrL->Last; j++) {
        PtrL->Data[j-1] = PtrL->Data[j];
    }
    PtrL->Last--;
    return;
}

int main() {

    return 0;
}