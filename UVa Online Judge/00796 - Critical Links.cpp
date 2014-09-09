#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int N, dfsCount;
vi dfsNum;
vi dfsLow;
vi dfsParent;
vector<vi> graph;
vector<ii> sol;

void solve(int c)
{
    dfsNum[c] = dfsLow[c] = dfsCount++;
    for(int i = 0; i < (int)graph[c].size(); i++)
    {
        int v = graph[c][i];
        if(dfsNum[v] == -1)
        {
            dfsParent[v] = c;

            solve(v);

            if(dfsLow[v] > dfsNum[c])
                sol.pb((c < v) ? ii(c, v) : ii(v, c));

            dfsLow[c] = min(dfsLow[c], dfsLow[v]);
        }
        else if(dfsParent[c] != v) dfsLow[c] = min(dfsLow[c], dfsNum[v]);
    }
}

int main()
{
    bool i = 0;
    while(scanf("%d", &N) != EOF)
    {
        graph.assign(N, vi());
        dfsNum.assign(N, -1);
        dfsLow.assign(N, 0);
        dfsParent.assign(N, 0);
        sol.clear();
        dfsCount = 0;
        
        for(int i = 0; i < N; i++)
        {
            int h, j; scanf("%d (%d)", &h, &j);
            while(j--)
            {
                int t;
                scanf("%d", &t);
                graph[h].pb(t);
            }
        }

        for(int i = 0; i < N; i++)
            if(dfsNum[i] == -1) solve(i);

        sort(sol.begin(), sol.end());
        
        printf("%d critical links\n", (int)sol.size());

        for(int i = 0; i < (int)sol.size(); i++)
            printf("%d - %d\n", sol[i].fi, sol[i].se);
        printf("\n");
    }
    return 0;
}
