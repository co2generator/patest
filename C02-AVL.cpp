#include <iostream>
using namespace std;

typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode {
    int Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

int getHeight(AVLTree root);
AVLTree insert(AVLTree root, int data);
AVLTree rightRightRotation(AVLTree root);
AVLTree leftLeftRotation(AVLTree root);
AVLTree rightLeftRotation(AVLTree root);
AVLTree leftRightRotation(AVLTree root);

int getHeight(AVLTree root) {
    if (!root) return -1;
    return root->Height;
}

AVLTree insert(AVLTree root, int data) {
    if (!root) {
        root = new AVLNode();
        root->Data = data;
        root->Left = NULL;
        root->Right = NULL;
        root->Height = 0;
    } else if (root->Data > data) {
        root->Left = insert(root->Left, data);
        if (getHeight(root->Left) - getHeight(root->Right) == 2) {
            if (data < root->Left->Data) root = leftLeftRotation(root);
            else root = leftRightRotation(root);
        }
    } else if (root->Data < data) {
        root->Right = insert(root->Right, data);
        if (getHeight(root->Left) - getHeight(root->Right) == -2) {
            if (data < root->Right->Data) root = rightRightRotation(root);
            else root = rightLeftRotation(root);
        }
    }
    root->Height = max(getHeight(root->Left), getHeight(root->Right)) + 1;
    return root;
}

AVLTree rightRightRotation(AVLTree root) {
    AVLTree tmp = root->Right;
    root->Right = tmp->Left;
    tmp->Left = root;
    root->Height = max(getHeight(root->Left), getHeight(root->Right)) + 1;
    tmp->Height = max(getHeight(tmp->Left), getHeight(tmp->Right)) + 1;
    return tmp;
}

AVLTree leftLeftRotation(AVLTree root) {
    AVLTree tmp = root->Left;
    root->Left = tmp->Right;
    tmp->Right = root;
    root->Height = max(getHeight(root->Left), getHeight(root->Right)) + 1;
    tmp->Height = max(getHeight(tmp->Left), getHeight(tmp->Right)) + 1;
    return tmp;
}

AVLTree rightLeftRotation(AVLTree root) {
    AVLTree tmp = root->Right;
    root->Right = rightRightRotation(tmp);
    return leftLeftRotation(root);
}

AVLTree leftRightRotation(AVLTree root) {
    AVLTree tmp = root->Left;
    root->Left = leftLeftRotation(tmp);
    return rightRightRotation(root);
}