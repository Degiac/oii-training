#include <cstdio>

bool isPrime(int n)
{
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0) return false;

	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N; scanf("%d", &N);

	for(int i = 2; i * i <= N; i++)
		if(N%i == 0)
		{
		        int k = N/i;
			if(isPrime(k))
			{
				printf("%d %d\n", i, k);
				return 0;
			}
			else
			{
				printf("-1\n");
				return 0;
			}
		}

	printf("-1\n");
	return 0; 
}
