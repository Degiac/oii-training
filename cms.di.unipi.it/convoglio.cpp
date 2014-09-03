#include <cstdio>
#include <vector>
#include <list>
#include <set>
#include <utility>

#define MIL 100000 

using namespace std;

int N, M;
list<int> grafo[2*MIL];
bool visited[2*MIL];
bool wrote[MIL];

int dfs(int c)
{
    if(visited[c])
    {
	if(c < MIL) return 1;
	else return 0;
    }
    visited[c] = true;

    int found = 0;
    for(list<int>::iterator i = grafo[c].begin(); i != grafo[c].end(); i++)
    {
	found = dfs(*i);
	if(found==1 && c >= MIL) { printf("%d %d\n", *i, c-MIL); wrote[*i] = 1; }
	if(found==1 && c < MIL && wrote[c]) found = 2;
	if(found) { visited[c] = 0; return found; }
    }

    visited[c] = false;
    return found;   
}

int main()
{
    freopen("input.txt", "r", stdin);
    #ifdef EVAL
    freopen("output.txt", "w", stdout);
    #endif

    scanf("%d %d", &N, &M);
    
    for(int i = 0; i < N; i++)
    {
	int h, t;
	scanf("%d %d", &h, &t); t += MIL;
	grafo[h].push_back(t);	
    }

    for(int i = N; i < M; i++)
    {
	int h, t;
	scanf("%d %d", &h, &t); t += MIL;
	grafo[t].push_back(h);
    }

    bool found = false;
    for(int i = 0; i < N && !found; i++)   
	found = dfs(i);

    if(!found) printf("-1\n");
    else for(int i = 0; i < N; i++) 
	    if(!wrote[i]) printf("%d %d\n", i, grafo[i].front()-MIL);
    
    return 0;
}
