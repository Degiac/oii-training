#include <cstdio>
#include <algorithm>
#include <cstring>

#define MAXN 5000
#define INF (int)1e9

using std::min;

int dp[MAXN][MAXN];
int p[MAXN];
int K, N;

int solve(int w, int i)
{
    if(w >= K) return w;
    if(i == N) return INF;
    if(dp[w][i] > 0) return dp[w][i];
    
    return dp[w][i] = min(solve(w+p[i], i+1), solve(w, i+1));
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    memset(dp, 0, sizeof dp);
    scanf("%d %d", &N, &K);
    
    for(int i = 0; i < N; i++)
        scanf("%d", p+i);
    
    printf("%d\n", solve(0,0));
    
    return 0;
}
