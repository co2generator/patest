#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void polyMultipy(vector<int>& poly1_coef, vector<int>& poly1_exp, vector<int>& poly2_coef, vector<int>& poly2_exp);

void polySum(vector<int>& poly1_coef, vector<int>& poly1_exp, vector<int>& poly2_coef, vector<int>& poly2_exp);

void printPoly(unordered_map<int, int>& newPoly);

int main() {
    vector<int> poly1_coef, poly1_exp, poly2_coef, poly2_exp;
    int num1 = 0, num2 = 0;
    cin >> num1;
    for (int i = 0; i < num1; ++i) {
        int coef, exp;
        cin >> coef >> exp;
        poly1_coef.push_back(coef);
        poly1_exp.push_back(exp);
    }
    cin >> num2;
    for (int i = 0; i < num2; ++i) {
        int coef, exp;
        cin >> coef >> exp;
        poly2_coef.push_back(coef);
        poly2_exp.push_back(exp);
    }
    
    polyMultipy(poly1_coef, poly1_exp, poly2_coef, poly2_exp);
    cout << endl;
    polySum(poly1_coef, poly1_exp, poly2_coef, poly2_exp);
    
    return 0;
}

void polyMultipy(vector<int>& poly1_coef, vector<int>& poly1_exp, vector<int>& poly2_coef, vector<int>& poly2_exp) {
    int num1 = poly1_coef.size();
    int num2 = poly2_coef.size();
    unordered_map<int, int> newPoly;
    for (int i = 0; i < num1; ++i) {
        for (int j = 0; j < num2; ++j) {
            int coef = poly1_coef[i] * poly2_coef[j];
            int exp = poly1_exp[i] + poly2_exp[j];
            newPoly[exp] += coef;
        }
    }
    printPoly(newPoly);
}

void polySum(vector<int>& poly1_coef, vector<int>& poly1_exp, vector<int>& poly2_coef, vector<int>& poly2_exp) {
    int num1 = poly1_coef.size();
    int num2 = poly2_coef.size();
    unordered_map<int, int> newPoly;
    for (int i = 0; i < num1; ++i) {
        newPoly[poly1_exp[i]] += poly1_coef[i];
    }
    for (int i = 0; i < num2; ++i) {
        newPoly[poly2_exp[i]] += poly2_coef[i];
    }
    printPoly(newPoly);
}

void printPoly(unordered_map<int, int>& newPoly) {
    vector<int> expArray;
    for (auto& kv : newPoly) {
        expArray.push_back(kv.first);
    }
    sort(expArray.rbegin(), expArray.rend());
    bool flag = true;
    for (int i = 0; i < expArray.size(); ++i) {
        if (newPoly[expArray[i]] != 0) {
            flag = false;
            if (i == 0) {
                cout << newPoly[expArray[i]] << " " << expArray[i];
            } else {
                cout << " " << newPoly[expArray[i]] << " " << expArray[i];
            }
        } 
    }
    if (flag) cout << "0 0";
}