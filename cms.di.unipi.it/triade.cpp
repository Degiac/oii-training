#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    #ifdef EVAL
    freopen("output.txt", "w", stdout);
    #endif

    int N, M;
    int cont = 0;
    vector<pair<int, int> > edge;
    vector<set<int> > graph;

    scanf("%d %d", &M, &N);

    graph.resize(N+1);

    for(int i = 0; i < M; i++)
    {
        int h, t;
        scanf("%d %d", &h, &t);
        edge.push_back(make_pair(h, t));
        graph[h].insert(t);
        graph[t].insert(h);
    }

    for(int i = 0; i < M; i++)
    {
        int h = edge[i].first;
        int t = edge[i].second;
        if((int)graph[h].size() < (int)graph[t].size())
        {
            for(set<int>::iterator i = graph[h].begin(); i != graph[h].end(); i++)
                if(graph[t].find(*i) != graph[t].end()) cont++;
        }
        else
        {
            for(set<int>::iterator i = graph[t].begin(); i != graph[t].end(); i++)
                if(graph[h].find(*i) != graph[h].end()) cont++;
        }
    }

    printf("%d\n", cont/3);

}
