#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>

using namespace std;

struct coord
{
    int x, y;
};

int main(int argc, char* args[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N, M;
    vector<coord> stemma;
    vector<vector<int> > giardino;
    
    in >> N >> M;
    
    stemma.resize(M);
    giardino.resize(N);
    
    for(int i = 0; i < M; i++)
	in >> stemma[i].x >> stemma[i].y;
    
    for(int i = 0; i < N; i++)
	giardino[i].resize(N);
    
    for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++)
	    in >> giardino[i][j];

    int minY = stemma[0].y, minX = stemma[0].x, maxY = stemma[0].y, maxX = stemma[0].x;

    
    for(int i = 1; i < M; i++)
    {
	if(stemma[i].y < minY) minY = stemma[i].y; 
	if(stemma[i].x < minX) minX = stemma[i].x;
	if(stemma[i].y > maxY) maxY = stemma[i].y;
	if(stemma[i].x > maxX) maxX = stemma[i].x;
    }
    
    int solution = numeric_limits<int>::max();
    int posX = minY;
    int posY = minX;
    
    for(int i = minY*-1; maxY+i < N; i++)
	for(int j = minX*-1; maxX+j < N; j++)
	{
	    int costo = 0;
	    for(int l = 0; l < M; l++)
		costo += giardino[stemma[l].y+i][stemma[l].x+j];
	    
	    if(costo < solution)
	    {
		solution = costo;
		posX = j;
		posY = i;
	    }
	}
    
    out << posX << " " << posY << " " << solution; 
    
    return 0;
}
