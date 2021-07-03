#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
using namespace std;

struct ListNode {
    int address;
    int value;
    int next;
};

vector<int> createLinkedList(int initialAddr, vector<ListNode>& vec, unordered_map<int, int> add2index);

void printLinkedList(vector<int>& list, vector<ListNode>& vec);

int main() {
    int initialAddr, N, K;
    cin >> initialAddr;
    cin >> N;
    cin >> K;
    vector<struct ListNode> vec;
    unordered_map<int, int> add2index;
    for (int i = 0; i < N; ++i) {
        ListNode node;
        cin >> node.address;
        cin >> node.value;
        cin >> node.next;
        vec.push_back(node);
        add2index[node.address] = i;
    }
    vector<int> list = createLinkedList(initialAddr, vec, add2index);
    int listLength = list.size();
    if (K > listLength/2) {
       reverse(list.begin(), list.begin() + K);
    } else {
        for (int j = 0; j < listLength/K; ++j) {
            int start = j * K, end = start + K;
            reverse(list.begin() + start, list.begin() + end);
        }
    }
    printLinkedList(list, vec);
    return 0;
}

vector<int> createLinkedList(int initialAddr, vector<ListNode>& vec, unordered_map<int, int> add2index) {
    vector<int> index;
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i].address == initialAddr) {
            index.push_back(i);
            break;
        }
    }
    int ii = 0;
    while(vec[index[ii]].next != -1) {
        index.push_back(add2index[vec[index[ii]].next]);
        ++ii;
    }
    return index;
}

void printLinkedList(vector<int>& list, vector<ListNode>& vec) {
    int length = list.size();
    for (int i = 0; i < length; ++i) {
        if (i < length-1) {
            vec[list[i]].next = vec[list[i+1]].address;
            cout << setfill('0') << setw(5) << vec[list[i]].address << " " << vec[list[i]].value << " " << setfill('0') << setw(5) << vec[list[i]].next << endl;
        } else {
            vec[list[i]].next = -1;
            cout << setfill('0') << setw(5) << vec[list[i]].address << " " << vec[list[i]].value << " " << vec[list[i]].next << endl;
        }
        
    }
}