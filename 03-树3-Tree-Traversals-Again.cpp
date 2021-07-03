/**
 * Please refer https://blog.csdn.net/shinanhualiu/article/details/49279051
 * 
 * niubility!
 * 
 */
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void getPreAndIn(int N, vector<int>& pre, vector<int>& in);

void getPost(vector<int>& pre, int prePos, vector<int>& in, int inPos, vector<int>& post, int postPos, int n);

int main() {
    int N;
    cin >> N;
    vector<int> pre(N, 0);
    vector<int> in(N, 0);
    vector<int> post(N, 0);
    getPreAndIn(N, pre, in);
    getPost(pre, 0, in, 0, post, 0, N);
    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            cout << post[i];
        } else {
            cout << " " << post[i];
        }
    }
    return 0;
}

void getPreAndIn(int N, vector<int>& pre, vector<int>& in) {
    int indexPre = 0, indexIn = 0;
    stack<int> s;
    for (int i = 0; i < 2*N; ++i) {
        string str;
        int tmp;
        cin >> str;
        if (str == "Push") {
            cin >> tmp;
            s.push(tmp);
            pre[indexPre++] = tmp;
        } else if (str == "Pop") {
            tmp = s.top();
            in[indexIn++] = tmp;
            s.pop();
        }
    }
}

void getPost(vector<int>& pre, int prePos, vector<int>& in, int inPos, vector<int>& post, int postPos, int n) {
    if (n == 0) return;
    if (n == 1) {
        post[postPos] = pre[prePos];
        return;
    }
    auto root = pre[prePos];
    post[postPos + n - 1] = root;
    //在中序遍历数组上找出root的位置
    int i = 0;
    while (i < n) {
        if (in[inPos + i] == root) break;
        ++i;
    }
    // 计算出root节点左右子树节点的个数
    int L = i, R = n - i - 1;
    // 递归的进行求解
    getPost(pre, prePos+1, in, inPos, post, postPos, L);
    getPost(pre, prePos + L + 1, in, inPos + L + 1, post, postPos + L, R);
}