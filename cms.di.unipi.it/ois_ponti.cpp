#include <cstdio>
#include <vector>

#define MAXN 10000

using namespace std;

vector<int> graph[MAXN];
bool visited[MAXN];

void dfs(int n)
{
	if(visited[n]) return;
	else visited[n] = true;
	
	for(int i = 0; i < (int)graph[n].size(); ++i)
		dfs(graph[n][i]);
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N, M; scanf("%d %d", &N, &M);
	int conn = 0;
	
	while(M--)
	{
		int h, t; scanf("%d %d", &h, &t);
		graph[h].push_back(t);
		graph[t].push_back(h);
	}
	
	for(int i = 0; i < N; ++i)
		if(!visited[i])
		{
			conn++;
			dfs(i);
		}

	printf("%d\n", conn-1);
}
