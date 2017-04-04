//
// Created by Metallic  on 17/4/3.
//

#include "Solution.h"
#include <stack>

bool Solution::Find(int target, vector<vector<int> > array) {
    if (array.empty()) return false;

    int row = 0;
    int col = array[0].size() - 1;
    while (row < array.size() && col >= 0) {
        if (array[row][col] == target) {
            return true;
        } else if (array[row][col] > target) {
            --col;
        } else {
            ++row;
        }
    }
    return false;
}

void Solution::replaceSpace(char *str, int length) {
    if (str == NULL || length < 0) return;

    int spaceNum = 0, i = 0, old_length = 0;
    while (str[i] != '\0') {
        old_length++;
        if (str[i] == ' ')
            spaceNum++;
        i++;
    }

    int new_length = old_length + spaceNum * 2;
    if (new_length > length) return;

    for (int j = old_length; j >= 0 ; --j) {
        if (str[j] == ' ') {
            str[new_length--] = '0';
            str[new_length--] = '2';
            str[new_length--] = '%';
        } else {
            str[new_length--] = str[j];
        }
    }
}

vector<int> Solution::printListFromTailToHead(ListNode *head) {
    vector<int > v;
    if (head) {
        v = printListFromTailToHead(head->next);
        v.push_back(head->val);
    }
    return v;
}

TreeNode *Solution::reConstructBinaryTree(vector<int> pre, vector<int> vin) {
    if (pre.empty() || vin.empty()) return NULL;

    TreeNode *node = constructBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
    return node;
}

TreeNode *Solution::constructBinaryTree(vector<int> pre, int pre_start, int pre_end,
                              vector<int> vin, int vin_start, int vin_end) {
    if (pre_start > pre_end || vin_start > vin_end) return NULL;

    TreeNode *node = new TreeNode(pre[pre_start]);

    int length = 0;
    while (vin[vin_start + length] != node->val)
        length++;

    node->left = constructBinaryTree(pre, pre_start + 1, pre_start + length, vin, vin_start, vin_start + length - 1);
    node->right = constructBinaryTree(pre, pre_start + length + 1, pre_end, vin, vin_start + length + 1, vin_end);

    return node;
}

void Solution::push(int node) {
    stack1.push(node);
}

int Solution::pop() {
    int temp;
    if (stack2.empty()) {
        while (!stack1.empty()) {
            temp = stack1.top();
            stack2.push(temp);
            stack1.pop();
        }
    }
    temp = stack2.top();
    stack2.pop();
    return temp;
}

int Solution::minNumberInRotateArray(vector<int> rotateArray) {
    if (rotateArray.empty()) return 0;

    int left = 0, right = rotateArray.size() - 1;
    int middle = 0;
    while (rotateArray[left] >= rotateArray[right]) {
        if (right - left == 1) {
            middle = right;
            break;
        }
        middle = (left + right) / 2;
        if (rotateArray[left] == rotateArray[middle] && rotateArray[middle] == rotateArray[right]) {
            int min = rotateArray[left];
            for (int i = left + 1; i < right; ++i) {
                if (rotateArray[i] < min)
                    min = rotateArray[i];
            }
            return min;
        }

        if (rotateArray[middle] >= rotateArray[left])
            left = middle;
        else
            right = middle;
    }
    return rotateArray[middle];
}