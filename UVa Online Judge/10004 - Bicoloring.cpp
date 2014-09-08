#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef vector<int> vi;

int N, M;
int col[200]; // 0 - not colored; 1 - white; 2 - black
vi graph[200];

bool solve()
{
    queue<int> q;
    q.push(0);
    col[0] = 1;

    while(!q.empty())
    {
        int c = q.front();
        q.pop();
        for(int i = 0; i < (int)graph[c].size(); i++)
        {
            if(col[graph[c][i]] == 0) 
            { 
                q.push(graph[c][i]); 
                col[graph[c][i]] = (col[c] == 1) ? 2 : 1; 
                continue; 
            }
            if(col[graph[c][i]] == col[c]) return false;
        }
    }
    return true;
}

int main()
{
    while(scanf("%d", &N), N)
    {
        for(int i = 0; i < N; i++) graph[i].clear();
        memset(col, 0, sizeof col);
        scanf("%d", &M);
        for(int i = 0; i < M; i++)
        {
            int h, t;
            scanf("%d %d", &h, &t);
            graph[h].push_back(t);
            graph[t].push_back(h);
        }
        if(solve()) printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
    return 0;
}
