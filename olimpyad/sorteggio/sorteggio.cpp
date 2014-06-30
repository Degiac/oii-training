#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* args[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int m;
    vector<int> squadre;
    
    in >> m;
    
    squadre.resize(m);
    
    for(int i = 0; i < m; i++) in >> squadre[i];
    
    int ourTeam = squadre[0];
    int pos;
    
    sort(squadre.begin(), squadre.end());
    reverse(squadre.begin(), squadre.end());
    
    for(int i = 0; i < squadre.size(); i++)
	if(squadre[i] == ourTeam) { pos = i; break; }
    
    if(m == 16)
    {
	if(pos == 0) out << 'V';
	else if(pos < 3) out << 'F';
	else if(pos < 10) out << 'H';
	else if(pos < 14) out << 'Q';
	else out << 'G';
    }
    
    else if(m == 32)
    {
	if(pos == 0) out << 'V';
	else if(pos < 5) out << 'F';
	else if(pos < 19) out << 'H';
	else if(pos < 26) out << 'Q';
	else if(pos < 30) out << 'O';
	else out << 'G';
    }
    
    else if(m == 64)
    {
	if(pos == 0) out << 'V';
	else if(pos < 8) out << 'F';
	else if(pos < 36) out << 'H';
	else if(pos < 50) out << 'Q';
	else if(pos < 57) out << 'O';
	else if(pos < 62) out << 'S';
	else out << 'G';
    }
    
    return 0;
}