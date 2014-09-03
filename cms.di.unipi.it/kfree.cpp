#include <fstream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int n, k;
    
    in >> n >> k;
    
    bool v[1000001] = { false };
    
    int temp;
    int sol = 0;
    
    for(int i = 0; i < n; i++)
    {
	in >> temp;
	v[temp] = true;
    }
    
    for(int i = 1; i <= 1000000/k; i++)
    {
	if(v[i]) v[i*k] = false;
    }
    
    for(int i = 1; i <= 1000000; i++)
	if(v[i]) sol++;
    
    out << sol;
	
    return 0;
}