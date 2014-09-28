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
    int T; scanf("%d", &T);
    for(int i = 0; i < T; i++)
    {
        float d, u, v; scanf("%f %f %f", &d, &v, &u);

        if(u <= v || v == 0 || u == 0) { printf("Case %d: can't determine\n", i+1); continue; }

        float t1 = d/u, t2 = d/sqrt(u*u - v*v);

        printf("Case %d: %.3f\n", i+1, fabs(t1-t2));
    }

    return 0;
}
