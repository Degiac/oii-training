#include <fstream>
#include <vector>
#define MAXN 10000

int B[MAXN], N;

using namespace std;
vector<int> grafo[MAXN];
int recluta(int corrente)
{
    int somma=0;
    int limite = (int)grafo[corrente].size(); 
    for(int i=0; i<limite; i++)
        somma += recluta(grafo[corrente][i]);
        
    if(somma>B[corrente]) return somma;
    else return B[corrente];
}

int main()
{
    int var;
    ifstream in("input.txt");
    ofstream out("output.txt");
    in>>N;
    
    for(int i=0; i<N; i++)
    {
        in>>B[i];
        in>>var;
        if(var != -1)
            grafo[var].push_back(i);
    }
    out<<recluta(0);
    
    return 0;
}
