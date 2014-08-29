#include <cstdio>
#include <cmath>

int main()
{  
    int N;
    int seq[3010];
    bool jolly[3010];
    
    while(scanf("%d", &N) != EOF)
    {
	for(int i = 0; i < N; i++)
	{
	    scanf("%d", seq+i);
	    jolly[i] = 0;
	}
	
	for(int i = 0; i < N-1; i++)
	    jolly[(int)std::abs(seq[i]-seq[i+1])] = 1;
	
	int i = 1;
	
	for(; i < N; i++)
	    if(!jolly[i])
	    {
		printf("Not jolly\n");
		break;
	    }
	
	if(i == N) printf("Jolly\n");
    }
    
    return 0;
}
