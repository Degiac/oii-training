#include <fstream>
#include <vector>
#include <queue>
#include <list>
#include <cstring>

#include <iostream>

using namespace std;

void BFS(vector<list<pair<int, int> > > graph, vector<pair<int, int> > &max)
{
    queue<int> q;
    q.push(0);
    
    while(!q.empty())
    {
	int c = q.front();
	q.pop();
	
	for(list<pair<int, int> >::iterator i = graph[c].begin(); i != graph[c].end(); i++)
	{
	    if(c == 0)
	    {
		max[i->first].first = 0;
		max[i->first].second = i->second;
		q.push(i->first);
	    }
	    else
	    {
		int peso = i->second;
		int to = i->first;
		
		int newSecondMax = max[c].first;
		int newMax = max[c].second;
		if(peso > max[c].first && peso <= max[c].second)
		{
		    newSecondMax = peso;
		}
		if(peso > max[c].second)
		{
		    newSecondMax = newMax;
		    newMax = peso;
		}
		
		pair<int, int> newMaxPair = make_pair(newSecondMax, newMax);
		
		if(newMaxPair < max[to] || (max[to].first == 0 && max[to].second > newMaxPair.second))
		{
		    max[to] = newMaxPair;
		    q.push(to);
		}
	    }
	}
    }
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N, M;
    vector<list<pair<int, int> > > graph;
    vector<pair<int, int> > max;
    in >> N >> M;
    
    graph.resize(N);
    max.resize(N);
    
    for(int i = 0; i < N; i++)
	max[i].first = max[i].second = 1000001;
    
    for(int i = 0; i < M; i++)
    {
	int t1, t2, t3;
	in >> t1 >> t2 >> t3;
	
	graph[t1-1].push_back(make_pair(t2-1, t3));
    }
    
    BFS(graph, max);
    
    out << max[N-1].first;
    
    return 0;
    
}