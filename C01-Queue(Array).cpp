#include <iostream>
using namespace std;
#define MAXSIZE 1000

// definition
struct QNode {
    int Data[MAXSIZE];
    int rear;
    int front;
};
typedef struct QNode *Queue;

// add queue
void addQueue(Queue ptrQ, int item) {
    if ((ptrQ->rear+1)%MAXSIZE == ptrQ->front) {
        cout << "The queue is full." << endl;
        return;
    }
    ptrQ->rear = (ptrQ->rear+1)%MAXSIZE;
    ptrQ->Data[ptrQ->rear] = item;
}

// delete queue
int deleteQueue(Queue ptrQ) {
    if (ptrQ->front == ptrQ->rear) {
        cout << "The queue is null. Delete failed." << endl;
        return NULL;
    } else {
        ptrQ->front = (ptrQ->front+1)%MAXSIZE;
        return ptrQ->Data[ptrQ->front];
    }
}