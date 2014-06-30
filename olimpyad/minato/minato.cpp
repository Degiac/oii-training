#include <fstream>
#include <vector>

using namespace std;


int main(int argc, char* args[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M;
    char temp;
    int griglia[100][100] = {};
    int soluzioni[100][100] = {};
    
    in >> N >> M;
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            in >> temp;
            if(temp == '+') griglia[i][j] = -1;
        }
    
    soluzioni[0][0] = 1;
    
    for(int i = 1; i < M; i++)
	if(griglia[0][i] == -1) break;
	else soluzioni[0][i] = soluzioni[0][i-1];

    for(int i = 1; i < N; i++)
	if(griglia[i][0] == -1) break;
	else soluzioni[i][0] = soluzioni[i-1][0];
	
    for(int i = 1; i < N; i++)
	for(int j = 1; j < M; j++)
	{
	    if(griglia[i-1][j] == 0) soluzioni[i][j] += soluzioni[i-1][j];
	    if(griglia[i][j-1] == 0) soluzioni[i][j] += soluzioni[i][j-1];
	}   
	
    out << soluzioni[N-1][M-1];

    return 0;
}
