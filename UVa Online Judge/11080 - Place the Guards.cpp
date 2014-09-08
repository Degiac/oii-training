#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int v, e;
vector<int> graph[200];
int col[200];

int solve()
{
    int sol = 0;
    for(int i = 0; i < v; i++)
        if(col[i] == 0)
        {
            int col1 = 1, col2 = 0;
            queue<int> q;
            q.push(i);
            col[i] = 1;
            while(!q.empty())
            {
                int c = q.front(); q.pop();
                for(int j = 0; j < (int)graph[c].size(); j++)
                {
                    if(col[graph[c][j]] == 0)
                    {
                        q.push(graph[c][j]);
                        if(col[c] == 1) { col[graph[c][j]] = 2; col2++; }
                        else { col[graph[c][j]] = 1; col1++; }
                    }
                    else if(col[graph[c][j]] == col[c]) return -1;
                }
            }
            if(col2 == 0) sol+=col1;
                else sol += min(col1, col2);
        }

    return sol;
}

int main()
{
    int T; scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &v, &e);
        memset(col, 0, sizeof col);
        for(int i = 0; i < v; i++) graph[i].clear();
        for(int i = 0; i < e; i++)
        {
            int h, t;
            scanf("%d %d", &h, &t);
            graph[h].push_back(t);
            graph[t].push_back(h);
        }
        printf("%d\n", solve());
    }
    return 0;
}
