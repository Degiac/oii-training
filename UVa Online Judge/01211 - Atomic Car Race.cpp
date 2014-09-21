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
#define MAXN    105
#define MAXDIST 10005

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

double B, V, E, F;
int N, R, dist[MAXN];
double dp[MAXN], t[MAXDIST];

void precomp()
{
    t[0] = 0;
    for(int i = 0; i < R; i++)
        t[i+1] = 1/(V - F*(double)(R - i)) + t[i];

    for(int i = R; i < dist[N-1]; i++)
        t[i+1] = 1/(V - E*(double)(i - R)) + t[i];
}

int main()
{
    while(scanf("%d", &N), N)
    {
        for(int i = 0; i < N; i++)
            scanf("%d", dist+i);

        scanf("%lf", &B);
        scanf("%d %lf %lf %lf", &R, &V, &E, &F);

        precomp();

        dp[0] = t[dist[0]];

        for(int i = 1; i < N; i++)
        {
            dp[i] = t[dist[i]];   
            for(int j = 0; j < i; j++)
                dp[i] = min(dp[i], dp[j]+t[dist[i]-dist[j]]+B);    
        }
        
        printf("%.4lf\n", dp[N-1]);
    }

    return 0;
}
