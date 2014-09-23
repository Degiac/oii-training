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

bool vis[MAXN];
vi rete,graph[MAXN];

void count(int i)
{
    queue<int> q; q.push(i);
    rete.clear();

    while(!q.empty())
    {
        int c = q.front(); q.pop();
        if(!vis[c])
        {
            vis[c] = true;
            rete.pb(sz(graph[c]));
            for(int i = 0; i < sz(graph[c]); i++)
                q.push(graph[c][i]);
        }
    }
}

bool isLin()
{
    if(sz(rete) < 2) return false;
    int c1 = 0; 
    for(int i = 0; i < sz(rete); i++)
    {
        if(rete[i] == 1) { c1++; continue; }
        if(rete[i] != 2) return false;
    }
    if(c1 != 2) return false;
    return true;

}

bool isAne()
{
    if(sz(rete) < 3) return false;
    for(int i = 0; i < sz(rete); i++)
        if(rete[i] != 2) return false;
    return true;
}

bool isSte()
{
    if(sz(rete) < 4) return false;
    bool fcen = false;
    for(int i = 0; i < sz(rete); i++)
    {
        if(rete[i] != 1)
        {
            if(fcen) return false;
            fcen = true;
        }
    }
    return true;
}

void Analizza(int N, int M, int A[], int B[], int T[])
{
    for(int i = 0; i < M; i++)
    {
        graph[A[i]].pb(B[i]);
        graph[B[i]].pb(A[i]);
    }

    T[0] = T[1] = T[2] = 0;

    for(int i = 1; i <= N; i++)
        if(!vis[i])
        {
            count(i);
            if(isLin()) { T[0]++; continue; }
            if(isAne()) { T[1]++; continue; }
            if(isSte()) T[2]++; 
        }
}
