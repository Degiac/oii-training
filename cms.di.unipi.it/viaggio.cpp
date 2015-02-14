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
int dist[MAXN];

int main()
{
    #ifndef EVAL
    freopen("input.txt", "r", stdin);
    #endif
    
    int N, M; scanf("%d %d", &N, &M);
    
    for(int i = 0; i < N; i++) dist[i] = INF;
    
    for(int i = 0; i < M; i++)
    {
        int h, t, w; scanf("%d %d %d", &h, &t, &w);
        graph[--h].pb(ii(--t, w));
        graph[t].pb(ii(h, w));
    }
    
    priority_queue<ii, vii, greater<ii> > pq; pq.push(ii(0, 0));
    dist[0] = 0;
   
    while(!pq.empty())
    {
        ii top = pq.top(); pq.pop();
        int d = top.fi;
        int h = top.se;
        
        if(d > dist[h]) continue;
        
        for(int i = 0; i < sz(graph[h]); i++)
        {
            int t = graph[h][i].fi, w = graph[h][i].se;
            if(dist[h] + w < dist[t])
            {
                dist[t] = dist[h] + w;
                pq.push(ii(dist[t], t));
            }
        }
    }
    
    printf("%d\n", dist[N-1]);

    return 0;
}
