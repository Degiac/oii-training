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

int ContaOperazioni(int N, int K, int* secchi)
{
    sort(secchi, secchi+N);

    int sol = 0;
    int i = 0;
    int j = N-1;
    while(secchi[i] < K && i < N && j > i && secchi[j] > K)
    {
        int toAdd = K-secchi[i];
        int addable = secchi[j] - K;
        if(addable > toAdd)
        {
            secchi[i] += toAdd;
            sol += toAdd;
            secchi[j] -= toAdd;
        }
        else
        {
            secchi[i] += addable;
            sol += addable;
            secchi[j] -= addable;
            j--;
        }
        if(secchi[i] == K) i++; 
    }

    for(int i = 0; i < N; i++)
        sol += abs(secchi[i]-K);

    return sol;
}
