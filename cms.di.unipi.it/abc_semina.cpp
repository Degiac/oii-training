#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 200

using std::max;

int c[MAXN][MAXN];

int main(int argc, const char *argv[])
{
	int N; scanf("%d", &N);

	memset(c, 0, sizeof c);

	for(int i = 0; i < N; i++)
	{
		int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1 += 100;
		x2 += 100;
		y1 += 100;
		y2 += 100;

		for(int j = y2; j < y1; j++)
		{
			c[x1][j]++;
			c[x2][j]--;
		}
	}
	
	int sol = 0;

	for(int i = 0; i < MAXN; i++)
	{
		int semi = 0;
		for(int j = 0; j < MAXN; j++)
		{
			semi += c[j][i];
			sol = max(sol, semi);
		}
	}

	printf("%d\n", sol);

	return 0;
}
