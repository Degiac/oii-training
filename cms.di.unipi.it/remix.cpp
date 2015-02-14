#include <cstdio>

#define MAXN 100005

char testo[MAXN];
char pah[5] = "PaH";
char tunz[5] = "TuNZ";
	
bool checkPah(int i)
{
	bool itIs = false;
	
	int j = 0;
	for(; j < 3; j++)
		if(testo[i+j] != pah[j]) break;
	if(j == 3) itIs = true;

	return itIs;
}

bool checkTunz(int i)
{
	bool itIs = false;
	
	int j = 0;
	for(; j < 4; j++)
		if(testo[i+j] != tunz[j]) break;
	if(j == 4) itIs = true;
	
	return itIs;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N; scanf("%d\n", &N); 
	for(int i = 0; i < N; i++)
		testo[i] = getchar_unlocked();
	
	bool smt = false;
	
	for(int i = 0; i < N; i++)
	{
		bool cP = 1, cT = 1;
		
		while(cP || cT)
		{
			cP = checkPah(i);
			if(cP)
			{
				i += 3;
				if(smt) { printf(" "); smt = 0; }
			}
			cT = checkTunz(i);
			if(cT)
			{
				i += 4;
				if(smt) { printf(" "); smt = 0; }
			}
		}
		
		smt = true;
		if(i >= N) break;
		printf("%c", testo[i]);
	}
	
	printf("\n");
	
	return 0;
	
}
