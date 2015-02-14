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
#define INF     1e9
#define MAXN    10005

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    freopen("input.txt", "r", stdin);
    #ifdef EVAL
    freopen("output.txt", "w", stdout);
    #endif

    int N, M, A, B, sol[MAXN];

    scanf("%d %d %d %d", &N, &M, &A, &B);

    sol[0] = min(A, B);

    for(int i = 1; i < N; i++)
        sol[i] = min(sol[i-1]+A, ((i-M < 0) ? 0 : sol[i-M]) + B); 

    printf("%d\n", sol[N-1]);

    return 0;
}
