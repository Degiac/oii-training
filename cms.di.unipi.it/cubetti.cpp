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

bool col[MAXN];

void Vernicia(int indice, int colore);

void Diversifica(int N, int colore[])
{
    vii cubi;
    for(int i = 0; i < N; i++) { col[colore[i]] = 1; cubi.pb(ii(colore[i], i)); }
    sort(cubi.begin(), cubi.end());
    
    int colIdx = 1;

    for(int i = 1; i < N; i++)
        if(cubi[i].fi == cubi[i-1].fi)
        {
            while(col[colIdx]) colIdx++;
            col[colIdx] = 1;
            Vernicia(cubi[i].se, colIdx);
        }
}
