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

int valuta(int N, int* H)
{
    int sol = 0;
    int posMax = 0, max = H[0];
    vi massimi(N); massimi[0] = H[0];
    for(int i = 1; i < N; i++)
    { 
        if(H[i] > max)
        { 
            posMax = i; 
            max = H[i]; 
        } 
        massimi[i] = max; 
    }
    
    max = H[N-1]; massimi[N-1] = H[N-1];
    for(int i = N-2; i > posMax; i--) { if(H[i] > max) max = H[i]; massimi[i] = max; }

    int curr = massimi[0]; int cont = 1;
    for(int i = 1; i < N; i++)
    {
        if(massimi[i] == curr) cont++;
        else
        {
            sol += (cont-1);
            cont = 1;
            curr = massimi[i];
        }
    }

    if(cont != 0) sol += (cont-1);

    return sol;
}

void progetta(int N, int K, int *H)
{
    int i = 0;
    for(; i <= K; i++) H[i] = K-i+1;
    for(; i < N; i++) H[i] = K+i+1;
}
