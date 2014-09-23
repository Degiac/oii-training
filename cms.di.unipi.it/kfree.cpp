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

int sol;
bool kfree[MAXN];

int Trova(int N, int K, int insieme[])
{
    for(int i = 0; i < N; i++)
        kfree[insieme[i]] = 1;

    if(K == 1) return 0;

    for(int i = 0; i < MAXN; i++)
        if(kfree[i])
        {
            sol++;
            if(i*K < MAXN) kfree[i*K] = 0;
        }

    return sol;
}
