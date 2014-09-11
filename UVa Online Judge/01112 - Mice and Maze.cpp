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

#define MAXN    100

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int N, M, E, T;
vii graph[MAXN];
int dist[MAXN];

void dijkstra()
{
    dist[--E] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(mp(0, E));

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
                dist[t.fi] = dist[h] + t.se;
                pq.push(mp(dist[t.fi], t.fi));
            }
        }
    }
}

int main()
{
    int test; scanf("%d", &test);
    bool blank = false;
    while(test--)
    {
        if(blank) printf("\n");
        else blank = true;
        scanf("%d %d %d %d", &N, &E, &T, &M);
        for(int i = 0; i < N; i++) { graph[i].clear(); dist[i] = INF; }

        while(M--)
        {
            int h, t, w; scanf("%d %d %d", &h, &t, &w);
            graph[t-1].pb(mp(h-1, w));
        }
        
        dijkstra();
        
        int sol = 0;
        for(int i = 0; i < N; i++)
            if(dist[i] <= T) sol++;
        printf("%d\n", sol);
    }

    return 0;
}
