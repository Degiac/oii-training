#include <fstream>
#include <iostream>
#include <cstring>

#define MAXN 100000000

using namespace std;

long long sum[51][51];
long long sol[51][51][51][51];
int raisins[51][51];
int N, M;

int solve(int x, int y, int x2, int y2)
{
    if(sol[x][y][x2][y2] < MAXN) return sol[x][y][x2][y2];
    
    if( ( x2-x + y2-y ) == 1) 
    {
	sol[x][y][x2][y2] = raisins[x][y] + raisins[x2][y2];
	return sol[x][y][x2][y2];
    }
 
    for(int i = x; i < x2; i++)
    {
	sol[x][y][x2][y2] = min(sol[x][y][x2][y2], solve(x,y,i,y2) + solve(i+1,y,x2,y2) + sum[x2][y2] + sum[x-1][y-1] - sum[x-1][y2] - sum[x2][y-1]);   
    }
    
    for(int i = y; i < y2; i++)
    {
	sol[x][y][x2][y2] = min(sol[x][y][x2][y2], solve(x,y,x2,i) + solve(x,i+1,x2,y2) + sum[x2][y2] + sum[x-1][y-1] - sum[x-1][y2] - sum[x2][y-1]);
    }
    
    return sol[x][y][x2][y2];
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    in >> N >> M;
    
    for(int x = 0; x <= N; x++)
	for(int y = 0; y <= M; y++)
	    for(int x1 = x; x1 <= N; x1++)
		for(int y1 = y; y1 <= M; y1++)
		    sol[x][y][x1][y1] = MAXN;
		
    for(int i = 1; i <= N; i++)
	for(int j = 1; j <= M; j++)
	{
	    in >> raisins[i][j];
	    sol[i][j][i][j] = 0;
	}
		
    for(int x = 1; x <= N; x++)
    {
	int conta = 0;
	for(int y = 1; y <= M; y++)
	{
	    conta += raisins[x][y];
	    sum[x][y] = conta;
	    sum[x][y] += sum[x-1][y];
	}
    }

    out << solve(1, 1, N, M);
 
    return 0;
}