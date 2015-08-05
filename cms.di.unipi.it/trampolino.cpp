#include <cstdio>

#define MAXN 100000

int e[MAXN];

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
    
    int N; scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
        e[i] = readInt();
        
    int count = 0, pos = 0, lastPos = 0;
    
    while(pos < N)
    {
        count++;
        
        int nextPos = pos+e[pos];
        int howFar = nextPos+e[nextPos];
        
        if(nextPos >= N)
            break;
        
        for(int i = nextPos-1; i > lastPos; i--)
        {
           if(i+e[i] > howFar)
           {
               nextPos = i;
               howFar = i+e[i];
           }
        }
        
        lastPos = pos+e[pos];
        pos = nextPos;
    }
    
    printf("%d\n", count);
    
    return 0;
}   
