/**
 * 02-线性结构1-两个有序链表序列的合并
 * 
 * 本题要求实现一个函数，将两个链表表示的递增整数序列合并为一个非递减的整数序列。
 * 
 * 函数接口定义
 * 
 * List Merge( List L1, List L2 );
 * 
 * 其中List结构定义如下：
 * 
 * typedef struct Node *PtrToNode;
 * 
 * struct Node {
 *  ElementType Data; // 存储结点数据
 *  PtrToNode   Next; // 指向下一个结点的指针
 * };
 * typedef PtrToNode List; // 定义单链表类型 
 * 
 * L1和L2是给定的带头结点的单链表，其结点存储的数据是递增有序的；
 * 
 * 函数Merge要将L1和L2合并为一个非递减的整数序列。应直接使用原序列中的结点，返回归并后的带头结点的链表头指针。
 * 
 * 输入样例：
 * 
 * 3
 * 1 3 5
 * 5
 * 2 4 6 8 10
 * 
 * 输出样例：
 * 
 * 1 2 3 4 5 6 8 10 
 * 
 * NULL
 * 
 * NULL
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print( List L ); /* 细节在此不表；空链表将输出NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
List Merge( List L1, List L2 ) {
    List mergedList = (List)malloc(sizeof(struct Node));
    PtrToNode ptr0 = mergedList;
    PtrToNode ptr1 = L1->Next;
    PtrToNode ptr2 = L2->Next;
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->Data <= ptr2->Data) {
            ptr0->Next = ptr1;
            ptr1 = ptr1->Next;
        } else {
            ptr0->Next = ptr2;
            ptr2 = ptr2->Next;
        }
        ptr0 = ptr0->Next;
    }
    if (ptr1 != NULL) {
        ptr0->Next = ptr1;
    }
    if (ptr2 != NULL) {
        ptr0->Next = ptr2;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return mergedList;
}
