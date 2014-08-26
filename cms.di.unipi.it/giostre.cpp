#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    vector<bool> visitati;
    int A, B;
    
    in >> A >> B;
    
    visitati.resize(A);
    
    int i = 0;
    int cont = 0;
    
    while(!visitati[i])
    {
	visitati[i] = true;
	cont++;
	i = (i+B)%A;
    }
    
    out << cont << " ";
    
    bool trovato = false;
    int j = 19;
    
    while(!trovato)
    {
	j++;
	for(int l = 0; l < A; l++) visitati[l] = false;
	i = 0;
	cont = 0;
	while(!visitati[i])
	{
	    visitati[i] = true;
	    cont++;
	    i = (i+j)%A;
	}
	if(cont == A) trovato = true;
    }
    
    out << j;
    
    return 0;
}
