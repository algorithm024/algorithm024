/*
 * @Author: your name
 * @Date: 2021-01-31 23:13:10
 * @LastEditTime: 2021-01-31 23:14:21
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \简单\21合并两个有序链表.cpp
 */

#include <algorithm>
#include <iostream>

using namespace std;

//解法二:迭代法(非递归方式)
//思路:1.新建空的虚拟头结点2.新建游标3.循环遍历4.交换所选节点指针域的指向
//时间复杂度:O(M+N),其中M和N分别为两个链表的长度。因为每次循环迭代中,l1和l2只有一个元素会被放进合并链表中,因此while循环的次数不会超过两个链表的长度之和。所有其他操作的时间复杂度都是常数级别的，因此总的时间复杂度为O(M+N)
//空间复杂度:O(1)

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
        ListNode *dumpHead = new ListNode(0);
        ListNode *pre = dumpHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                pre->next = l1;
                l1 = l1->next;
            } else {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        //合并后l1和l2最多只有一个还未被合并完,我们直接将链表末尾指向未合并完的链表即可
        pre->next = l1 == nullptr ? l2 : l1;
        return dumpHead->next;
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