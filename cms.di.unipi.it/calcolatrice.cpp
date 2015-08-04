#include <cstdio>
#include <algorithm>

using std::min;

int map[10] = { 0, 1, 2, -1, -1, 5, 9, -1, 8, 6 };

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N; scanf("%d", &N);
    
    if(N%10 == 0)
    {
        printf("%d\n", N);
        return 0;
    }
    
    int v = N;
    int n = 0;
    
    while(v)
    {
       if(map[v%10] < 0)
       {
           printf("%d\n", N);
           return 0;
       }
       
       n *= 10;
       n += map[(v%10)];
       v /= 10;
    }
    
    printf("%d\n", min(N, n));
    
    return 0;
}
