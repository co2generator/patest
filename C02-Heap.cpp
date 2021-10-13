/**
 * ZJU Data Structure Note
 * 
 * Heap (堆)
 * 
 * 堆的特性：
 *   （1）结构性：用数组表示的完全二叉树
 *   （2）有序性：任一结点的关键字是其子树所有结点的最大值（或最小值），即最大堆、最小堆
 */
#include <iostream>
using namespace std;
#define MaxData 1000

typedef int ElementType;
typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
    ElementType* data;     // 存储堆元素的数组
    int size;              // 堆的当前元素个数
    int capacity;          // 堆的最大容量
};

MaxHeap create(int maxSize);
bool isEmpty(MaxHeap H);
bool isFull(MaxHeap H);
void insert(MaxHeap H, ElementType item);
ElementType deleteMax(MaxHeap H);


int main() {

    return 0;
}

MaxHeap create(int maxSize) {
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStruct));
    H->data = (ElementType*)malloc((maxSize+1) * sizeof(ElementType));
    H->size = 0;
    H->capacity = maxSize;
    H->data[0] = MaxData;
    return H;
}

bool isFull(MaxHeap H) {
    return H->size == H->capacity;
}

bool isEmpty(MaxHeap H) {
    return H->size == 0;
}

void insert(MaxHeap H, ElementType item) {
    int i;
    if (isFull(H)) {
        cout << "最大堆已满." << endl;
        return;
    }
    i = ++H->size;
    for ( ; H->data[i / 2] < item; i /= 2) {
        H->data[i] = H->data[i / 2];
    }
    H->data[i] = item;
}

ElementType deleteMax(MaxHeap H) {
    int parent, child;
    ElementType maxItem, temp;
    if (isEmpty(H)) {
        cout << "最大堆已为空" << endl;
        return;
    }
    maxItem = H->data[1];   // 取出根结点
    temp = H->data[H->size--];
    for (parent = 1; parent*2 <= H->size; parent=child) {
        child = parent * 2;
        if ((child != H->size) && H->data[child] < H->data[child+1]) {
            child++;
        }
        if (temp >= H->data[child]) {
            break;
        } else {
            H->data[parent] = H->data[child];
        }
    }
    H->data[parent] = temp;
    return maxItem;
}

void PercDown( MaxHeap H, int p ) { 
    int Parent, Child;
    ElementType X;
    X = H->data[p]; // 取出根结点存放的值
    for( Parent=p; Parent*2<=H->size; Parent=Child ) {
        Child = Parent * 2;
        // Child指向左右子结点的较大者
        if( (Child!=H->size) && (H->data[Child]<H->data[Child+1]) )
            Child++;  
        if( X >= H->data[Child] ) break;
        else
            H->data[Parent] = H->data[Child];
    }
    H->data[Parent] = X;
}

void BuildHeap( MaxHeap H ){
    // 这里假设所有H->Size个元素已经存在H->Data[]中
    int i;
    // 从最后一个结点的父节点开始，到根结点1
    for( i = H->size/2; i>0; i-- )
        PercDown( H, i );
}