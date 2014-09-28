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
    printf("PERFECTION OUTPUT\n");
    int N;
    while(scanf("%d", &N), N)
    {
        int sum = 1;
        for(int div = 2; div*div <= N; div++)
        {
            if(N%div == 0)
            {
                sum += div;
                if(div*div != N) sum += N/div;
            }
        }
        if(N < 10) printf("    ");
        else if(N < 100) printf("   ");
        else if(N < 1000) printf("  ");
        else if(N < 10000) printf(" ");

        printf("%d  ", N);
        if(N == 1) printf("DEFICIENT\n");
        else if(sum == N) printf("PERFECT\n");
        else if(sum < N) printf("DEFICIENT\n");
        else printf("ABUNDANT\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
