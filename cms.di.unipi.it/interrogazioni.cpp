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
#define MAXN    10005

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N, K;
    int diff[MAXN];
    scanf("%d %d", &N, &K);
    
    for(int i = 0; i < N; i++)
        scanf("%d", diff+i);
        
    sort(diff, diff+N);
    
    int sol = INF;
    
    for(int i = 0; i < N-K+1; i++)
        sol = min(sol, diff[i+K-1]-diff[i]); 
 
    printf("%d\n", sol);
 
    return 0;
}
