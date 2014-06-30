#include <fstream>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N, M;
    int current = 0;
    
    in >> N >> M;
    
    int t, t1;
    
    for(int i = 0; i < M; i++)
    {
	in >> t >> t1;
	if(t == current) current = t1;
	else if(t1 == current) current = t;
    }
    
    out << current;
    
    return 0;
}
