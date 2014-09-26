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

void Accendi(int N, int acceso[], int pulsante[])
{
    for(int i = N; i > 0; i--)
    {
        int cont = acceso[i];
        for(int j = i; j <= N; j += i)
            cont += pulsante[j];

        if(cont%2 == 0) pulsante[i] = 1;
    }
}
