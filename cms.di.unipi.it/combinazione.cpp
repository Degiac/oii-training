#include <cstdio>
#include <utility>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N;
    
    scanf("%d", &N);
    
    int med[N];
    
    for(int i = 0; i < N; i++)
	scanf("%d", med+i);
    
    int min = med[0]  - (med[1] - med[0]);
    int max = med[0];
    
    int i = 0;
    bool found = false;
    
    while(!found && min <= max)
    {
	int currN = min;
	int contN = 0;
	while(contN < N)
	{
	    int prevN = currN;
	    currN = med[contN]*2 - prevN;
	    if(currN < prevN) { min++; break; }
	    contN++;
	}
	if(contN == N) found = true;
    }
    
    
    if(min > max) { printf("0\n"); return 0; }
    
    i = 0;
    
    while(found)
    {
	int currN = max;
	int contN = 0;
	
	while(contN < N)
	{
	    int prevN = currN;
	    currN = med[contN]*2 - prevN;
	    if(currN < prevN) { max--; break; }
	    contN++;
	}
	if(contN == N) found = false;
    }
    
    
    printf("%d\n", max-min+1);
    
    return 0;
}
