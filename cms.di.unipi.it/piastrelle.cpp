#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* args[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N;
    vector<int> sol;
    vector<vector <int> > dopo;
    
    in >> N;
    for(int i = 0; i < N; i++)
	sol.push_back(1);
    
    bool exit = false;
    int len = N-1;
    
    while(true)
    {
	dopo.push_back(sol);
	dopo.back().push_back(len);
	    
	while(next_permutation(sol.begin(), sol.begin()+len+1))
	{	  
	    dopo.push_back(sol);
	    dopo.back().push_back(len);
	}
	
	int j = len;
	
	while(sol[j] != 1 && j > 0) j--;
	
	if(j == 0) break;
	
	sol[j] = 2;
	sol[j-1] = 2;
	len--;
    }
    
    sort(dopo.begin(), dopo.end());
    
    for(int i = 0; i < dopo.size(); i++)
    {
	for(int j = 0; j <= dopo[i].back(); j++)
		if(dopo[i][j] == 1) out << "[O]";
		else if(dopo[i][j] == 2) out << "[OOOO]";
	out << "\n";
    }
    
    return 0;
}
