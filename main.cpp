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

    vector<int> v = {7877,7878,7879,7880,7881,7882,7884,7884,7884,7885,7887,7888,7889,7891,7892,7893,7894,7895,7895,7896,7897,7897,7904,7904,7904,7905,7906,7907,7909,7910,7911,7912,7913,7916,7917,7918,7918,7918,7919,7919,7922,7924,7926,7926,7926,7930,7931,7935,7936,7937,7939,7939,7942,7943,7944,7946,7947,7949,7951,7960,7965,7965,7971,7973,7974,7976,7976,7977,7978,7978,7980,7981,7982,7983,7984,7986,7986,7994,7995,7996,7997,7998,7998,8000,8001,8008,8008,8009,8009,8010,8011,8011,8013,8013,8014,8016,8019,8020,8020,8022,8023,8026,8029,8033,8035,8036,8038,8039,8040,8040,8041,8047,8050,8053,8055,8057,8057,8058,8065,8065,8065,8066,8068,8068,8070,8074,8074,8074,8076,8077,8078,8079,8080,8082,8083,8084,8087,8090,8092,8092,8092,8094,8099,8099,8102,8107,8108,8109,8109,8114,8115,8116,8118,8120,8125,8125,8126,8127,8128,8130,8131,8133,8136,8137,8139,8142,8142,8146,8147,8147,8148,8149,8150,8153,8153,8154,8155,8158,8161,8162,8163,8167,8171,8173,8182,8183,8183,8185,8189,8190,8190,8191,8192,8193,8193,8194,8195,8196,8198,8198,8198,819};

    cout<<s.minNumberInRotateArray(v)<<endl;
    return 0;
}