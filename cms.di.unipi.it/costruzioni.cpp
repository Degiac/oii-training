#include <cstdio>
#include <algorithm>

#define MAXN 100000

using std::min;
int N, K, v[MAXN], presum[MAXN];

int readInt()
{
    int n = 0;
    char c = getchar_unlocked();
    while(c < '0' || c > '9') c = getchar_unlocked();
    
    while(c >= '0' && c <= '9')
    {
        n *= 10;
        n += (c - '0');
        c = getchar_unlocked();
    }
    
    return n;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    N = readInt();
    K = readInt();
    
    for(int i = 0; i < N; i++)
        v[i] = readInt();
        
    presum[0] = v[0];
    
    for(int i = 1; i < N; i++)
        presum[i] = v[i] + presum[i-1];
    
    int sol = presum[K-1];
        
    for(int i = 1; i <= N-K; i++)
       sol = min(sol, presum[i+K-1] - presum[i-1]);
    
    printf("%d\n", sol);
    
    return 0;
}
