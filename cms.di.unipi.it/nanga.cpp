#include <cstdio>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, int> m;

int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N; scanf("%d", &N);
	int alt = 5000;
	m[alt]++;

	for(int i = 0; i < N; i++)
	{
		int t; scanf("%d", &t);
		alt += t;
		m[alt]++;
	}

	int sol = 0;
	int mas = 0;

	for(auto &i : m)
		if(i.second > mas)
		{
			sol = i.first;
			mas = i.second;
		}

	printf("%d\n", sol);

	return 0;
}
