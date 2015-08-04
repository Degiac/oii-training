#include <cstdio>
#include <cmath>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N, K, M; scanf("%d %d %d", &N, &K, &M);
    printf("%d\n", N - (int)(sqrt((double)N)));
    
    return 0;
}
