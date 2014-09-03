#include <cstdio>
#include <cstring>
#include <deque>
#include <vector>

using namespace std;

int main()
{
    int N, P;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &N, &P);

    if(P == 1)
    {
	deque<int> eroi(N);
	
	for(int i = 1; i <= N; i++)
	    eroi[i-1] = i;

	for(int i = 0; i < N; i++)
	{
	    for(int j = 0; j < N; j++)
		printf("%d %d ", j+1, eroi[j]);
	    printf("\n");

	    eroi.push_front(eroi.back());
	    eroi.pop_back();
	}
    }
    else
    {
	deque<int> hero1;
	deque<int> hero2;
	
	for(int i = 0; i < N/2; i++)
	{
	    hero1.push_back(i+1);
	    hero2.push_back(N-i);
	}
	
	for(int i = 0; i < N-1; i++)
	{
	    for(int j = 0; j < N/2; j++)
		printf("%d %d ", hero1[j], hero2[j]);
	    printf("\n");
	    
	    hero1.pop_front();
	    hero2.push_back(hero1.back());
	    hero1.pop_back();
	    hero1.push_front(hero2.front());
	    hero2.pop_front();
	    hero1.push_front(1);
	}
    }

    return 0;
}
