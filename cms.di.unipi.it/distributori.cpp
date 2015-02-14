#include        <cstdio>
#include        <cmath>
#include        <cstring>
#include        <vector>
#include        <queue>
#include        <stack>
#include        <set>
#include        <map>
#include        <utility>
#include        <algorithm>

#define pb      push_back
#define fi      first
#define se      second
#define mp      make_pair
#define sz(a)   (int)a.size()

#define EPS     1e-9
#define INF     1e9

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    freopen("input.txt", "r", stdin);
    #ifdef EVAL
    freopen("output.txt", "w", stdout);
    #endif

    int N, M, K;
    vi distributori;

    scanf("%d %d %d", &N, &M, &K);

    distributori.reserve(N);

    for(int i = 0; i < N; i++)
    {
        int temp; scanf("%d", &temp);
        distributori.pb(temp);
    }

    int currPos = M;
    int sol = 0;

    while(currPos < K)
    {
        sol++;
        currPos = *(upper_bound(distributori.begin(), distributori.end(), currPos)-1);
        currPos += M;
    }

    printf("%d\n", sol);

    return 0;
}
