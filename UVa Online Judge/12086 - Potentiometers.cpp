#include <cstdio>
#include <vector>

using namespace std;

class FenwickTree
{
private:
    vector<int> ft;
    int LSOne(int b) { return (b & (-b)); }
public:
    FenwickTree(int n) { ft.assign(n+1, 0); }
    int rsq(int b)
    {
	int sum = 0;
	for(; b; b -= LSOne(b)) sum += ft[b];
	return sum;
    }
    int rsq(int a, int b)
    {
	return rsq(b) - (a == 1 ? 0 : rsq(a-1));
    }
    void adjust(int k, int v)
    {
	for(; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; 
    }
};

int main()
{
    int N;
    int contcase = 1;
    while(scanf("%d", &N), N)
    {
	if(contcase > 1) printf("\n");
	FenwickTree ft(N);
	printf("Case %d:\n", contcase);
	for(int i = 1; i <= N; i++)
	{
	    int res;
	    scanf("%d", &res);
	    ft.adjust(i, res);
	}
	
	char com[4];
	
	while(scanf("%s\n", com), com[0] != 'E')
	{
	    int a, b;
	    scanf("%d %d", &a, &b);
	    if(com[0] == 'M')
		printf("%d\n", ft.rsq(a, b));
	    if(com[0] == 'S')
		ft.adjust(a, b-ft.rsq(a, a));	    
	}
	contcase++;
    }
    
    return 0;
}

