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

#define MAXN    100005

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

vii graph[MAXN];
ii dp[MAXN];
bool vis[MAXN];

void solve(int s, int e)
{
    queue<int> q;
    q.push(s);
    dp[s] = ii(0, INF);
    vis[s] = true;

    while(!q.empty())
    {
        int c = q.front(); q.pop();
        if(c == e) return;

        for(int i = 0; i < sz(graph[c]); i++)
        {
            int v = graph[c][i].fi, w = graph[c][i].se;
            ii t = ii(dp[c].fi+1, min(dp[c].se, w));
            dp[v] = min(dp[v], t);
            if(!vis[v]) { q.push(v); vis[v] = true; }
        }
    }
}

int Analizza(int N, int M, int W, int L, int arco_da[], int arco_a[], int capacita[], int R, int C)
{
    for(int i = 0; i < M; i++)
    {
        int u = arco_da[i], v = arco_a[i], w = capacita[i];
        graph[u].pb(ii(v, w));
        graph[v].pb(ii(u, w));
    }

    for(int i = 1; i <= N; i++) dp[i] = ii(INF, INF);
    memset(vis, 0, sizeof vis);

    solve(W, L);

    return dp[L].se;
}
