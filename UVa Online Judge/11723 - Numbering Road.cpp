#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

#define pb      push_back
#define fi      first
#define se      second
#define mp      make_pair
#define sz(a)   (int)a.size()

#define EPS     1e-9
#define INF     (int)1e9

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int main()
{
    int R, N, i = 1;
    while(scanf("%d %d", &R, &N), R && N)
    {
        R-=N;
        if(R <= 0) { printf("Case %d: 0\n", i++); continue; }
        int sol = R/N + (R % N != 0);
        printf("Case %d: ", i++);
        if(sol > 26) printf("impossible\n");
        else printf("%d\n", sol);
    }
    return 0;
}
