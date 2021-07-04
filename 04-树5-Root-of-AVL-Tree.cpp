#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
    int value;
    node* left;
    node* right;
} node;

node* createTree(int value, node* head);

int main() {
    int N;
    cin >> N;
    node* tree = NULL;
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        tree = createTree(value, tree);
    }
    return 0;
}

node* createTree(int value, node* head) {
    if (head == NULL) {
        node* temp = new node();
        temp->value = value;
        temp->left = NULL;
        temp->right = NULL;
    }
    if (head->value > value) {
        head = createTree(value, head->left);
    }
    if (head->value < value) {
        head = createTree(value, head->right);
    }
    return head;
}