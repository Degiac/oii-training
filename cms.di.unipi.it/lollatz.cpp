#include <cstdio>
#include <unordered_map>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N; scanf("%d", &N);
	unordered_map<int, bool> m;
	
	while(N % 10 != 0)
	{
		if(m[N] == 1)
		{
			N = -1;
			break;
		}
		m[N] = 1;
		
		int u = N%10 - 1;
		if(u < 0) u = 9;
		
		N = N*(N%10 - 1)/2;
	}
	
	printf("%d\n", N);
	
	return 0;
}
