#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <utility>
#include <functional>
#include <queue>
#include <map>
#include <set>

#define MAX_N 1000005
#define INF 1000000005
#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int n, m, k, s[MAX_N], d[MAX_N], d2[MAX_N], v[MAX_N], v2[MAX_N];
vi g[MAX_N];

int main(){

    ios_base::sync_with_stdio(false);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        int t;
        cin>>t;
        t--;
        s[t] = 1;
    }
    for(int i=0;i<m;i++){
        int t, t2;
        cin>>t>>t2; t--; t2--;
        g[t].push_back(t2);
        g[t2].push_back(t);
    }

    for(int i=0;i<n;i++)
        d[i] = d2[i] = INF;

    queue<int> q;
    d[0] = 0;
    v[0] = 1;
    q.push(0);

    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i=0;i<(int)g[t].size();i++){
            int c = g[t][i];
            if(!v[c]){
                v[c] = 1;
                d[c] = d[t] + 1;
                q.push(c);
            }
        }
    }

    queue<int> q2;
    d2[n-1] = 0;
    v2[n-1] = 1;
    q2.push(n-1);

    while(!q2.empty()){
        int t = q2.front();
        q2.pop();
        for(int i=0;i<(int)g[t].size();i++){
            int c = g[t][i];
            if(!v2[c]){
                v2[c] = 1;
                d2[c] = d2[t] + 1;
                q2.push(c);
            }
        }
    }
    int sol = INF;
    for(int i=0;i<n;i++)
        if(s[i])
            sol = min(sol, d[i] + d2[i]);
    cout<<sol;
    return 0;

}

