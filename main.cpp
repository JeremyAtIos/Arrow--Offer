#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Solution.h"
using namespace std;

double sequenceSum(int n, int m) {
    double sum = 0, temp = n;

    if (m <= 0 || n <= 0) return 0;

    sum += temp;
    for (int i = 0; i < m - 1; ++i) {
        temp = sqrt(temp);
        sum += temp;
    }

    return sum;
}

void suiXianHuaFunc(int m, int n)
{
    bool flag = false;
    for (int i = m; i <= n;  ++i) {
        int a = i % 10; //个位数
        int b = (i / 10) % 10; //十位数
        int c = i / 100; //百位数

        if (i == pow(a, 3) + pow(b, 3) + pow(c, 3)) {
            flag = true;
            printf("%d ", i);
        }
    }
    if (flag)
        printf("\n");
    else
        printf("no\n");
}

int main()
{
    Solution s;

    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    ListNode *node4 = new ListNode(3);
    ListNode *node5 = new ListNode(5);
    ListNode *node6 = new ListNode(7);
    node4->next = node5;
    node5->next = node6;
    node6->next = NULL;

    ListNode *result = s.MergeList(node1, node4);
    while (result) {
        cout<<result->val<<endl;
        result = result->next;
    }

    return 0;
}