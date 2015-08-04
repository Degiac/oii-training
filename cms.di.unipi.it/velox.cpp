#include <vector>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAXN 10000
#define MAXM 100000

using namespace std;

typedef vector<int> vi;

vi graph[MAXN];
int dp[MAXM];
int to[MAXM];
int ve[MAXM];

int readInt()
{
	int n = 0;
	char c = getchar_unlocked();
	
	while(c < '0' || c > '9') c = getchar_unlocked();
	
	while(c >= '0' && c <= '9')
	{
		n *= 10;
		n += (c - '0');
		c = getchar_unlocked();
	}
	
	return n;
}

int dfs(int n, int prev)
{
	int res = 0;
	
	for(int i : graph[n])	
		if(prev < ve[i]) res = max(res, (dp[i] < 0) ? dp[i] = dfs(to[i], ve[i]) : dp[i]);
	
	return res + 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N = readInt(), M = readInt();
	
	for(int i = 0; i < M; i++)
	{
		int da = readInt(); 
		to[i] = readInt(); ve[i] = readInt();
		graph[da].push_back(i);
		dp[i] = -1;
	}
	
	for(int i = 0; i < N; i++)
		dfs(i, 0);
	
	int sol = 0;
	
	for(int i = 0; i < M; i++)
		sol = max(sol, dp[i]);
	
	printf("%d\n", sol);
	
	return 0;
}
