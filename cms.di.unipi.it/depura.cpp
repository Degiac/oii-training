#include <cstdio>
#include <queue>
#include <vector>

#define pb push_back
#define sz(a) (int)a.size()

#define MAXN 2000

using namespace std;

vector<int> grafo[MAXN];
bool visited[MAXN];

int readInt()
{
	int n = 0;
	char c = getchar_unlocked();

	while(c < '0' || c > '9') c = getchar_unlocked();

	while(c >= '0' && c <= '9')
	{
		n *= 10;
		n += (c - '0');
		c = getchar_unlocked();
	}

	return n;
}

int solve(int nodo)
{
	if(sz(grafo[nodo]) == 0) return -1;
	int sol = 1;
        for(int i = 0; i < sz(grafo[nodo]); i++)
        {
		if(visited[grafo[nodo][i]]) continue;
	        int son = solve(grafo[nodo][i]);
	        if(son == -1) return -1;

	        sol += son;
        }
	visited[nodo] = 1;
        return sol;
}

int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int K = readInt(), R = readInt(); 

	for(int i = 0; i < K; i++)
	{
		int t = readInt(); 
		visited[t-1] = 1;
	}
        
	for(int i = 0; i < R; i++)
	{
		int h = readInt(), n = readInt(); 

		for(int j = 0; j < n; j++)
		{
			int t = readInt();
			grafo[h-1].pb(t-1);
		}
	}

	printf("%d\n", solve(0));

	return 0;
}
