#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N;
    string s;
    
    in >> N >> s;
    
    int bstart = 0, bend = 0, cend = 0, best = 0;
    
    for(int i = 0; i < N-2; i++)
    {
	if(s[i] == s[i+1]) continue;
	
	string x = s.substr(i, 2), y = s.substr(i, 1);
	
	cend = i+1;
	int st = i+2;
	bool isFibStr = true;
	
	while(isFibStr)
	{
	    if(y.compare( s.substr(st, y.length()) ) == 0)
	    {
		cend += y.length();
		st += y.length();
		string a = x;
		x.append(y);
		y = a;
	    }
	    else isFibStr = false;
	}
	
	if(cend - i > best)
	{
	    best = cend - i;
	    bstart = i;
	    bend = cend;
	}
    }
    
    out << bstart+1 << " " << bend+1 << endl;
    
    return 0;
}
