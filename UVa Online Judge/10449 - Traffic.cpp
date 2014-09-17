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
#define MAXN    205

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int N, M, busy[MAXN], dist[MAXN];
vii graph[MAXN];
bool reachable[MAXN];
bool vis[MAXN];

void upd(int n)
{
    queue<int> q; q.push(n);
    if(vis[n]) return;
    while(!q.empty())
    {
        int c = q.front(); q.pop();
        vis[c] = 1;
        for(int i = 0; i < sz(graph[c]); i++)
            if(!vis[graph[c][i].fi]) q.push(graph[c][i].fi);
    }
}

void solve()
{
    dist[0] = 0;
    for(int i = 0; i < N-1; i++)
        for(int u = 0; u < N; u++)
            for(int j = 0; j < sz(graph[u]); j++)
            {
                ii v = graph[u][j];
                dist[v.fi] = min(dist[v.fi], dist[u] + v.se);
            }

    for(int u = 0; u < N; u++)
        for(int j = 0; j < sz(graph[u]); j++)
        {
            ii v = graph[u][j];
            if(dist[v.fi] > dist[u] + v.se) upd(v.fi);                 
        }
}

void reachabilityCheck()
{
    queue<int> q; q.push(0);
    vector<bool> vist(N, 0);

    while(!q.empty())
    {
        int c = q.front(); q.pop();
        vist[c] = 1;
        reachable[c] = 1;
        for(int i = 0; i < sz(graph[c]); i++)
            if(!vist[graph[c][i].fi]) q.push(graph[c][i].fi);
    }
}

int main()
{
    int count = 1;
    while(scanf("%d", &N) == 1)
    {
        printf("Set #%d\n", count++);
        for(int i = 0; i < N; i++) { scanf("%d", busy+i); graph[i].clear(); dist[i] = INF; reachable[i] = 0; vis[i] = 0; }
        scanf("%d", &M);
        for(int i = 0; i < M; i++)
        {
            int h, t;
            scanf("%d %d", &h, &t); h--; t--;
            if(h >= N || t >= N) continue;
            int w = busy[t] - busy[h];
            graph[h].pb(ii(t, w*w*w));
        }
        solve();
        reachabilityCheck();
        int Q; scanf("%d", &Q);
        while(Q--)
        {
            int temp; scanf("%d", &temp);
            if(--temp >= N) printf("?\n");
            else if(dist[temp] == INF || dist[temp] < 3 || !reachable[temp] || vis[temp]) printf("?\n");
            else printf("%d\n", dist[temp]);
        }
    }

    return 0;
}
