#include <fstream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

struct torre
{
    int h;
    int c;
    int sol;
    list <int> basse;
    torre(): sol(0) {}
};

void DFS(vector<torre> &grafo)
{
    vector<bool> visited;
    visited.resize(grafo.size());
    stack<int> s;
    s.push(0);

    while(!s.empty())
    {
	int c = s.top();
	s.pop();

	if(!visited[c])
	{
	    grafo[c].sol = grafo[c].c;
	    visited[c] = true;
	    for(list<int>::iterator i = grafo[c].basse.begin(); i != grafo[c].basse.end(); i++)
	    {
		s.push(*i);
		grafo[c].sol = max(grafo[c].sol, grafo[*i].sol+grafo[c].c);
	    }
	}
    }
}

int main(int argc, char* args[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;
    vector<torre> grafo;

    in >> N;

    grafo.resize(N+1);

    grafo[0].h = 1000;
    grafo[0].c = 0;

    int tot = 0;

    for(int i = 1; i <= N; i++)
    {
	in >> grafo[i].h >> grafo[i].c;
	tot += grafo[i].c;
	for(int j = 0; j < i; j++)
	    if(grafo[i].h < grafo[j].h) grafo[j].basse.push_back(i);
    }

    DFS(grafo);

    int max = 0;

    for(int i = 1; i <= N; i++)
	if(grafo[i].sol > max) max = grafo[i].sol;

    out << tot-max;

    return 0;
}
