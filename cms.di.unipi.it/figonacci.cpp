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
    freopen("input.txt", "r", stdin);
    #ifdef EVAL
    freopen("output.txt", "w", stdout);
    #endif
    
    int N, K; scanf("%d %d", &N, &K);
    
    int n = 1;
    int gN = 0;
    int sum = K-1;
    
    for(; n < N; n++)
    {
        int temp = ((((n%K)*(gN%K))%K - sum)+K)%K;
        sum = (sum + gN)%K;
        gN = temp;
    }
    
    printf("%d\n", gN);
    
    return 0;
}
