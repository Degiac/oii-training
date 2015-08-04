#include <cstdio>
#include <algorithm>
#include <utility>

#define fi first
#define se second

#define MAXN 100000

using namespace std;

typedef pair<int, int> ii;
ii atleti[MAXN];

inline int readInt()
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

int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N = readInt(), K = readInt();

	for(int i = 0; i < N; i++)
	{
		int f = readInt(), p = readInt();
		atleti[i].fi = f - 3 * p / 2;
		atleti[i].se = i+1;
	}

	nth_element(atleti, atleti+K, atleti+N, greater<ii>());

	for(int i = 0; i < K; i++)
		printf("%d\n", atleti[i].se);

	return 0;
}
