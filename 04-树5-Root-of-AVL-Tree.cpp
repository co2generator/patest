#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
    int value;
    node* left;
    node* right;
    int height;
} node;

int getHeight(node* node);
node* insertNode(int value, node* head);
node* singleLeftRotate(node* head);
node* singleRightRotate(node* head);
node* leftRightRotate(node* head);
node* rightLeftRotate(node* head);

int main() {
    int N;
    cin >> N;
    node* tree = NULL;
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        tree = insertNode(value, tree);
    }
    cout << tree->value << endl;
    return 0;
}

int getHeight(node* head) {
    if (head == NULL) return 0;
    return max(getHeight(head->left), getHeight(head->right)) + 1;
}

node* singleLeftRotate(node* head) {
    node* tmp = head->left;  
    head->left = tmp->right;  
    tmp->right = head;  
    head->height = max(getHeight(head->left),getHeight(head->right))+1;  
    tmp->height = max(getHeight(tmp->left), head->height)+1;  
    return tmp;  
}

node* singleRightRotate(node* head) {
    node* tmp = head->right;  
    head->right = tmp->left;  
    tmp->left = head;  
    head->height = max(getHeight(head->left), getHeight(head->right)) + 1;  
    tmp->height = max(getHeight(tmp->right), head->height) + 1;  
    return tmp;
}

node* leftRightRotate(node* head) {
    head->left = singleRightRotate(head->left);
    return singleLeftRotate(head);
}

node* rightLeftRotate(node* head) {
    head->right = singleLeftRotate(head->right);
    return singleRightRotate(head);
}

node* insertNode(int value, node* head) {
    if (head == NULL) {
        node* temp = new node();
        temp->value = value;
        temp->left = NULL; 
        temp->right = NULL;
        temp->height = 0;
    } else if (value < head->value) {
        head->left = insertNode(value, head->left);
        if (getHeight(head->left) - getHeight(head->right) == 2) {
            if (value < head->left->value) {
                head = singleLeftRotate(head);
            } else {
                head = leftRightRotate(head);
            }
        }
    } else if (value > head->value) {
        head->right = insertNode(value, head->right);
        if (getHeight(head->right) - getHeight(head->left) == 2) {
            if (value > head->value) {
                head = singleRightRotate(head);
            } else {
                head = rightLeftRotate(head);
            }
        }
    }
    head->height = max(getHeight(head->left), getHeight(head->right)) + 1;
    return head;
}