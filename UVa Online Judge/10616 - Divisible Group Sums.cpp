#include <cstdio>
#include <cstring>

int v[205];
int mem[205][15][25];
int N, Q, M, D;

int modulo(int x, int y)
{
    return ((x % y) + y) % y;
}

int solve(int pos, int rim, int mod)
{
    if(rim == 0)
        return mem[pos][rim][mod] = (mod == 0);

    if(pos == N)
        return 0;

    if(mem[pos][rim][mod] > -1)
        return mem[pos][rim][mod];

    return mem[pos][rim][mod] = solve(pos+1, rim, mod) + solve(pos+1, rim-1, modulo((mod+v[pos]),D));
}

int main()
{
    int s = 1;
    while(scanf("%d %d", &N, &Q), N && Q)
    {
        printf("SET %d:\n", s++);
        int i = -1;
        while(++i < N)
            scanf("%d", &v[i]);

        int q = 1;
        while(Q--)
        {
            scanf("%d %d", &D, &M);
            memset(mem, -1, sizeof mem);
            printf("QUERY %d: %d\n", q++, solve(0, M, 0));
        }
    }

    return 0;
}
