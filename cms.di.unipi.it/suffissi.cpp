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
#define MAXN    100005

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int main()
{
    #ifndef EVAL
    freopen("input.txt", "r", stdin);
    #endif
    
    int num[MAXN];
    int diff[MAXN];
    
    int N, M; scanf("%d %d", &N, &M);
    
    for(int i = 1; i <= N; i++)
        scanf("%d", num+i);
        
    set<int> found;
        
    for(int i = N; i > 0; i--)
    {
        found.insert(num[i]);
        diff[i] = found.size();
    }
    
    for(int i = 0; i < M; i++)
    {
        int q; scanf("%d", &q);
        printf("%d\n", diff[q]);
    }
    

    return 0;
}
