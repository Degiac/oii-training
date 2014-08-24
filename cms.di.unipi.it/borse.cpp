#include <fstream>
#include <iostream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int N, sol[101];

void stampa(int n)
{
    for(int i = 1; i < n; i++)
	out << sol[i] << " ";
    out << "\n";
}

void solve(int toAssign, int count)
{
    if(toAssign == 0) stampa(count);
    else
    {
	int max = sol[count-1];
	int disp;
	if(max <= toAssign) disp = max;
	else disp = toAssign;
	
	for(int i = 1; i <= disp; i++)
	{
	    sol[count] = i;
	    solve(toAssign-i, count+1);
	}
    }
    
}


int main()
{ 
    in >> N;
    
    sol[0] = N;
	
    solve(N, 1);
    
    return 0;
}
