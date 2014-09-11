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
#define MAXN    1005

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int N, M;
vii graph[MAXN];
int dist[MAXN];

bool solve()
{
    for(int i = 0; i < N; i++) dist[i] = INF; dist[0] = 0;
    for(int i = 0; i < N-1; i++)
        for(int u = 0; u < N; u++)
            for(int j = 0; j < sz(graph[u]); j++)
            {
                ii v = graph[u][j];
                dist[v.fi] = min(dist[v.fi], dist[u] + v.se);
            }

    for(int u = 0; u < N; u++)
        for(int i = 0; i < sz(graph[u]); i++)
        {
            ii v = graph[u][i];
            if(dist[v.fi] > dist[u] + v.se)
                return true;
        }

    return false;
}

int main()
{
    int t; scanf("%d", &t);
    while(t--)
    {
        for(int i = 0; i < N; i++) graph[i].clear();
        scanf("%d %d", &N, &M);
        while(M--)
        {
            int h, t, w;
            scanf("%d %d %d", &h, &t, &w);
            graph[h].pb(ii(t, w));
        }
        if(solve()) printf("possible\n");
        else printf("not possible\n");
    }

    return 0;
}
