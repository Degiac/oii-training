#include <cstdio>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

class FenwickTree
{
    private:
	vector<int> ft;
	int LSOne(int n) { return n & (-n); }
    public:
	FenwickTree(int n) { ft.assign(n+1, 0); }
	int rsq(int a)
	{
	    int sum = 0;
	    for(; a; a -= LSOne(a))
	    {
		sum += ft[a];
		sum %= MOD;
	    }
	    return sum;
	}
	int rsq(int a, int b) { return rsq(b) - (a == 1 ? 0 : rsq(a)); }
	void adjust(int k, int v)
	{
	    for(; k < (int)ft.size(); k += LSOne(k))
	    {
		ft[k] += v;
		ft[k] %= MOD;
	    }
	}
};

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N;
    scanf("%d\n", &N);
    
    FenwickTree ft(N);
    
    vector<pair<int, int> > num(N);
    vector<pair<int, int> > actual(N);
    vector<int> sol(N);
    
    for(int i = 0; i < N; i++)
    {
	scanf("%d ", &num[i].first);
	num[i].second = i;
    }
    
    sort(num.begin(), num.end());
    
    int cont = 1;
    actual[0].first = 1;
    actual[0].second = num[0].second;
    for(int i = 1; i < N; i++)
    {
	if(num[i].first != num[i-1].first) cont++;
	actual[i].first = cont;
	actual[i].second = num[i].second;
    }
    
    sort(actual.begin(), actual.end(), cmp);
    
    ft.adjust(actual[0].first, 1);
    
    for(int i = 1; i < N; i++)
	ft.adjust(actual[i].first, ft.rsq(actual[i].first-1)+1);
    
    int sum = 0;
    
    printf("%d\n", ft.rsq(N)); 
    
    return 0;
}