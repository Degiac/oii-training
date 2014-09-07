#include <cstdio>

#define MAXN 105
#define N 0
#define E 1
#define S 2
#define W 3

int main()
{   
    int arena[MAXN][MAXN];
	char line[100];
	char comandi[50000];
    int n, m, s;

    while(scanf("%d %d %d\n", &n, &m, &s))
    {
		if(n == 0) break;
		int dir, sol = 0;
		int r, c;

		for(int i = 0; i < n; i++)
		{
			scanf("%s", line);
			for(int j = 0; j < m; j++)
			{
				if(line[j] == '.') arena[i][j] = 0;
				else if(line[j] == '*') arena[i][j] = 1;
				else if(line[j] == '#') arena[i][j] = -1;
				else
				{
					r = i; c = j;
					arena[i][j] = 0;
					switch(line[j])
					{
						case 'N':
							dir = N; break;
						case 'L':
							dir = E; break;
						case 'S':
							dir = S; break;
						case 'O':
							dir = W;
					}
				}
			}
		}

		scanf("%s", comandi);

		for(int i = 0; i < s; i++)
		{
			sol += arena[r][c];
			if(arena[r][c] > 0) arena[r][c] = 0;
			char com = comandi[i];
			if(com == 'D') dir = (dir+1)%4;
			else if(com == 'E') dir = ((dir-1)+4)%4;
			else if(com == 'F')
			{
				int tempR = r, tempC = c;
				switch(dir)
				{
					case N:
					tempR--;
					break;
					case E:
					tempC++;
					break;
					case S:
					tempR++;
					break;
					case W:
					tempC--;    
				}
				if(tempC < 0 || tempC >= m || tempR < 0 || tempR >= n) continue;
				if(arena[tempR][tempC] == -1) continue;
				r = tempR;
				c = tempC;
			}   
		}
		sol += arena[r][c];
		printf("%d\n", sol); 
    }

    return 0;
}
