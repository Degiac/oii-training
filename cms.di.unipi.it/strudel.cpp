#include <cstdio>

#define MAXN 100000

int can[MAXN], man[MAXN], diff[MAXN+1], C[MAXN+1], M[MAXN+1];

int readInt()
{
    int n = 0;
    char c = getchar_unlocked();
    
    while(c < '0' || c > '9') c = getchar_unlocked();
    
    while(c >= '0' && c <= '9') 
    {
        n *= 10;
        n += (c-'0');
        c = getchar_unlocked();
    }
    
    return n;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N = readInt();
    
    for(int i = 0; i < N; i++)
        man[i] = readInt();
    for(int i = 0; i < N; i++)
        can[i] = readInt();
    
    for(int i = 0; i < N; i++)
        diff[i+1] = can[i] - man[i];
    
    int x = 0, y = 0;
    for(int i = 1; i <= N; i++)
    {
       C[i] = C[i-1] + diff[i];
       if(C[i-1] < C[M[i-1]])
           M[i] = i - 1;
       else
           M[i] = M[i-1];
       
       int k = i - y + x - 1;
       while(k)
       {
           if(C[i] - C[M[k]] >= 0)
               k = M[k];
           else break;
           
           x = k + 1;
           y = i;
       }
    }
    printf("%d\n", y - x + 1);
    
    return 0;
    
}
