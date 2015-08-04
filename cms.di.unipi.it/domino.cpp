#include <cstdio>
#include <utility>

#define MAXN 10

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

int N;
int sol;
ii tessere[MAXN];
bool used[MAXN];

void solve(int tes, int tsol, int side)
{
	if(used[tes]) return;
	if(tsol > sol) sol = tsol;
	used[tes] = 1;

	for(int i = 0; i < N; i++)
	{
		if(side == 0 && tessere[i].fi == tessere[tes].fi)
			solve(i, tsol+1, 1);
		if(side == 0 && tessere[i].se == tessere[tes].fi)
			solve(i, tsol+1, 0);
		if(side == 1 && tessere[i].fi == tessere[tes].se)
			solve(i, tsol+1, 1);
		if(side == 1 && tessere[i].se == tessere[tes].se)
			solve(i, tsol+1, 0);
	}

	used[tes] = 0;

	return;
}

int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	sol = 0;
	scanf("%d", &N);

	for(int i = 0; i < N; i++)
	{
		used[i] = 0;
		scanf("%d %d", &tessere[i].fi, &tessere[i].se);
	}

	for(int i = 0; i < N; i++)
		for(int j = 0; j < 2; j++)
		        solve(i, 1, j);

	printf("%d\n", sol);

	return 0;
}
