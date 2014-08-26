#include <vector>
#include <fstream>
#include <cstring>
#include <iostream>

#define MAXN 1000000

using namespace std;

char w[MAXN];
int RA[MAXN], tempRA[MAXN], SA[MAXN], tempSA[MAXN];
int x;
int c[MAXN];

void countingSort(int k)
{
    int i, sum, maxi = max(300, x);
    memset(c, 0, sizeof(c));
    
    for(i = 0; i < x; i++)
	c[i + k < x ? RA[i+k] : 0]++;
    
    for(i = sum = 0; i < maxi; i++)
    {
	int t = c[i];
	c[i] = sum;
	sum += t;
    }
    
    for(i = 0; i < x; i++)
	tempSA[c[SA[i]+k < x ? RA[SA[i]+k] : 0]++] = SA[i];
    
    for(i = 0; i < x; i++)
	SA[i] = tempSA[i];
}

void buildSA()
{
    int i, k, r;
    for(i = 0; i < x; i++)
    {
	RA[i] = w[i];
	SA[i] = i;
    }
    
    for(k = 1; k < x; k <<= 1)
    {
	countingSort(k);
	countingSort(0);
	tempRA[SA[0]] = r = 0;
	for(i = 1; i < x; i++)
	    tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
	for(i = 0; i < x; i++)
	    RA[i] = tempRA[i];
	if(RA[SA[x-1]] == x-1) break;
    }
}

int main(int argc, char* args[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    in.getline(w, MAXN);
    x = strlen(w);
    w[x++] = '$';
    
    buildSA();
    
    for(int i = 1; i < x; i++)
	out << SA[i] << " ";

    return 0;
}

