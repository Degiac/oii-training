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

class UnionFind
{
    private:
    vi p, rank;
    public:
    UnionFind(int N) { for(int i = 0; i < N; i++) p.pb(i); rank.assign(N, 0); }
    int parent(int i) { return (p[i] == i) ? i : p[i] = parent(p[i]); }
    int isSameSet(int i, int j) { return parent(i) == parent(j); }
    int join(int i, int j)
    {
        if(!isSameSet(i, j))
        {
            int x = parent(i), y = parent(j);
            if(rank[x] > rank[y]) p[y] = x;
            else { p[x] = y; if(rank[x] == rank[y]) rank[y]++; }
        }
    }
};

int N, sol;
vector<pair<int, ii> > edges;
vector<vector<ii> > mst;
vector<bool> vis;

void buildMST()
{
    sort(edges.begin(), edges.end());
    UnionFind UF(N);

    for(int i = 0; i < sz(edges); i++)
    {
        pair<int, ii> c = edges[i];
        if(!UF.isSameSet(c.se.fi, c.se.se))
        {
            mst[c.se.fi].pb(mp(c.se.se, c.fi));
            mst[c.se.se].pb(mp(c.se.fi, c.fi));
            UF.join(c.se.fi, c.se.se);
        }
    }
}

bool query(int c1, int c2)
{
    if(c1 == c2) return true;
    
    vis[c1] = true;

    bool found = false;
    for(int i = 0; i < sz(mst[c1]) && !found; i++)
        if(!vis[mst[c1][i].fi])
        {
            found = query(mst[c1][i].fi, c2);
            if(found) sol = max(sol, mst[c1][i].se); 
        }

    return found;    
}

int main()
{
    int Q, S, cont = 1;
    while(scanf("%d %d %d", &N, &S, &Q), N && S && Q)
    {
        if(cont != 1) printf("\n");
        printf("Case #%d\n", cont++);
        edges.clear();
        mst.clear();
        mst.resize(N);
        for(int i = 0; i < S; i++)
        {
            int h, t, w; scanf("%d %d %d", &h, &t, &w);
            edges.pb(mp(w, ii(h-1, t-1)));
        }
        buildMST();

        for(int i = 0; i < Q; i++)
        {
            sol = 0;
            vis.assign(N, 0);
            int c1, c2; scanf("%d %d", &c1, &c2);
            if(query(c1-1, c2-1)) printf("%d\n", sol);
            else printf("no path\n");
        }
    }

    return 0;
}
