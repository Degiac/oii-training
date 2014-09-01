#include <cstdio>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

struct snodo
{
    int value;
    int pCon, pSenza;
};

int N, cont;
vector<snodo> snodi;
vector<list<int> > graph;
vector<bool> visited;
ostringstream out;

void dfs(int c)
{
    visited[c] = true;

    for(list<int>::iterator i = graph[c].begin(); i != graph[c].end(); i++)
    	if(!visited[*i])
        {
            dfs(*i);
            snodi[c].pSenza += snodi[*i].pCon;
            snodi[c].pCon += min(snodi[*i].pCon, snodi[*i].pSenza);
        }

    snodi[c].pCon += snodi[c].value;
}

void print(int c, bool preso)
{
    visited[c] = true;

    if(preso) { out << c+1 << " "; cont++; }

    for(list<int>::iterator i = graph[c].begin(); i != graph[c].end(); i++)
    {
        if(visited[*i]) continue;
        if(snodi[*i].pCon < snodi[*i].pSenza || !preso) print(*i, true);
        else print(*i, false);
    }

}

int main()
{
    freopen("input.txt", "r", stdin);
    #ifdef EVAL
    freopen("output.txt", "w", stdout);
    #endif

    scanf("%d", &N);
    snodi.resize(N);
    graph.resize(N);
    visited.assign(N, 0);

    int h, t;
    for(int i = 0; i < N; i++)
    {
	scanf("%d", &h);
	snodi[i].value = h;
    }

    for(int i = 1; i < N; i++)
    {
        scanf("%d %d", &h, &t);
        h--; t--;
        graph[h].push_back(t);
        graph[t].push_back(h);
    }

    dfs(0);
    for(int i = 0; i < visited.size(); visited[i++] = false);

    if(snodi[0].pCon < snodi[0].pSenza) print(0, 1);
    else print(0, 0);

    printf("%d\n", cont);
    printf("%s\n", out.str().c_str());

    return 0;
}
