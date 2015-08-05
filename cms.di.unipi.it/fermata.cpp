#include <cstdio>
#include <utility>
#include <vector>

#define maxn 1000000
#define maxc 10000000

#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;

int n, s, c;
ii tab[maxc];
int memo[maxn];
int strip[maxn];
vector<int> solutions;

int visit(int state, int position) {
	int tabIdx = state*c + strip[position];
	int memoIdx = state*n + position;

	if(memo[memoIdx] != 0) return memo[memoIdx];

	if(position == 0) return memo[memoIdx] = 1;

	memo[memoIdx] = 2;

	int newState = tab[tabIdx].fi;
	int newPos = position + tab[tabIdx].se;

	return memo[memoIdx] = visit(newState, newPos);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d %d %d", &n, &s, &c);

	for(int i = 0; i < s*c; i++) {
		int sc, cl, ns, sp; scanf("%d %d %d %d", &sc, &cl, &ns, &sp);

		tab[sc*c + cl] = ii(ns, sp);
	}

	for(int i = 0; i < n; i++) {
		scanf("%d", strip+i);
	}

	for(int i = 0; i < n; i++) {
		if(visit(0, i) == 1) solutions.push_back(i);
	}

	printf("%d\n", solutions.size());

	for(auto i : solutions) {
		printf("%d\n", i);
	}

	return 0;
}
