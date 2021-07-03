#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void checkSequence(int N, int M, int begin, int end, vector<int>& inputSeq) {
    int num = 1, pos = begin;
    stack<int> s;
    s.push(num);
    while (num <= N && s.size() <= M) {
        if (!s.empty() && s.top() == inputSeq[pos]) {
            s.pop();
            ++pos;
        } else {
            ++num;
            s.push(num);
        }
    }
    if (pos == end+1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}


int main() {
    int M, N, K;
    cin >> M >> N >> K;
    vector<int> inputSeq(K*N);
    int index = 0;
    for (int k = 0; k < K; ++k) {
        for (int n = 0; n < N; ++n) {
            cin >> inputSeq[index];
            ++index;
        }
    }
    for (int k = 0; k < K; ++k) {
        checkSequence(N, M, k * N, k * N + N-1, inputSeq);
    }
    return 0;
}