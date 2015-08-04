#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

#define MAXN 30
#define MAXA 20
#define INF (int)1e9

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int N, M, C, K;
bool air[MAXN];
int dist[MAXN];
bool vis[MAXN];
vii g[MAXN];

void solve(int n, int d, int a)
{
	if(n == C)
		return;

	vis[n] = 1;

	for(auto i : g[n])
	{
		int nD = d + i.second, nA = a - i.second;
		if(nA >= 0 && !vis[i.first] && nD < dist[i.first])
		{
			dist[i.first] = nD;
			solve(i.first, nD, air[i.first] ? MAXA : nA);
		}
	}

	vis[n] = 0;
}

int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d %d %d", &N, &M, &C, &K); C--;

	for(int i = 1; i < N; i++) dist[i] = INF;

	for(int i = 0; i < K; i++)
	{
		int t; scanf("%d", &t);
		air[--t] = 1;
	}

	for(int i = 0; i < M; i++)
	{
		int h, t, d; scanf("%d %d %d", &h, &t, &d);

		g[--h].push_back(ii(--t, d));
		g[t].push_back(ii(h, d));
	}

	solve(0, 0, MAXA);

	if(dist[C] == INF)
		printf("-1\n");
	else
		printf("%d\n", dist[C]);
	
	return 0;
}
