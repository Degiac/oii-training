#include <cstdio>
#include <utility>
#include <algorithm>

#define fi first
#define se second

#define MAXN 100
#define MAXD 365

using namespace std;

typedef pair<int, int> ii;

int dp[MAXN][MAXD], N;
ii miss[MAXN];

int solve(int idx, int d)
{
	if(idx == N) return 0;
	if(dp[idx][d] != -1) return dp[idx][d];

	int sol = solve(idx+1, d);

	if(d + miss[idx].fi - 2 < miss[idx].se) sol = max(sol, solve(idx+1, d + miss[idx].fi) + 1);

	return dp[idx][d] = sol;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &N);

	for(int i = 0; i < N; i++)
		for(int j = 0; j < MAXD; j++)
			dp[i][j] = -1;

	for(int i = 0; i < N; i++)
		scanf("%d %d", &miss[i].fi, &miss[i].se);

	printf("%d\n", solve(0, 1));

	return 0;
}
