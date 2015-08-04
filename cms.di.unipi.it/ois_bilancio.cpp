#include <cstdio>

#define MAXN 1000000
#define INF	1e9

int num[MAXN], min[MAXN*4];

void build_tree(int idx, int l, int r)
{
	if(l == r)
	{
		min[idx] = l;
		return;
	}
	
	build_tree(idx*2, l, (l+r)/2);
	build_tree(idx*2+1, (l+r)/2+1, r);
	
	if(num[min[idx*2]] <= num[min[idx*2+1]])
		min[idx] = min[idx*2];
	else
		min[idx] = min[idx*2+1];
}

int getmin(int idx, int l, int r, int s, int e)
{
	if(s > r || e < l) return -1;
	
	if(s <= l && e >= r) return min[idx];
	
	int leftIdx = getmin(idx*2, l, (l+r)/2, s, e);
	int rightIdx = getmin(idx*2+1, (l+r)/2+1, r, s, e);
	
	if(leftIdx < 0) return rightIdx;
	if(rightIdx < 0) return leftIdx;
	
	if(num[leftIdx] <= num[rightIdx])
		return leftIdx;
	else return rightIdx;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N, K; scanf("%d %d", &N, &K);
	
	for(int i = 0; i < N; i++)
		scanf("%d", num+i);

	build_tree(1, 0, N-1);
	int l = 0, r = K;	
	int len = N-K;
	for(int i = 0; i < len; i++)
	{
		int posMin = getmin(1, 0, N-1, l, r);	
		printf("%d ", num[posMin]); 
		K -= (posMin-l);
		l = posMin+1;
		r = l + K;
	}
		
	return 0;
}
