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
#define sz(a)   (int)(a.size())

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
    vi ufds, rank;
    public:
    UnionFind(int n) { ufds.assign(n, 0); for(int i = 0; i < n; i++) ufds[i] = i; rank.assign(n, 0); }
    int parent(int c) { return (ufds[c] == c) ? c : ufds[c] = parent(ufds[c]); }
    int isSameSet(int c, int v) { return parent(c) == parent(v); }
    void join(int c, int v)
    {
        if(!isSameSet(c, v))
        {
            int x = parent(c), y = parent(v);
            if(rank[x] > rank[y])
                ufds[y] = x;
            else
            {
                ufds[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

bool cmp(pair<double, ii> &a, pair<double, ii> &b)
{
    return (a.fi - b.fi) < EPS;
}

int main()
{
    int T; scanf("%d", &T);
    for(int test = 1; test <= T; test++)
    {
        double road = 0, rail = 0; int states = 1;
        int N, R; scanf("%d %d", &N, &R);
        vii coord(N);
        vector<pair<double, ii> > edges;
        UnionFind UF(N);
        for(int i = 0; i < N; i++)
        {
            int x, y; scanf("%d %d", &x, &y);
            coord[i] = mp(x, y);
        }

        for(int i = 0; i < N-1; i++)
            for(int j = i+1; j < N; j++)
            {
                double w = sqrt((double)pow(coord[i].fi-coord[j].fi, 2) + (double)pow(coord[i].se-coord[j].se, 2));
                
                edges.pb(mp(w, ii(i, j)));
            }
        sort(edges.begin(), edges.end(), cmp);

        for(int i = 0; i < sz(edges); i++)
        {
            pair<double, ii> front = edges[i];
            
            if(!UF.isSameSet(front.se.fi, front.se.se))
            {
                if(front.fi > R)
                {
                    rail += front.fi;
                    states++;
                }
                else road += front.fi;

                UF.join(front.se.fi, front.se.se);
            }
        }
        int ro = floor(road+0.5);
        int ra = floor(rail+0.5);
        printf("Case #%d: %d %d %d\n", test, states, ro, ra);
    }

    return 0;
}
