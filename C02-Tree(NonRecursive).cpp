#include <iostream>
#include <queue>
#include <stack>
using namespace std;

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
    int Data;
    BinTree Left;
    BinTree Right;
};


// Pre Order Traversal
void preOrderTraversal(BinTree BT) {
    BinTree T = BT;
    stack<BinTree> s;
    while (T || !s.empty()) {
        while (T) {
            cout << T->Data << endl;
            s.push(T);
            T = T->Left;
        }
        if (!s.empty()) {
            T = s.top();
            s.pop();
            T = T->Right;
        }
    }
}

// In Order Traversal
void inOrderTraversal(BinTree BT) {
    BinTree T = BT;
    stack<BinTree> s;
    while (T || !s.empty()) {
        while (T) {
            s.push(T);
            T = T->Left;
        }
        if (!s.empty()) {
            T = s.top();
            s.pop();
            cout << T->Data << endl;
            T = T->Right;
        }
    }
}

// Post Order Traversal
void preOrderTraversal(BinTree BT) {
    BinTree T = BT;
    stack<BinTree> s;
    stack<BinTree> s2;
    while (T || !s.empty()) {
        while (T) {
            s2.push(T);
            s.push(T);
            T = T->Right;
        }
        if (!s.empty()) {
            T = s.top();
            s.pop();
            T = T->Left;
        }
    }
    while (!s2.empty()) {
        T = s2.top();
        cout << T->Data << endl;
        s2.pop();
    }
}

// Level Order Traversal
void levelOrderTraversal(BinTree BT) {
    queue<BinTree> q;
    BinTree T;
    if (!BT) return;
    q.push(BT);
    while (!q.empty()) {
        T = q.front();
        q.pop();
        cout << T->Data << endl;
        if (T->Left) q.push(T->Left);
        if (T->Right) q.push(T->Right);
    } 
}