//
// Created by Metallic  on 17/4/3.
//

#ifndef EMPTY_SOLUTION_H
#define EMPTY_SOLUTION_H

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
    val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//剑指offer
class Solution {
public:
    //1.二维数组中的查找
    bool Find(int target, vector<vector<int> > array);

    //2.替换空格
    void replaceSpace(char *str, int length);

    //3.从尾到头打印链表
    vector<int> printListFromTailToHead(ListNode *head);

    //4.重建二叉树
    TreeNode *reConstructBinaryTree(vector<int> pre,vector<int> vin);
    TreeNode *constructBinaryTree(vector<int> pre, int pre_start, int pre_end,
                                  vector<int> vin, int vin_start, int vin_end);

    //5.用两个栈实现队列
    void push(int node);
    int pop();

    //6.旋转数组的最小数字
    int minNumberInRotateArray(vector<int> rotateArray);

private:
    stack<int> stack1;
    stack<int> stack2;
};


#endif //EMPTY_SOLUTION_H
