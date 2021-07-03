#include<iostream>
#include<vector>
using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> array(num);
    for (int i = 0; i < num; ++i) {
        cin >> array[i];
    }

    // find maximum
    bool flag = true;
    int maximum = -1, current = 0, tmpLeft = 0, l = 0, r = num-1;
    for (int i = 0; i < num; ++i) {
        if (array[i] >= 0) flag = false;
        current += array[i];
        if (current < 0) {
            current = 0;
            tmpLeft = i+1;
        } else if (current > maximum) {
            maximum = current; 
            l = tmpLeft;
            r = i;
        } 
    }
    if (maximum < 0 && flag) {
        cout << "0 " << array[0] << " " << array[num-1];
    } else {
        cout << maximum << " " << array[l] << " " << array[r];
    }
    return 0;
}