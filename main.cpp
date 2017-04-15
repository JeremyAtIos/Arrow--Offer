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

    vector<vector<int> > v = { {1, 2, 3, 4, 5} };
    vector<int> result = s.printMatrix(v);
    for (int i = 0; i < result.size(); ++i) {
        cout<<result[i]<<endl;
    }

    return 0;
}