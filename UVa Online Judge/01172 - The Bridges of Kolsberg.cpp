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
#include <string>

#define pb      push_back
#define fi      first
#define se      second
#define mp      make_pair
#define sz(a)   (int)a.size()

#define EPS     1e-9
#define INF     (int)1e9
#define MAXN    1005

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int lS, lN;
ii dp[MAXN][MAXN];
vii south, north;

bool cmp(const ii &a, const ii &b)
{
    if(a.fi < b.fi) return true;
    if(a.fi == b.fi && a.se > b.se) return true;
    return false;
}

ii solve(int currS, int currN)
{
    if(currS >= lS || currN >= lN) return ii(-1, 0);
    if(dp[currS][currN].fi != -1) return dp[currS][currN];

    dp[currS][currN] = ii(0, 0);

    if(south[currS].fi == north[currN].fi)
    {
        dp[currS][currN].fi = south[currS].se + north[currN].se;
        dp[currS][currN].se = 1;
        ii toAdd = solve(currS+1, currN+1);
        if(toAdd.fi != -1) { dp[currS][currN].fi += toAdd.fi; dp[currS][currN].se += toAdd.se; }
    }

    return dp[currS][currN] = max(dp[currS][currN], max(solve(currS+1, currN), solve(currS, currN+1), cmp), cmp);
}

int main()
{
    int t; scanf("%d", &t);  
    while(t--)
    {
        map<string, int> type; int tp = 1;
        south.clear();
        north.clear();

        scanf("%d", &lS);
        for(int i = 0; i < lS; i++)
        {
            int tipo, value;
            char tS[15]; scanf("%s %s %d", tS, tS, &value);
            string s = tS;
            if(type.find(s) == type.end()) type[s] = tipo = tp++;
            else tipo = type[s];
            south.pb(ii(tipo, value));
        }

        scanf("%d", &lN);
        for(int i = 0; i < lN; i++)
        {
            int tipo, value;
            char tS[15]; scanf("%s %s %d", tS, tS, &value);
            string s = tS;
            if(type.find(s) == type.end()) type[s] = tipo = tp++;
            else tipo = type[s];
            north.pb(ii(tipo, value));
        }

        for(int i = 0; i < MAXN; i++) for(int j = 0; j < MAXN; j++) dp[i][j] = ii(-1, 0);
        ii sol = solve(0, 0);

        if(sol.fi != -1)        printf("%d %d\n", sol.fi, sol.se);
        else                    printf("0 0\n");
    }
    return 0;
}
