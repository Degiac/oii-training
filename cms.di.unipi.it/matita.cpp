#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>

#include <iostream>


using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");       

    int N, V, A, B;
    vector<int> sol;
    stack<int> tempS;
    vector<list<int> > grafo;
    vector<int> archi;
    
    in >> N >> V >> A >> B;
    
    grafo.resize(N+1);
    archi.resize(V);
    
    int temp1, temp2;
    
    for(int i = 0; i < V; i++)
    {
	in >> temp1 >> temp2;
	archi[i] = temp1 + temp2;
	grafo[temp1].push_back(i);
	grafo[temp2].push_back(i);
    }
    
    int c = A;
    
    while(sol.size() < V)
    {
	bool hasNeighbour = false;
	    
	for(list<int>::iterator i = grafo[c].begin(); i != grafo[c].end(); i++)
	    if(archi[*i] > 0)
	    {
		tempS.push(c);
		hasNeighbour = true;
		int next = archi[*i]-c;
		archi[*i] = -1;
		grafo[c].remove(*i);
		c = next;
		grafo[c].remove(*i);
		break;
	    }
	
	if(!hasNeighbour)
	{
	    sol.push_back(c);
	    c = tempS.top();
	    tempS.pop();
	}
    }
    
    sol.push_back(A);

    for(int i = sol.size() - 1; i > 0; i--)
	out << sol[i] << " " << sol[i-1] << "\n";
    
    return 0; 
}