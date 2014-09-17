#include <cstring>
#include <cstdio>
#include <algorithm>

#ifndef EVAL
#include "grader.cpp"
#endif

using std::min;

int n;
int presum[10005];
int dp[5000];

int equalize(int a, int b)
{
    int mid = (a+b)/2;
    int valSx = presum[mid]-presum[a];
    int valDx = b - mid - presum[b] + presum[mid];
    return valSx + valDx;
}

int solve(int a)
{
    if(dp[a] != -1) return dp[a];

    dp[a] = equalize(a*2, n); 

    for(int i = a+1; i < n/2; i++)
        dp[a] = min(dp[a], solve(i) + equalize(a*2, i*2));

    return dp[a];
}

int Gira(int N, int* freccia)
{
    n = N;
    memset(dp, -1, sizeof dp);

    presum[0] = 0;
    for(int i = 1; i <= N; i++) presum[i] = freccia[i-1] + presum[i-1];

    return solve(0);
}
