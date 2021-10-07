#include <iostream>
using namespace std;

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode {
    int Data;
    BinTree Left;
    BinTree Right;
};

Position find(int x, BinTree BST);
Position findMin(BinTree BST);
Position findMax(BinTree BST);
BinTree insertNode(int x, BinTree BST);
BinTree deleteNode(int x, BinTree BST);

int main() {


    return 0;
}

Position find(int x, BinTree BST) {
    if (!BST) return NULL;
    if (BST->Data > x) {
        return find(x, BST->Left);
    } else if (BST->Data < x) {
        return find(x, BST->Right);
    } else {
        return BST;
    }
}

Position findMin(BinTree BST) {
    if (!BST) {
        return NULL;
    } else if (!BST->Left) {
        return BST;
    } else {
        return findMin(BST->Left);
    }
}

Position findMax(BinTree BST) {
    if (BST) {
        while(BST->Right) BST = BST->Right;
    }
    return BST;
}

BinTree insertNode(int x, BinTree BST) {
    if (!BST) {
        BST = (BinTree)malloc(sizeof(TreeNode));
        BST->Data = x;
        BST->Left = NULL;
        BST->Right = NULL;
    } else {
        if (BST->Data < x) {
            insertNode(x, BST->Right);
        } else {
            insertNode(x, BST->Left);
        }
    }
    return BST;
}

BinTree deleteNode(int x, BinTree BST) {
    Position tmp;
    if (!BST) cout << "The node doesn't exists." << endl;
    else if (BST->Data < x) {
        BST->Right = deleteNode(x, BST->Right);
    } else if (BST->Data > x) {
        BST->Left = deleteNode(x, BST->Left);
    } else {
        if (BST->Left && BST->Right) {
            tmp = findMin(BST->Right);
            BST->Data = tmp->Data;
            BST->Right = deleteNode(BST->Data, BST->Right);
        } else {
            tmp = BST;
            if (!BST->Left) {
                BST = BST->Right;
            } else if (!BST->Right) {
                BST = BST->Left;
            }
            free(tmp);
        }
    }
}