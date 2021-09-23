#include <iostream>
using namespace std;

// definition
struct Node {
    int Data;
    struct Node *Next;
};
struct QNode {
    struct Node *front;
    struct Node *rear;
};
typedef struct QNode *Queue;

// add queue
void addQueue(Queue ptrQ, int item) {
    Node *tmp = (Node*)malloc(sizeof(struct Node));
    tmp->Data = item;
    ptrQ->rear->Next = tmp;
    ptrQ->rear = ptrQ->rear->Next;
}


// delete queue
int deleteQueue(Queue ptrQ) {
    if (ptrQ->front == NULL) {
        cout << "The queue is null." << endl;
        return NULL; 
    }
    struct Node *frontItem = ptrQ->front;
    if (ptrQ->front == ptrQ->rear) {
        ptrQ->front = ptrQ->rear = NULL;
    } else {
        ptrQ->front = ptrQ->front->Next;
    }
    int frontValue = frontItem->Data;
    free(frontItem);
    return frontValue;
}