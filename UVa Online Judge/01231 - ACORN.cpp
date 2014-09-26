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
#define MAXN    2005

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int T, H, F, dp[MAXN], trees[MAXN][MAXN];

int main()
{
    int test; scanf("%d", &test);
    while(test--)
    {
        memset(dp, -1, sizeof dp); memset(trees, 0, sizeof trees);
        scanf("%d %d %d", &T, &H, &F);

        for(int i = 0; i < T; i++)
        {
            int rep; scanf("%d", &rep);
            while(rep--)
            {
                int t; scanf("%d", &t); trees[i][t]++;
            }
        }
        
        for(int t = 0; t < T; t++)
            dp[H] = max(dp[H], trees[t][H]);        

        for(int h = H-1; h >= 0; h--)
            for(int t = 0; t < T; t++)
            {
                trees[t][h] += max(trees[t][h+1], (h+F <= H) ? dp[h+F] : 0);
                dp[h] = max(dp[h], trees[t][h]);
            }
        printf("%d\n", dp[0]);
    }
    return 0;
}
