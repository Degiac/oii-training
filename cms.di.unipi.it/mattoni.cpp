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
#define MAXN    1000005

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int mattoni[MAXN];

int main()
{
    #ifndef EVAL
    freopen("input.txt", "r", stdin);
    #endif
    
    int N, M; scanf("%d %d", &N, &M);
    
    for(int i = 0; i < M; i++)
    {
        int s, q; scanf("%d %d", &s, &q);
        mattoni[s]++; mattoni[q+1]--;
    }
    
    for(int i = 2; i <= N; i++)
        mattoni[i] += mattoni[i-1];
    
    sort(mattoni+1, mattoni+N+1);
  
    printf("%d\n", mattoni[N/2+1]);
    
    return 0;
}
