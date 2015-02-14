#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <cassert>
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

vi graph[MAXN];
int B[MAXN], C[MAXN];
int sol; 

void solve(int nodo, int minSoFar)
{
    int toPass = min(minSoFar, B[nodo]);
    for(int i = 0; i < sz(graph[nodo]); i++)
        solve(graph[nodo][i], toPass);
        
    if(B[nodo] > minSoFar) sol++;
}

int licenzia(int N, int B[], int C[])
{
    sol = 0;
    
    for(int i = 1; i < N; i++)
    {
        graph[C[i]].pb(i);
    }

    solve(0, INF);

    return sol;
}

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(2 == fscanf(fr, "%d %d", &B[i], &C[i]));

    fprintf(fw, "%d\n", licenzia(N, B, C));
    fclose(fr);
    fclose(fw);
    return 0;
}
