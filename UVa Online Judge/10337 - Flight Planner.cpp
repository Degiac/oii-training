#include <cstdio>
#include <cstring>
#include <algorithm>

#define climb 60
#define hold 30
#define sink 20

using std::min;

int dp[11][1002];
int tab[11][1002];
int X;

void fly(int h, int m, int c)
{
    if(dp[h][m] == -1) dp[h][m] = c;
    else if(dp[h][m] < c) return;
    dp[h][m] = c;
    if(m == X+1) return;
    /*hold!*/ fly(h, m+1, c + hold - tab[h][m]);
    if(h > 1) fly(h-1, m+1, c + sink - tab[h][m]);
    if(h < 10) /*climb!*/ fly(h+1, m+1, c + climb - tab[h][m]);
} 

int main()
{  
    int N;
    scanf("%d", &N);
    for(int l = 0; l < N; l++)
    {
	scanf("%d", &X);
	X /= 100;
	
	for(int i = 10; i > 0; i--)
	    for(int j = 1; j <= X; j++)
		scanf("%d", &tab[i][j]);
	    
	memset(dp, -1, sizeof dp);
	
	fly(1, 1, 0);
	
	printf("%d\n\n", dp[1][X+1]);
    }
    
    return 0;
}