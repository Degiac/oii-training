#include <queue>
#include <vector>
#include <cstdio>

using namespace std;

int GreatestHappiness(int N, int K, int *H)
{
    int happy = 0, temp = 0;
    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i = 0; i < N; i++)
    {
    	if(K-i == 0) break;
		if(K-i >= i+1)
		{
			temp += H[i];
			pq.push(H[i]);
			if(temp > happy) happy = temp;
			continue;
		}
		if(pq.size() > K-i)
		{
			temp -= pq.top();
			pq.pop();
		}
		if(H[i] > pq.top())
		{
			temp -= pq.top();
			temp += H[i];
			pq.pop();
			pq.push(H[i]);
			
			if(temp > happy) happy = temp;
		}
		
    }

    return happy;
}

#ifndef EVAL

int main()
{
    freopen("input.txt", "r", stdin);

    int N, K;
    int H[1000];

    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) scanf("%d ", &H[i]);

    printf("%d\n", GreatestHappiness(N, K, H));
}

#endif // EVAL
