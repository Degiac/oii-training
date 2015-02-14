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
#define MAXN    30005

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
    
    int N;
    char numeri[MAXN][25];
    
    scanf("%d\n", &N);
    
    for(int i = 0; i < N; i++)
        scanf("%s\n", numeri[i]);
        
    int sol = 0;
    bool exit = 0;
    
    for(; sol < strlen(numeri[0]) && !exit; sol++)
    {
        for(int i = 1; i < N; i++)
        {
            if(numeri[i][sol] != numeri[0][sol]) { exit = 1; break; }
        }   
    }
    
    printf("%d\n", sol-1);
    
    return 0;
}
