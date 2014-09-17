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
    int t; scanf("%d", &t);
    for(int te = 1; te <= t; te++)
    {
        int s; scanf("%d", &s);
        vi arr(s);
        for(int i = 1; i < s; i++)
    scanf("%d", &arr[i]);

        int sol = 0, sum = 0, currBeg = 0, beg = 0, end = 0;
        for(int i = 1; i < s; i++)
        {
            sum += arr[i];
            if(sum > sol || (sum == sol && i - currBeg > end - beg))
            {
                sol = sum;
                end = i;
                beg = currBeg;
            }
            if(sum < 0)
            {
                sum = 0;
                currBeg = i;
            }
        }

        if(sol > 0) printf("The nicest part of route %d is between stops %d and %d\n", te, beg+1, end+1);
        else printf("Route %d has no nice parts\n", te);
    }

    return 0;
}
