#include <cstdio>
#include <algorithm>
#include <utility>

#define fi first
#define se second

#define MAXN 50

using namespace std;

typedef pair<int, int> ii;

ii turni[MAXN];

int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N, K; scanf("%d %d", &K, &N);

	for(int i = 0; i < N; i++)
		scanf("%d %d", &turni[i].fi, &turni[i].se);

	sort(turni, turni+N);

	int lim = 0;
	int i = 0;
	int sol = 0;

	while(lim < K)
	{
		int nLim = 0;
		for(; i < N && turni[i].fi <= lim; i++)
			nLim = max(nLim, turni[i].se+1);

		lim = nLim;
		sol++;
	}

	printf("%d\n", sol);

	return 0;
}
