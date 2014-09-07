#include <cstdio>
#include <cstring>

#define MAXN 1005

int N, M;
int dp[MAXN][MAXN];
int match[2][MAXN];
bool evita[MAXN];

int solve(int pos, int mat)
{
    if(dp[pos][mat] != -1) return dp[pos][mat];    
    if(mat == M) return dp[pos][mat] = 0;
    if(pos == N) return dp[pos][mat] = 1;

    int v1 = solve(pos+1, match[0][mat]);
    int v2 = solve(pos+1, match[1][mat]);

    return dp[pos][mat] = (v1+v2)%2011;   
}

void fillMatchTable()
{
    for(int i = 0; i < M; i++)
	{
		if(evita[i])
		{
			match[1][i] = i+1;
			match[0][i] = 0;
			int j = 1;
			while(j <= i)
			{
				if(!evita[i-j])
				{
					int l = 1;
					while(evita[i-j-l] == evita[i-l] && l <= i-j) l++;
					if(l > i-j)
						match[0][i] = l;		
					if(match[0][i]) break;
				}
				if(match[0][i]) break;
				j++;
			}
		}
		else
		{
			match[0][i] = i+1;
			match[1][i] = 0;
			int j = 1;
			while(j <= i)
			{
				if(evita[i-j])
				{
					int l = 1;
					while(evita[i-j-l] == evita[i-l] && l <= i-j) l++;
					if(l > i-j)
						match[1][i] = l;		
					if(match[1][i]) break;
				}
				if(match[1][i]) break;
				j++;
			}
		}
    }   
}

int main()
{
    freopen("input.txt", "r", stdin);
    #ifdef EVAL
    freopen("output.txt", "w", stdout);
    #endif

    scanf("%d %d\n", &M, &N);
    for(int i = 0; i <= N; i++)
		for(int j = 0; j <= M; j++)
	    	dp[i][j] = -1;    



    for(int i = 0; i < M; i++)
    {
		char t;
		scanf("%c", &t);
		if(t == '0') evita[i] = 0;
		else evita[i] = 1;
    }

    fillMatchTable();
    
    printf("%d\n", solve(0, 0));     
    return 0;
}
