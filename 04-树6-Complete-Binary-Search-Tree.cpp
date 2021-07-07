#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[1005];
int answer[1005];

int getLeftTreeLength(int n);

void solve(int left, int right, int root);

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+N);
    solve(0, N-1, 0);
    for (int i = 0; i < N; ++i) {
        if (i != 0) cout << " ";
        cout << answer[i];
    }
    return 0;
}

int getLeftTreeLength(int n) {
    int H = (int) log2(n+1);
    int X = min(n - pow(2, H) + 1, pow(2, H-1));
    int L = pow(2, H-1) - 1 + X;
    return L;
}

void solve(int left, int right, int root) {
    int n = right - left + 1;
    if (n == 0) return;
    int L = getLeftTreeLength(n);
    answer[root] = arr[left + L];
    int leftRoot = 2 * root + 1;
    int rightRoot = leftRoot + 1;
    solve(left, left+L-1, leftRoot);
    solve(left+L+1, right, rightRoot);
}