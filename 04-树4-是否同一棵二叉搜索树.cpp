#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
    int value;
    node* left;
    node* right;
    bool isVisit;
} node;

void inorder(node* head);

node* createTree(int value, node* head);

void reset(node* head);

bool compare(int value, node* head);

int main() {
    int N, L;
    vector<string> answer;
    while (true) {
        cin >> N;
        if (N == 0) break;
        cin >> L;
        node* tree = NULL;
        for (int i = 0; i < N; ++i) {
            int v;
            cin >> v;
            tree = createTree(v, tree);
        }
        for (int i = 0; i < L; ++i) {
            bool flag = true;
            for (int j = 0; j < N; ++j) {
                int v;
                cin >> v;
                if (!compare(v, tree)) {
                    flag = false;
                }
            }
            reset(tree);
            if (flag) {
                answer.push_back("YES");
            } else {
                answer.push_back("NO");
            }
        }
    }

    int num = answer.size();
    for (int i = 0; i < num; ++i) {
        cout << answer[i];
        if (i < (num-1)) {
            cout << endl;
        }
    }
    return 0;
}

void inorder(node* head) {
    if (head == NULL) return;
    cout << head->value << endl;
    inorder(head->left);
    inorder(head->right);
}

node* createTree(int value, node* head) {
    if (head == NULL) {
        node* tmp = new node();
        tmp->value = value;
        tmp->left = NULL;
        tmp->right = NULL;
        tmp->isVisit = false;
        return tmp;
    }
    if (value > head->value) {
        head->right = createTree(value, head->right);
    } else {
        head->left = createTree(value, head->left);
    }
    return head;
}

void reset(node* head) {
    if (head->left != NULL) {
        reset(head->left);
    }
    if (head->right != NULL) {
        reset(head->right);
    }
    head->isVisit = false;
}

bool compare(int value, node* head) {
    if (head->isVisit) { 
		if(value < head->value) return compare(value, head->left);
		else return compare(value, head->right);
	}
	else {
		if (head->value == value) {
			head->isVisit = true;
			return true;
		}
		else return false;
	}
}
