#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int findMax(vector<int> numeri)
{
    if(numeri.size() <= 2)	return 1;
    vector<int> sequenza(numeri.size()-1);
    
    for(int i = 0; i < numeri.size()-1; i++)
	sequenza[i] = numeri[i] - numeri[i+1];
    
    int posPrimo = 0;
    
    while(posPrimo < sequenza.size() && sequenza[posPrimo] == 0)
	posPrimo++;
    
    if(posPrimo >= sequenza.size()-2)	return 1;
    
    int primo = sequenza[posPrimo];
    
    int lunghezza = 2;
    
    for(int i = posPrimo+1; i < sequenza.size(); i++)
	if(primo*sequenza[i] < 0)
	{
	    primo *= -1;
	    lunghezza++;
	}
	
    return lunghezza;
}

int main(int argc, char* args[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N;
    vector <int> numeri;

    in >> N;
    numeri.resize(N);
    for(int i = 0; i < N; i++) in >> numeri[i];
    
    out << findMax(numeri);
    
    return 0;
}
