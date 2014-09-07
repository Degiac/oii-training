#include <cstdio>

using namespace std;

int pc[1000];
int rank[1000];

int parent(int i) { return (pc[i] == i) ? i : (pc[i] = parent(pc[i])); }

bool isConnected(int i, int j) { return parent(i) == parent(j); }

void join(int i, int j)
{
    if(!isConnected(i, j))
    {
	      int x = parent(i), y = parent(j);
	      if(rank[x] > rank[y]) pc[y] = x;
	      else { pc[x] = y; if(rank[x] == rank[y]) rank[y]++; }
    }   
}

int main()
{
   	int T; scanf("%d", &T);
	while(T--)
    {
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; i++) { pc[i] = i; rank[i] = 0; }

		char c, line[3000];
		int i, j;
		int succ = 0, fail = 0;

		while(getchar() != '\n');
		while(gets(line) && sscanf(line, "%c %d %d", &c, &i, &j) == 3)
		{
			i--; j--;
		   	if(c == 'c') join(i, j);
		   	else isConnected(i, j) ? succ++ : fail++;
   		}

   		printf("%d,%d\n", succ, fail); if(T != 0) printf("\n");
   	}
	
	return 0;
}	
