#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
    int N, monete[10001];    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &N);
        
    while(N--)
    {
	int M;
	scanf("%d", &M);
	for(int i = 0; i < M; i++)
	    scanf("%d", monete+i);

    	std::sort(monete, monete+M);
	int sol = 0;
	int curr = 1;	
	int i = 0;	

	for(; i < M; i++)
	    if(monete[i] <= curr) { sol += monete[i]; curr = sol+1; }
	    else break;   

	printf("%d\n", curr);
    }

    return 0;
}
