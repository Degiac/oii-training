#include <queue>
#include <utility>
#include <iostream>
#include <fstream>
#include <list>

#define MAXN 100005
#define INF 1000000000

using namespace std;

typedef pair<int, int> ii;
list<ii> graph[MAXN];
int visited[MAXN];

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[])
{
    for(int i = 0; i < M; i++)
    {
	int h = R[i][0], t = R[i][1];
	graph[h].push_back(ii(L[i], t));
	graph[t].push_back(ii(L[i], h));
    }

    priority_queue<ii, vector<ii>, greater<ii> > pq;
    for(int i = 0; i < K; i++) { pq.push(ii(0, P[i])); visited[P[i]] = 1; }

    while(!pq.empty())
    {
	ii c = pq.top(); pq.pop();
	if(visited[c.second] == 2) continue;
	if(visited[c.second] == 0) { visited[c.second] = 1; continue; }
	visited[c.second] = 2;
	if(c.second == 0) return c.first;
	for(list<ii>::iterator i = graph[c.second].begin(); i != graph[c.second].end(); i++)
	    pq.push(ii(c.first + i->first, i->second));
    }

    return INF;    
}


#ifndef EVAL
int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int N, M, K;
    
    in >> N >> M >> K;
    
    int R[M][2];
    int L[M];
    int P[K];
    
    for(int i = 0; i < M; i++)
    {
	in >> R[i][0] >> R[i][1];
    }
    
    for(int i = 0; i < M; i++)
	in >> L[i];
    
    for(int i = 0; i < K; i++)
	in >> P[i];

    cout << travel_plan(N, M, R, L, K, P);
    
    return 0;
}
#endif 
