#include <cstdio>

#define MAXN 20

int punti[MAXN], pwin, win;

int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N; scanf("%d", &N);

	for(int i = 0; i < N*(N-1)/2; i++)
	{
		int t1, t2, g1, g2; scanf("%d %d %d %d", &t1, &t2, &g1, &g2);
		t1--; t2--;
		if(g1 > g2) punti[t1] += 3;
		if(g2 > g1) punti[t2] += 3;
		if(g1 == g2) { punti[t1]++; punti[t2]++; }
	}

	for(int i = 0; i < N; i++)
		if(punti[i] > pwin)
		{
			pwin = punti[i];
			win = i;
		}

	printf("%d %d\n", win+1, pwin);

	return 0;
}
