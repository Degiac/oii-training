#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<unsigned char, int> values;
    int N, Let, Lin;
    scanf("%d\n", &N);
    
    while(N--)
    {
	double pay = 0;
	
	for(int i = 0; i < 255; i++)
	    values[i] = 0;
	
	scanf("%d\n", &Let);
	
	while(Let--)
	{
	    unsigned char c;
	    int v;
	    
	    scanf("%c %d\n", &c, &v);
	    values[c] = v;
	}
	
	scanf("%d\n", &Lin);
	
	while(Lin--)
	{
	    unsigned char c;
	    c = getc(stdin);
	    while(c != '\n')
	    {
		pay += values[c];
		c = getc(stdin);
	    }
	}
	
	pay /= 100;
	
	printf("%.2f$\n", pay);
    }
}
