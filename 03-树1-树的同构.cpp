#include<iostream>
#define MAX 10
using namespace std;

struct tree {
	char data;
	int left;
	int right;
} T1[MAX],T2[MAX];

int createTree(tree T[]);
bool ismorphic(int t1, int t2);

int main() {
    int t1 = createTree(T1);
    int t2 = createTree(T2);
    if (ismorphic(t1, t2)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}

int createTree(tree T[]) {
    int n, root = -1, check[MAX] = {0};
    cin >> n;
    char left, right;
    if (n) {
        for (int i = 0; i < n; ++i) {
            cin >> T[i].data >> left >> right;
            if (left != '-') {
                T[i].left = left - '0';
                check[T[i].left] = 1;
            } else {
                T[i].left = -1;
            }
            if (right != '-') {
                T[i].right = right - '0';
                check[T[i].right] = 1;
            } else {
                T[i].right = -1;
            }
        }
        for (int i = 0; i < MAX; ++i) {
            if (check[i] == 0){
                root = i;
                break;
            }
        }
    }

    return root;
}

bool ismorphic(int t1, int t2) {
    // 两棵树均为空
    if (t1 == -1 && t2 == -1) return true;
    // 一棵为空
    if ((t1 != -1 && t2 == -1) || (t1 == -1 && t2 != -1)) return false;
    // 根节点值不同
    if (T1[t1].data != T2[t2].data) return false;
    // 左子树均为空
    if (T1[t1].left == -1 && T2[t2].left == -1) {
        return ismorphic(T1[t1].right, T2[t2].right);
    }
    // 左子树均不为空，且值相等
    if ((T1[t1].left != -1 && T2[t2].left != -1) && (T1[T1[t1].left].data == T2[T2[t2].left].data)) {
        return ismorphic(T1[t1].left, T2[t2].left) && ismorphic(T1[t1].right, T2[t2].right);
    } else {
        // 左子树有为空 或者 左子树根节点值不相同
        return ismorphic(T1[t1].left, T2[t2].right) && ismorphic(T1[t1].right, T2[t2].left);
    }
}