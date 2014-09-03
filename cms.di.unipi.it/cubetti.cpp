#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int n;
    
    in >> n;
    
    vector<int> cubetti(n);
    
    int temp;
    
    for(int i = 0; i < n; i++)
    {
	in >> temp;
	temp--;
	cubetti[temp]++;
    }
    
    int sol = 0;
    
    for(int i = 0; i < n; i++)
	if(cubetti[i] == 0) sol++;
	
    out << sol;
    
    return 0;
}
