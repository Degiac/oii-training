#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

#define MAX_N 1000
#define INF 1000000005
#define MOD 1000000007

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

int d[MAX_N], sol;
vii g[MAX_N];

int main(){

#ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m; scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int t, t2, dist;
        scanf("%d %d %d", &t, &t2, &dist);
        g[t-1].push_back(ii(t2-1, dist));
        g[t2-1].push_back(ii(t-1, dist));
    }

    priority_queue< ii, vii, greater<ii> > pq;
    
    for(int i = 1; i < n; i++)
        d[i] = INF;

    pq.push(ii(0, 0));

    while(!pq.empty()){
	ii c = pq.top(); pq.pop();
        int currN = c.second;
        int currD = c.first;

        if(currD > d[currN])
            continue;
        for(int i = 0; i < (int)g[currN].size(); i++){
            if(d[g[currN][i].first] > d[currN] + g[currN][i].second){
                d[g[currN][i].first] = d[currN] + g[currN][i].second;
                pq.push(ii(d[currN] + g[currN][i].second, g[currN][i].first));
            }
        }
    }

    for(int i = 0; i < n; i++)
        if(d[i] <= (i + 1) * 10)
            sol++;

    printf("%d", sol);
    

    return 0;
}

