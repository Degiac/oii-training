#include <cstdio>
#include <vector>
#include <list>

using namespace std;

int N;
vector<list<int> > graph;
vector<int> sol;
vector<bool> visited;

bool dfs(int c, int cont)
{
    if(cont == N-1)
    {
	sol[cont] = c;
	return true;
    }
    
    bool found = false;  
    visited[c] = true;   
    
    for(list<int>::iterator i = graph[c].begin(); i != graph[c].end() && !found; i++)
	if(!visited[*i]) found = dfs(*i, cont+1);

    if(found) sol[cont] = c;

    visited[c] = false;

    return found;
}

int main()
{
    freopen("input.txt", "r", stdin);
    #ifdef EVAL
    freopen("output.txt", "w", stdout);
    #endif

    scanf("%d", &N);
    
    graph.resize(N);
    visited.assign(N, 0);    
    sol.resize(N);

    for(int i = 0; i < N*(N-1)/2; i++)
    {
	int h, t;
	scanf("%d %d", &h, &t);
	graph[h-1].push_back(t-1);	
    }	

    int c = 0;
    while(!dfs(c, 0) && c<N) c++;

    printf("%d\n", N-1);

    for(int i = 1; i < N; i++)
	printf("%d %d\n", sol[i-1]+1, sol[i]+1);

    return 0;
}
