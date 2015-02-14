#include <cstdio>
#include <vector>

#define MAXN 10000

using namespace std;

vector<int> grafo[MAXN];
bool presenti[MAXN];
int N, M;

int readInt()
{
	char c = getchar_unlocked();
	
	while(c < '0' || c > '9') c = getchar_unlocked();
	
	int n = 0;
	
	while(c >= '0' && c <= '9')
	{
		n *= 10;
		n += (c - '0');
		c = getchar_unlocked();	
	}
	
	return n;
}

void check(int n)
{
	if(presenti[n]) return;

	int amici = 0;

	for(int i = 0; i < (int)grafo[n].size(); i++)
		amici += (presenti[grafo[n][i]] == 0);
	
	if(amici < 2)
	{
		presenti[n] = 1;
		for(int i = 0; i < (int)grafo[n].size(); i++)
			check(grafo[n][i]);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	N = readInt(); M = readInt();
	
	for(int i = 0; i < M; i++)
	{
		int h = readInt();
		int t = readInt(); 
		
		grafo[h].push_back(t);
		grafo[t].push_back(h);
	}
	
	for(int i = 0; i < N; i++)
		check(i);
	
	int sol = 0; for(int i = 0; i < N; i++) sol += (presenti[i] == 0);
	
	printf("%d\n", sol);
	
	return 0;
}
