#include <iostream>
#include <vector>
using namespace std;

void insert(vector<int>& minHeap, int size, int item);
void printRoute(vector<int>& minHeap, int index);

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> minHeap(N+1, 0);
    minHeap[0] = -10001;
    for (int i = 1; i <= N; i++) {
        int item;
        cin >> item;
        insert(minHeap, i-1, item);
    }
    // build minHeap
    for (int i = 0; i < M; i++) {
        int index;
        cin >> index;
        printRoute(minHeap, index);
        cout << "\n";
    }
    
    return 0;
}

void insert(vector<int>& minHeap, int size, int item) {
    int i = size;
    ++i;
    for ( ; minHeap[i / 2] > item; i /= 2) {
        minHeap[i] = minHeap[i / 2];
    }
    minHeap[i] = item;
}

void printRoute(vector<int>& minHeap, int index) {
    cout << minHeap[index];
    index /= 2;
    for ( ; index > 0; index /= 2) {
        cout << " " << minHeap[index];
    }
}
