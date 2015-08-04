#include <cstdio>
#include <cstring>

#define MAXN 100000

int N, period;
char seq[MAXN];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		scanf(" %c", seq+i);
	
	for(int i = 2; i <= N/2; i++)
	{
		bool isThis = true;
		if(N % i == 0)
		{
			for(int l = 1; l < N/i && isThis; l++)
				for(int j = 0; j < i && isThis; j++)
					if(seq[j] != seq[l*i+j] || l*i+j >= N) isThis = false;

		        if(isThis)
		        {
			        period = i;
			        break;
		        }
		}
        }

	if(period == 0) printf("2");
	else for(int i = 0; i < period; i++)
		printf("%c ", seq[i]);

	return 0;
}
