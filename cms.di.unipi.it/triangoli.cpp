#include <fstream>
#include <algorithm>

#include <iostream>

using namespace std;

struct Punto
{
    double x, y;
    
    bool operator <(const Punto &p) const
    {
	return x < p.x || (x == p.x && y < p.y);
    }
};

double cross(const Punto &O, const Punto &A, const Punto &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, k = 0;
    
    in >> N;
    
    Punto P[N];
    Punto H[N*2];

    for(int i = 0; i < N; i++)
	in >> P[i].x >> P[i].y;
    
    sort(P, P+N);
    
    for(int i = 0; i < N; i++)
    {
	while(k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
	H[k++] = P[i];
    }
    
    for(int i = N-2, t = k+1; i >= 0; i--)
    {
	while(k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
	H[k++] = P[i];
    }
    
    out << k-1;
    
    return 0;
}