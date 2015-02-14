#include        <cstdio>
#include        <cmath>
#include        <cstring>
#include        <vector>
#include        <queue>
#include        <stack>
#include        <set>
#include        <map>
#include        <utility>
#include        <algorithm>

#define pb      push_back
#define fi      first
#define se      second
#define mp      make_pair
#define sz(a)   (int)a.size()

#define EPS     1e-9

const long long INF = 10000000000;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n;

ll solve(int sx)
{
	ll sol = INF;
	ll delta = (sx*sx) + (4*n);

	if(floor(sqrt(delta)) != ceil(sqrt(delta))) return INF;
	
	ll x1 = (-sx + sqrt(delta))/2;
	ll x2 = (-sx - sqrt(delta))/2;
	
	if(x1 < 0) x1 = INF;
	if(x2 < 0) x2 = INF;
	
	sol = min(x1, x2);
	
	return sol;
}

bool checkSol(ll x, int s)
{
	int sum = 0;
	
	while(x)
	{
		sum += (x%10);
		x /= 10;
	}
	
	return (sum == s);
}

int main()
{
	#ifdef EVAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	scanf("%d", &n);
	
	ll sol = INF;
	
	for(int i = 0; i <= 90; i++)
	{
		ll t = solve(i);
		if(checkSol(t, i)) sol = min(sol, t);
	}

	if(sol == INF) printf("-1\n");
	else printf("%lld\n", sol);
	
	return 0;
}
