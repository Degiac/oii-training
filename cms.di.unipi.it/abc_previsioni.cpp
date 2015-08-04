#include <cstdio>

int prevLen(int l, int prev)
{
	return (l - (prev+3))/2;
}

bool inMiddle(int l, int prev, int N)
{
	if(N < prevLen(l, prev)) return false;
	if(N > prevLen(l, prev) + prev + 3) return false;
	
	return true;
}

int main(int argc, const char *argv[])
{
	int N; scanf("%d", &N);

	int l = 3;
	int prev = 0;

	while(l < N)
	{
		prev++;
		l = l*2 + prev+3;
	}

	while(!inMiddle(l, prev, N))
	{
		if(N > l/2)
			N -= (prevLen(l, prev) + prev+3);
			
		l = prevLen(l, prev);
		prev--;
	}

	if(N == prevLen(l, prev)+1) printf("P\n");
	else printf("S\n");


	return 0;
}
