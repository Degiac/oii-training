#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

#define pb      push_back
#define fi      first
#define se      second
#define mp      make_pair
#define sz(a)   (int)a.size()

#define EPS     1e-9
#define INF     (int)1e9
#define COMBO   0xFFFF

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int N;
ii st[16];
double dp[COMBO];

double dist(ii i, ii j)
{
    return sqrt((double)pow(abs(i.fi-j.fi), 2) + (double)pow(abs(i.se-j.se), 2));
}

double solve(int curr)
{
    if(curr == 0) return 0;
    if(dp[curr] < INF) return dp[curr];

    for(int i = 0; i < 15; i++)
    {
        int temp = curr;
        if(temp & (1 << i))
        {
            temp -= (1 << i);
            for(int j = i+1; j < 16; j++)
            if(temp & (1 << j))
                dp[curr] = min(dp[curr], solve(temp - (1<<j)) + dist(st[i], st[j]));
        }
    }
    return dp[curr];
}

int main()
{
    int t = 1;
    while(scanf("%d", &N), N)
    {
        int mask = 0;
        char useless[25];
        for(int i = 0; i < 2*N; i++)
        {
            mask |= (1 << i);
            scanf("%s %d %d", useless, &st[i].fi, &st[i].se);
        }

        for(int i = 0; i <= mask; i++)
            dp[i] = INF;

        printf("Case %d: %.2lf\n", t++, solve(mask));
    }
    return 0;
}
