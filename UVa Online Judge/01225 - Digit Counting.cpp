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
    int T, N, digit[10];
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N); memset(digit, 0, sizeof digit);
        for(int i = 1; i <= N; i++)
        {
            int t = i;
            while(t)
            {
                digit[t%10]++;
                t /= 10;
            }
        }

        for(int i = 0; i < 9; i++)
            printf("%d ", digit[i]);
        printf("%d\n", digit[9]);
    }

    return 0;
}
