#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>

#define MAXN (int)1e5
#define MAXH (int)1e6

using namespace std;

typedef pair<int, int> ii;

int gratta[MAXN], sx[MAXN], dx[MAXN], N;

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
    
    int mas = 0;
    for(int i = 0; i < N; i++)
        mas = max(gratta[i] = readInt(), mas);
    
    for(int i = 0; i < N; i++)
    {
        if(gratta[i] != mas) continue;
        
        int j;
        for(j = i - 1, sx[i] = 0; j >= 0 && gratta[i] > gratta[j]; sx[i]++, j--);
        if(j >= 0)
            if(gratta[i] == gratta[j]) sx[i]++;
        
        for(j = i + 1, dx[i] = 0; j < N && gratta[i] > gratta[j]; dx[i]++, j++);
        if(j < N)
            if(gratta[i] == gratta[j]) dx[i]++;
    }
    
    int sol = 0;
    
    for(int i = 0; i < N; i++)
        sol = max(sol, dx[i]+sx[i]);

    printf("%d\n", sol+1);
    
    return 0;
}
