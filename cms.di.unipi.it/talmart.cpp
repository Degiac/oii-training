#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int findMax(vector<int> numeri)
{
    vector<int> sequenza(numeri.size()-1);
    
    for(int i = 0; i < sequenza.size(); i++)
	sequenza[i] = numeri[i] - numeri[i+1];
    
    int mance = 0;
    int up = -1;
    
    for(int i = 0; i < sequenza.size(); i++)
	if(sequenza[i]*up > 0)
	{
	    mance++;
	    up *= -1;
	}
	
    return mance;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N, P;
    vector<int> persone;
    persone.push_back(0);
    int mance = 0;
    
    int pos = 0;
    
    in >> N >> P;
    
    for(int i = 0; i < N; i++)
    {
	int n;
	in >> n;
	persone.push_back(n);
    }
    
    out << findMax(persone);
    
    return 0;
}
