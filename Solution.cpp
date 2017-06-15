//
// Created by Metallic  on 17/4/3.
//

#include "Solution.h"

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

int Solution::Fibonacci(int n) {
    int i = 0, j = 1;
    while (n--) {
        j += i;//f(n+1);
        i = j - i;//f(n);
    }
    return i;
}

int Solution::jumpFloor(int number) {
    int i = 1, j = 2;
    while (number-- > 1) {
        j += i;
        i = j - i;
    }
    return i;
}

int Solution::jumpFloorII(int number) {
    return 1<<--number;
}

int Solution::rectCover(int number) {
    int i = 1, j = 2;
    while (number-- > 1) {
        j += i;
        i = j - i;
    }
    return i;
}

int Solution::NumberOf1(int n) {
    int count = 0;
    while (n) {
        count++;
        n = n & (n - 1);
    }
    return count;
}

double Solution::Power(double base, int exponent) {
    if (base == 0) return 0;

    int n;
    double result = 1.0, temp = base;

    if (exponent > 0)
        n = exponent;
    else if (exponent < 0)
        n = -exponent;
    else
        return 1;

    while (n) {
        if (n & 1 == 1)
            result *= temp;
        temp *= temp;
        n >>= 1;
    }

    return exponent > 0 ? result : 1 / result;
}

void Solution::reOrderArrayI(vector<int> &array) {
    if (array.empty()) return;

    vector<int> v;
    for (int i = 0; i < array.size(); ++i) {
        if (array[i] % 2 != 0)
            v.push_back(array[i]);
    }
    for (int j = 0; j < array.size(); ++j) {
        if (array[j] % 2 == 0)
            v.push_back(array[j]);
    }

    array = v;
}

void Solution::reOrderArrayII(vector<int> &array) {
    if (array.empty()) return;

    int a = 0, temp, k;

    while (array[a] % 2 != 0)//找到第一个偶数的位置
        ++a;

    for (int i = a + 1; i < array.size(); ++i) {
        if (array[i] % 2 != 0) {
            temp = array[i];
            k = i - 1;
            while (k >= a) {
                array[k + 1] = array[k];
                --k;
            }
            array[a++] = temp;
        }
    }
}

ListNode *Solution::FindKthToTail(ListNode *pListHead, unsigned int k) {
    //两个指针p1用于遍历链表，因为正数第k和倒数第k是对称的，
    //p2在位置大于等于k时开始遍历，当循环停止时p2自然指向倒数第k个数
    int length = 1;
    ListNode *p1 = pListHead;
    ListNode *p2 = pListHead;
    if (pListHead) {
        while (p1->next) {
            if (length >= k)
                p2 = p2->next;
            p1 = p1->next;
            ++length;
        }
    }

    if (length < k || k == 0) return NULL;

    return p2;
}

ListNode *Solution::ReverseList(ListNode *pHead) {
    if (pHead == NULL) return pHead;

    ListNode *pre = NULL;
    ListNode *next = NULL;
    while (pHead) {
        next = pHead->next;
        pHead->next = pre;
        pre = pHead;
        pHead = next;
    }

    return pre;
}

ListNode *Solution::MergeList(ListNode* pHead1, ListNode* pHead2)
{
    if (pHead1 == NULL) return pHead2;
    if (pHead2 == NULL) return pHead1;

    ListNode *temp = NULL;
    ListNode *head = NULL;
    if (pHead1->val <= pHead2->val) {
        head = pHead1;
        pHead1 = pHead1->next;
    } else {
        head = pHead2;
        pHead2 = pHead2->next;
    }
    ListNode *pre = head;

    while (pHead1 && pHead2) {
        if (pHead1->val <= pHead2->val) {
            pre = pHead1;
            pHead1 = pHead1->next;
        } else {
            temp = pHead2->next;

            pHead2->next = pre->next;
            pre->next = pHead2;

            pre = pHead2;
            pHead2 = temp;
        }
    }

    if (pHead1) pre->next = pHead1;
    if (pHead2) pre->next = pHead2;

    return head;
}

bool Solution::HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
    if (pRoot1 == NULL || pRoot2 == NULL) return false;
    return IsSubtree(pRoot1, pRoot2)
           || HasSubtree(pRoot1->left, pRoot2)
           || HasSubtree(pRoot1->right, pRoot2);
}

bool Solution::IsSubtree(TreeNode *p1, TreeNode *p2) {
    if (p2 == NULL) return true;
    if (p1 == NULL) return false;

    if (p1->val == p2->val)
        return IsSubtree(p1->left, p2->left)
               && IsSubtree(p1->right, p2->right);
    else
        return false;
}

void Solution::Mirror(TreeNode *pRoot) {
    if (pRoot == NULL) return;
    if (pRoot->left == NULL && pRoot->right == NULL) return;

    TreeNode *temp;
    temp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = temp;

    Mirror(pRoot->left);
    Mirror(pRoot->right);
}

vector<int> Solution::printMatrix(vector<vector<int> > matrix) {
    vector<int> v;
    if (matrix.empty()) return v;

    int row = matrix.size() - 1;
    int col = matrix[0].size() - 1;
    int circles = row < col ? row / 2 + 1 : col / 2 + 1;
    for (int i = 0; i < circles; ++i) {
        for (int j = i; j <= col; ++j) {
            v.push_back(matrix[i][j]);
        }
        for (int k = i + 1; k <= row; ++k) {
            v.push_back(matrix[k][col]);
        }
        for (int l = col - 1; l > i && (row - i > 0); --l) {
            v.push_back(matrix[row][l]);
        }
        for (int m = row; m > i && (col - i > 0); --m) {
            v.push_back(matrix[m][i]);
        }

        row--;
        col--;
    }

    return v;
}

void Solution::min_push(int value)
{
    val_stack.push(value);
    if (min_stack.empty()) {
        min_stack.push(value);
    } else {
        int min = min_stack.top();
        if (value < min)
            min_stack.push(value);
        else
            min_stack.push(min);
    }
}

void Solution::min_pop()
{
    if (val_stack.empty()) {
        return;
    } else {
        val_stack.pop();
        min_stack.pop();
    }
}

int Solution::min_top()
{
    return val_stack.top();
}

int Solution::min_min() {
    return min_stack.top();
}

bool Solution::IsPopOrder(vector<int> pushV, vector<int> popV) {
    if (pushV.empty()) return false;

    vector<int> stack;
    for (int i = 0, j = 0; i < pushV.size(); ++i) {
        stack.push_back(pushV[i]);
        while (j < popV.size() && stack.back() == popV[j]) {
            stack.pop_back();
            ++j;
        }
    }

    return stack.empty();
}



