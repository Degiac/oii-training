#include <cstdio>
#include <cstring>

#define MAXN 100000

int G[10], sol[MAXN];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N; scanf("%d", &N);
	memset(G, 0, sizeof G);
	
	for(int i = 0; i < N; i++)
	{
		int t; scanf("%d", &t);
		G[t]++;
	}
	
	sol[0] = 0;
	G[0]--;
	
	for(int i = 0; i < 10; i += 2)
		if(G[i] > 0)
		{
			sol[1] = i;
			G[i]--;
			break;
		}
	
	int j = 0;
	
	for(int i = 2; i < N; i++)
	{
		while(G[j] == 0) j++;
		sol[i] = j;
		G[j]--;
	}
	
	for(int i = N-1; i >= 0; i--)
		printf("%d ", sol[i]);
	
	printf("\n");
	
	return 0;
}
