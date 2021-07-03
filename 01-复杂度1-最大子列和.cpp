#include<iostream>
#include<vector>
using namespace std;

int maxSubSeqSum(int left, int right, vector<int>& array);

int main() {
    int num;
    cin >> num;
    vector<int> array(num);
    for (int i = 0; i < num; ++i) {
        cin >> array[i];
    }
    cout << maxSubSeqSum(0, num-1, array) << endl;
    return 0;
}

int maxSubSeqSum(int left, int right, vector<int>& array) {
    if (left == right) return array[left];
    int mid = (left + right) / 2;
    int lmax = maxSubSeqSum(left, mid, array);
    int rmax = maxSubSeqSum(mid+1, right, array);
    
    int lbordermax = array[mid];
    int rbordermax = array[mid+1];
    int sum = 0;
    for (int i = mid; i >= left; --i) {
        sum += array[i];
        if (sum > lbordermax) lbordermax = sum;
    }
    sum = 0;
    for (int i = mid+1; i <= right; ++i) {
        sum += array[i];
        if (sum > rbordermax) rbordermax = sum;
    }

    int ans = (lbordermax + rbordermax) > lmax ? ((lbordermax + rbordermax) > rmax ? (lbordermax + rbordermax) : rmax) : lmax;

    return ans < 0 ? 0 : ans;        
}