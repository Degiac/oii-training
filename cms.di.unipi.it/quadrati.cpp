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
    double a, b; scanf("%lf %lf", &a, &b);
    
    int min = (int)ceil(sqrt(a));
    int max = (int)floor(sqrt(b));
    
    if(min*min > b) printf("0\n");
    else printf("%d\n", max-min+1);
    
    return 0;
}
