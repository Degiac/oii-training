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

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int N, M, S, E;
vector<vii> graph;

int dijkstra()
{
    vi dist(N, INF); dist[S] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, S));
    while(!pq.empty())
    {
        ii c = pq.top(); pq.pop();
        int d = c.fi, h = c.se;
        if(d > dist[h]) continue;
        for(int i = 0; i < sz(graph[h]); i++)
        {
            ii t = graph[h][i];
            if(dist[h] + t.se < dist[t.fi])
            {
                dist[t.fi] = dist[h]+t.se;
                pq.push(mp(dist[t.fi], t.fi));
            }
        }
    }

    return dist[E];
}

int main()
{
    int T; scanf("%d", &T);  
    for(int i = 1; i <= T; i++)
    {
        printf("Case #%d: ", i);

        scanf("%d %d %d %d", &N, &M, &S, &E);
        graph.resize(N);
        graph.clear();

        for(int i = 0; i < M; i++)
        {
            int h, t, w; scanf("%d %d %d", &h, &t, &w);
            graph[h].pb(ii(t, w));
            graph[t].pb(ii(h, w));
        }

        int ris = dijkstra();
        if(ris == INF) printf("unreachable\n");
        else printf("%d\n", ris);
    }

    return 0;
}
