/*
 * @Author: your name
 * @Date: 2021-01-31 23:08:47
 * @LastEditTime: 2021-01-31 23:12:50
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \简单\21合并两个有序链表01.cpp
 */

#include <stdio.h>
#include <stdlib.h>

#include <algorithm>
#include <iostream>

using namespace std;

//解法一:递归方式
//思路:采用递归思想解决问题主要关注以下三点
// 1.返回值:本题中是合并完成的链表的头指针
// 2.递归最小单元做了什么:分两种递归情况(1)当L1[0]<L2[0]时,递归函数为mergeTwoLists(l1->next,l2);(2)当L1[0]>=L2[0],递归函数为mergeTwoLists(l1,l2->next)。即两个链表头部值较小的一个节点与剩下元素的mergeTwoLists操作结果合并
// 3.终止条件:如果两个链表有一个为空,递归结束
//时间复杂度:O(M+N),其中M和N分别为两个链表的长度。因为每次调用递归都会去掉L1或者L2的头节点（直到至少有一个链表为空）,函数mergeTwoList至多只会递归调用每个节点一次。因此，时间复杂度取决于合并后的链表长度,即o(M+N)
//空间复杂度:O(M+N),其中M和N分别为两个链表的长度。递归调用mergeTwoLists函数时需要消耗栈空间,栈空间的大小取决于递归调用的深度。结束递归调用时mergeTwoLists函数最多调用M+N次,因此空间复杂度为O(M+N)

typedef struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
} Node, *p_Node;

//头插法
void headInsert(p_Node *pphead, p_Node *pptail, int data) {
    p_Node pnew = (p_Node)calloc(1, sizeof(Node));
    pnew->val = data;
    if (*pphead == nullptr) {
        *pphead = pnew;
        *pptail = pnew;
    } else {
        pnew->next = *pphead;
        *pphead = pnew;
    }
}

//链表的打印
void print(p_Node phead) {
    p_Node p_current = phead;
    while (p_current) {
        cout << p_current->val;
        p_current = p_current->next;
    }
    cout << endl;
}

class Test {
   public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main() {
    Test test;
    p_Node phead1 = nullptr, ptail1 = nullptr, phead2 = nullptr,
           ptail2 = nullptr;
    int value, i = 0, j = 0;
    while (cin >> value, !cin.eof() && i != 3) {
        headInsert(&phead1, &ptail1, value);
        ++i;
    }
    while (cin >> value, !cin.eof() && j != 3) {
        headInsert(&phead2, &ptail2, value);
        ++j;
    }
    print(test.mergeTwoLists(phead1, phead2));
    return 0;
}
