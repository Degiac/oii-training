#include <cstdio>

#define MAXN 30

int cars[MAXN];

int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N, M; scanf("%d %d", &N, &M);

	for(int i = 0; i < N; i++)
		scanf("%d", cars+i);

	for(int i = 0; i < M; i++)
	{
		int sorp; scanf("%d %d", &sorp, &sorp);

		for(int i = 0; i < N; i++)
			if(cars[i] == sorp)
			{
				int t = cars[i];
				cars[i] = cars[i+1];
				cars[i+1] = t;
				break;
			}
	}

	printf("%d\n", cars[0]);
	
	return 0;
}
