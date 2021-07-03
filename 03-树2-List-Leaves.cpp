#include <iostream>
#include <vector>
#include <queue>
#define MAX 10
using namespace std;

struct tree {
    int left;
    int right;
} T[MAX];

vector<int> leaves;

int createTree(tree T[]);

void listLeaves(int node);

int main() {
    int root = createTree(T);
    listLeaves(root);
    for (int i = 0; i < leaves.size(); ++i) {
        if (i == 0) {
            cout << leaves[i];
        } else {
            cout << " " << leaves[i];
        }
    }
    return 0;
}

int createTree(tree T[]) {
    int n, root = -1, check[MAX] = {0};
    cin >> n;
    if (n) {
        char left, right;
        for (int i = 0; i < n; ++i) {
            cin >> left >> right;
            if (left != '-') {
                T[i].left = left - '0';
                check[T[i].left] = 1;
            } else {
                T[i].left = -1;
            }
            if (right != '-') {
                T[i].right = right - '0';
                check[T[i].right] = 1;
            }  else {
                T[i].right = -1;
            }
        }
        for (int i = 0; i < MAX; ++i) {
            if (check[i] == 0) {
                root = i;
                break;
            }
        }
    }
    return root;
}

void listLeaves(int root) {
    queue<int> q;
    q.push(root);
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        if (T[node].left == -1 && T[node].right == -1) {
            leaves.push_back(node);
        }
        if (T[node].left != -1) {
            q.push(T[node].left);
        } 
        if (T[node].right != -1) {
            q.push(T[node].right);
        }
    }
}