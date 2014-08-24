#include <fstream>
#include <vector>
#include <list>
#include <queue>

#include <iostream>

using namespace std;

vector<int> BFS(vector<list<int> > &grafo, vector<bool> &visited, int n)
{
    queue<int> q;
    vector<int> connections;
    q.push(n);

    while(!q.empty())
    {
	int c = q.front();
	q.pop();
	if(!visited[c])
	{
	    visited[c] = true;

	    connections.push_back((int)grafo[c].size());
	    for(list<int>::iterator i = grafo[c].begin(); i != grafo[c].end(); i++)
		q.push(*i);
	}
    }

    return connections;
}

bool isLineare(vector<int> &net)
{
    if(net.size() < 2) return false;

    int uno = 0;

    for(int i = 0; i < (int)net.size(); i++)
    {
        if(net[i] == 1) uno++;
        if(net[i] > 2 || uno > 2) return false;
    }

    if(uno == 2) return true;
    else return false;
}

bool isAnello(vector<int> &net)
{
    if(net.size() < 3) return false;

    for(int i = 0; i < (int)net.size(); i++)
    {
        if(net[i] != 2) return false;
    }

    return true;
}

bool isStella(vector<int> &net)
{
    if(net.size() < 4) return false;

    bool foundCenter = false;

    for(int i = 0; i < (int)net.size(); i++)
    {
        if(net[i] == 1) continue;
        else if(foundCenter) return false;
             else foundCenter = true;
    }

    return true;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, V;
    int lin, ane, ste;
    vector<list<int> > grafo;
    vector<vector<int> > nets;
    vector<bool> visited;

    lin = ane = ste = 0;

    in >> N >> V;

    grafo.resize(N);
    visited.resize(N);

    int temp1, temp2;
    for(int i = 0; i < V; i++)
    {
        in >> temp1 >> temp2;
        grafo[temp1-1].push_back(temp2-1);
        grafo[temp2-1].push_back(temp1-1);
    }

    for(int i = 0; i < N; i++)
        if(!visited[i])
            nets.push_back(BFS(grafo, visited, i));

    for(int i = 0; i < (int)nets.size(); i++)
    {
        if(isLineare(nets[i])) { lin++; continue; }
        if(isAnello(nets[i])) { ane++; continue; }
        if(isStella(nets[i])) { ste++; }
    }

    out << lin << " " << ane << " " << ste << "\n";

    return 0;
}
