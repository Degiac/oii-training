#include <fstream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

void BFS(vector<list<int> > &grafo, vector<bool> &visited, int p)
{
    queue<int> q;
    q.push(p);
    
    while(!q.empty())
    {
	int current = q.front();
	q.pop();
	if(!visited[current])
	{
	    visited[current] = true;
	    for(list<int>::iterator i = grafo[current].begin(); i != grafo[current].end(); i++)
		q.push(*i);
	}
    }
}

int main(int argc, char* args[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N, M;
    vector<bool> visited;
    vector<list<int> > grafo;
    
    in >> N >> M;
    grafo.resize(N);
    visited.resize(N);
    
    int x, z;
    
    for(int i = 0; i < M; i++)
    {
	in >> x >> z;
	grafo[x].push_back(z);
	grafo[z].push_back(x);
    }
    
    int cont = -1;
    
    for(int i = 0; i < N; i++) visited[i] = false;
    
    for(int i = 0; i < N; i++)
	if(!visited[i])
	{
	    cont++;
	    BFS(grafo, visited, i);
	}
	
    out << cont;
    
    return 0;
}

