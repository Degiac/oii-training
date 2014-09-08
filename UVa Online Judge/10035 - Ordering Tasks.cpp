#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef vector<int> vi;

int N, M;
vi graph[100];
bool vis[100];
vi ans;

void toposort(int c)
{
    vis[c] = true;

    for(int i = 0; i < graph[c].size(); i++)
        if(!vis[graph[c][i]]) toposort(graph[c][i]);
    ans.push_back(c+1);
}

int main()
{
    while(scanf("%d %d", &N, &M), N)
    {
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < 100; i++) graph[i].clear();
        for(int i = 0; i < M; i++)
        {
            int h, t; scanf("%d %d", &h, &t);
            graph[h-1].push_back(t-1);
        } 
        for(int i = 0; i < N; i++) if(!vis[i]) toposort(i);
        for(int i = (int)ans.size()-1; i > 0; i--) printf("%d ", ans[i]);
        printf("%d\n", ans[0]);
        ans.clear();
    }
    return 0;
}
