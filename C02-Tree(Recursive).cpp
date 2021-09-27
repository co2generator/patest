#include <iostream>
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
    if (BT) {
        cout << BT->Data << endl;
        preOrderTraversal(BT->Left);
        preOrderTraversal(BT->Right);
    } else {
        cout << "Tree is null." << endl;
    }
}

// In Order Traversal
void inOrderTraversal(BinTree BT) {
    if (BT) {
        inOrderTraversal(BT->Left);
        cout << BT->Data << endl;
        inOrderTraversal(BT->Right);
    } else {
        cout << "Tree is null." << endl;
    }
}

// Post Order Traversal
void postOrderTraversal(BinTree BT) {
    if (BT) {
        postOrderTraversal(BT->Left);
        postOrderTraversal(BT->Right);
        cout << BT->Data << endl;
    } else {
        cout << "Tree is null." << endl;
    }
}
