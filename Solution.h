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

    //7.斐波那契数列的第n项（迭代法）
    int Fibonacci(int n);

    //8.跳台阶
    int jumpFloor(int number);

    //9.变态跳台阶
    int jumpFloorII(int number);

    //10.矩形覆盖
    int rectCover(int number);

    //11.二进制中1的个数
    int  NumberOf1(int n);

    //12.数值的整数次幂(快速幂)
    double Power(double base, int exponent);

    //13.调整数组顺序使奇数位于偶数前面
    void reOrderArrayI(vector<int> &array);
    void reOrderArrayII(vector<int> &array);

    //14.链表中倒数第k个节点
    ListNode *FindKthToTail(ListNode *pListHead, unsigned int k);

    //15.反转链表
    ListNode* ReverseList(ListNode* pHead);

    //16.合并两个排序的链表
    ListNode* MergeList(ListNode* pHead1, ListNode* pHead2);

    //17.树的子结构
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2);
    bool IsSubtree(TreeNode *p1, TreeNode *p2);

    //18.二叉树的镜像
    void Mirror(TreeNode *pRoot);

    //19.顺时针打印矩阵
    vector<int> printMatrix(vector<vector<int> > matrix);

private:
    stack<int> stack1;
    stack<int> stack2;
};


#endif //EMPTY_SOLUTION_H
