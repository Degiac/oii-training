#include <cstdio>

#define MAXN 10000

int bottoni[MAXN], diff[MAXN];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout); 
	
	int N; scanf("%d", &N);
	int sol = 1;
	
	for(int i = 0; i < N; i++)
		scanf("%d", bottoni+i);
	
	for(int i = 0; i < N-1; i++)
		diff[i] = bottoni[i] - bottoni[i+1];
	
	int sig = (diff[0] > 0) ? -1 : 1;
	
	for(int i = 0; i < N-1; i++)
	{
		if(diff[i] < 0 && sig > 0)
		{
			sol++;
			sig = -1;
		}
		if(diff[i] > 0 && sig < 0)
		{
			sol++;
			sig = 1;
		}
	}
	
	printf("%d\n", sol);
	
	return 0;
}
