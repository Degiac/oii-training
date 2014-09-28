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
        int N, p; scanf("%d", &N);
        int med = N/2;
        for(int j = 0; j < N; j++)
        {
            scanf("%d", &p);
            if(j == med) printf("Case %d: %d\n", i+1, p);
        }
    }

    return 0;
}
