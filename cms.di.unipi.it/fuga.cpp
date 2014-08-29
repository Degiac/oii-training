#include <cstdio>
#include <vector>
#include <list>
#include <queue>
#include <cstring>

using namespace std;

vector<list<int> > graph;
vector<bool> visited;
queue<int> path;
int curr;

bool findPath(int nodo, int K)
{
    visited[nodo] = true;
    bool found = false;
    for(list<int>::iterator i = graph[nodo].begin(); i != graph[nodo].end() && !found; i++)
    {
	if(*i == curr  && K > 1) found = true;
	if(!visited[*i]) found = findPath(*i, K+1);
    }
    
    if(found) path.push(nodo);
    return found;     
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M;

    scanf("%d %d", &N, &M);

    graph.resize(N+1);
    visited.assign(N+1, false);

    while(M--)
    {
	int v, u, s;
	scanf("%d %d %d", &v, &u, &s);
	if(s == 1)
	{
	    graph[v].push_back(u);
	    graph[u].push_back(v);
	}
    }

    int i = 1;
    curr = 1;
    while(!findPath(i++, 0)) 
    {
	curr = i; 
	queue<int> q;
	swap(q, path);
	for(int i = 0; i <= N; i++) visited[i] = false;    
    }

    printf("%d\n", path.size());
    while(!path.empty())
    {
	printf("%d ", path.front());
	path.pop();
    }

    return 0;
}
