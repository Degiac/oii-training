#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int N, dfsCount, rootChildren, sol;
vector<int> graph[100];
int dfsNum[100];
int dfsLow[100];
int dfsParent[100];
bool critical[100];

void findCritical(int c)
{
    dfsLow[c] = dfsNum[c] = dfsCount++;
    for(int i = 0; i < (int)graph[c].size(); i++)
    {
        int v = graph[c][i];
        if(dfsNum[v] == -1)
        {
            dfsParent[v] = c;
            if(c == 0) rootChildren++; 

            findCritical(v);

            if(dfsLow[v] >= dfsNum[c]) critical[c] = true;

            dfsLow[c] = min(dfsLow[c], dfsLow[v]);
        }
        else if(v != dfsParent[c])
            dfsLow[c] = min(dfsLow[c], dfsNum[v]);
    }
}

int main()
{
    while(scanf("%d", &N), N)
    {
        for(int i = 0; i < N; i++) { graph[i].clear(); dfsNum[i] = -1; }
        dfsCount = 0; sol = 0, rootChildren = 0;
        memset(dfsLow, 0, sizeof dfsLow);
        memset(dfsParent, 0, sizeof dfsParent);
        memset(critical, 0, sizeof critical);

        int h, t;
        while(scanf("%d", &h), h)
        {
            char c;
            while(scanf("%c", &c), c != '\n')
            {
                scanf("%d", &t);
                graph[h-1].push_back(t-1);
                graph[t-1].push_back(h-1);
            }
        }

        findCritical(0);
        critical[0] = (rootChildren > 1); 
        for(int i = 0; i < N; i++) sol += critical[i];
        printf("%d\n", sol);
    }

    return 0;
}
