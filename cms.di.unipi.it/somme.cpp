#include <cstdio>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

int dp[501][501];
int N;
int num[501], presum[501];

int solve(int b, int e)
{
    if(dp[b][e] != -1) return dp[b][e];
    if(b == e) return dp[b][e] = 0;
    
    int maxsum = numeric_limits<int>::max();

    for(int i = b; i < e; i++)
	maxsum = min(maxsum, max(abs(solve(b, i)), abs(solve(i+1, e))));
    maxsum = max(abs(presum[e]-presum[b-1]), maxsum);

    return dp[b][e] = maxsum;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
 
    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
	scanf("%d", num+i);
 
    for(int i = 0; i <= N; i++) presum[i] = presum[i-1]+num[i];
   
    for(int i = 0; i <= N; i++) for(int j = 0; j <= N; j++) dp[i][j] = -1; 

    printf("%d\n", solve(1, N));
    return 0;
}
