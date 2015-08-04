#include <cstdio>
#include <algorithm>
#include <utility>
#include <cstring>

#define MAXN 100

int car[MAXN][10];
int ana[MAXN];
char anag[MAXN][100];

int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

        int N; scanf("%d\n", &N);

	for(int i = 0; i < N; i++)
	{
		scanf("%s", anag[i]);
		for(int j = 0; j < strlen(anag[i]); j++)
			car[i][anag[i][j]-'0']++;
	}

	for(int i = 0; i < N - 1; i++)
		for(int j = i+1; j < N; j++)
		{
			bool isAna = 1;
			for(int l = 0; l < 10 && isAna; l++)
				if(car[i][l] != car[j][l])
					isAna = 0;

			if(isAna)
			{
				ana[i]++;
				ana[j]++;
			}
		}

	for(int i = 0; i < N; i++)
		printf("%c", anag[i][ana[i]]);
	printf("\n");

	return 0;
}
