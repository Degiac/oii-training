#include <cstdio>

int N;

int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d\n", &N);

	int ma = N, mi = 1;

	for(int i = 0; i < N-1; i++)
	{
		char c = getchar_unlocked();
		if(c == '<')
			printf("%d ", mi++);
		else
			printf("%d ", ma--);
	}

	printf("%d\n", mi);

	return 0;
}
