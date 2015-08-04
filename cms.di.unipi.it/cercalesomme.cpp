#include <cstdio>
#include <vector>

#define MAXN 10

using namespace std;

int cifre[MAXN], target, N;
vector<int> pos;

void solve(int idx, int sum, int temp)
{
	if(idx == N && sum+temp == target) 
	{
		for(int i = 0; i < (int)pos.size(); i++)
			printf("%d ", pos[i]);
		printf("\n");
		return;
	}
	else if(idx == N) return;

	if(idx != 0)
	{
		pos.push_back(idx);
		solve(idx+1, sum+temp, cifre[idx]);
		pos.pop_back();
	}

	solve(idx+1, sum, temp*10+cifre[idx]);
}

int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &N);
	
	for(int i = 0; i < N; i++)
		scanf("%d", cifre+i);

	scanf("%d", &target);

	solve(0, 0, 0);

	return 0;
}
