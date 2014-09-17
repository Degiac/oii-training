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

#ifndef EVAL
#include "grader.cpp"
#endif

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

int solve(int N, int* vals)
{
    int sol = 0;
    vi divs;
    
    int div = 1; 
    for(; div*div < N; div++)
        if(N%div == 0)
        {
            divs.pb(div);
            if(div != 1) divs.pb(N/div);
        }
    if(div*div == N) divs.pb(div);
    
    sort(divs.begin(), divs.end());
    int maxDiv = divs.back();

    vector<vi> divi; divi.resize(sz(divs));
    for(int i = 0; i < sz(divs); i++)
        for(int j = i; j < sz(divs); j++)
            if(divs[j]%divs[i] == 0) divi[i].pb(j);

    vector<bool> check; check.assign(maxDiv*sz(divs), 0);

    for(int j = 0; j < sz(divs); j++)
    {
        div = divs[j];
        for(int i = 0; i < div; i++)
        {
            if(check[i*sz(divs)+j]) { sol++; continue; }
                               
            int c;
            for(c = i + div; c < N && vals[c] == vals[i]; c += div);

            if(c >= N)
            {
		sol++;
                for(int l = i; l < maxDiv; l+=div)
                    for(int k = 0; k < sz(divi[j]); k++)
                        for(int i = 0; i*div+l < divi[j][k]; i++)
				check[(i*div+l)*sz(divs)+divi[j][k]] = 1;
            }
        }
    }

    return sol;
}
