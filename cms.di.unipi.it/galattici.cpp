#include <cstdio>

#define MAXN 100

int t[MAXN][26];
int m[MAXN];

int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int M, N, K; scanf("%d %d %d\n", &M, &N, &K);

	for(int i = 0; i < K; i++)
	{
		scanf("%c ", m+i);
		m[i] -= 'a';
	}

	for(int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %c", &a, &b, &c);
		c -= 'a';
		t[--a][c] = --b;
	}

	int sol = 0;

	for(int i = 0; i < K; i++)
		sol = t[sol][m[i]];

	printf("%d\n", sol+1);

	return 0;
}
