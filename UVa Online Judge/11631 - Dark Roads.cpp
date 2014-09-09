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
    vi rank, p;
    public:
    UnionFind(int N) { for(int i = 0; i < N; i++) p.pb(i); rank.assign(N, 0); }
    int parent(int i) { return (p[i] == i) ? i : p[i] = parent(p[i]); }
    bool isSameSet(int i, int j) { return parent(i) == parent(j); }
    void join(int i, int j)
    {
        if(!isSameSet(i, j))
        {
            int x = parent(i), y = parent(j);
            if(rank[x] > rank[y]) p[y] = x;
            else
            {
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main()
{
    int N, M;
    while(scanf("%d %d", &N, &M), N && M)
    {
        int sum = 0, mst = 0;
        vector<pair<int, ii> > edges;
        UnionFind UF(N);
        for(int i = 0; i < M; i++)
        {
            int h, t, w;
            scanf("%d %d %d", &h, &t, &w);
            sum += w;
            edges.pb(mp(w, ii(h, t)));
        }
        sort(edges.begin(), edges.end());

        for(int i = 0; i < sz(edges); i++)
        {
            pair<int, ii> c = edges[i];
            if(!UF.isSameSet(c.se.fi, c.se.se))
            {
                mst += c.fi;
                UF.join(c.se.fi, c.se.se);
            }
        }

        printf("%d\n", sum - mst);
    }

    return 0;
}
