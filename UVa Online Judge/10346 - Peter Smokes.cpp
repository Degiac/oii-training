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

int main()
{
    int cig, K;
    while(scanf("%d %d", &cig, &K) != EOF)
    {
        int sol = cig;
        int butts = cig;
        
        while(butts >= K)
        {
            int newCig = butts/K;
            sol += newCig;
            butts = (butts%K)+newCig;
        }

        printf("%d\n", sol);
    }
}
