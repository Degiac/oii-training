#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <list>
#include <cstring>

using namespace std;

int DFS(vector<list<int> > &grafo, vector<list<int> > &albero, vector<int> &totali, vector<int> &pop, vector<bool> &visited, int c)
{

    int toAdd = 0;
    visited[c] = true;
    for(list<int>::iterator i = grafo[c].begin(); i != grafo[c].end(); i++)
        if(!visited[*i])
        {
            albero[c].push_back(*i);
            toAdd += DFS(grafo, albero, totali, pop, visited, *i);
        }

    totali[c] = toAdd + pop[c];
    return totali[c];
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;
    in >> N;
    vector<list<int> > grafo(N);
    vector<list<int> > albero(N);
    vector<int> pop(N);
    vector<int> totali(N);
    vector<int> sol(N);
    vector<bool> visited(N);

    for(int i = 0; i < N; i++)
        in >> pop[i];

    int t1, t2;

    for(int i = 1; i < N; i++)
    {
        in >> t1 >> t2;
        grafo[t1].push_back(t2);
        grafo[t2].push_back(t1);
    }

    int tot = DFS(grafo, albero, totali, pop, visited, 0);

    for(int i = 0; i < N; i++)
    {
        int tempMax = 0;
        for(list<int>::iterator j = albero[i].begin(); j != albero[i].end(); j++)
            tempMax = max(tempMax, totali[*j]);

        sol[i] = max(tempMax, tot-totali[i]);
    }

    int finalSol = sol[0];

    for(int i = 1; i < N; i++)
        finalSol = min(finalSol, sol[i]);

    out << finalSol << endl;

    return 0;
}
