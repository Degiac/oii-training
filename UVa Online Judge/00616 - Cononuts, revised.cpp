#include        <cstdio>
#include        <cmath>
#include        <cstring>
#include        <vector>
#include        <queue>
#include        <stack>
#include        <set>
#include        <map>
#include        <utility>
#include        <algorithm>

#define pb      push_back
#define fi      first
#define se      second
#define mp      make_pair
#define sz(a)   (int)a.size()

#define EPS     1e-9
#define INF     1e9

using namespace std;

int main()
{
    int N;
    while(scanf("%ld", &N), N >= 0)
    {
        if(N == 0) { printf("0 coconuts, no solution\n"); continue; }
        int i;
        for(i = 9; i > 1; i--)
        {
            int temp = N;
            int j = 0;
            for(; j < i; j++)
            {
                temp--;
                if(temp% i != 0) break;
                temp -= (temp/i);
            }
            if(i == j && temp%i == 0) { printf("%d coconuts, %d people and 1 monkey\n", N, i); break; }
        }
        if(i == 1) printf("%d coconuts, no solution\n", N);
    }
}
