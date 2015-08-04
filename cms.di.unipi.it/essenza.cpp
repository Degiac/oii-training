#include <cstdio>
#include <algorithm>

#define MAXN 1000

using std::min;
using std::max;

int p[MAXN], sol;

int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N, K; scanf("%d %d", &K, &N);

	for(int i = 0; i < N; i++)
		scanf("%d", p+i);

	for(int i = 0; i < N; i++)
		for(int j = i; j < min(i + K + 1, N); j++)
			sol = max(sol, p[j] - p[i]);

	printf("%d\n", sol);
	
	return 0;
}
