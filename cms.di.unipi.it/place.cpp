#include <cstdio>
#include <vector>
#include <stack>
#include <list>

using std::vector;
using std::stack;
using std::list;

class FenwickTree
{
private:
    vector<int> vt;
    int LSOne(int v) { return v & (-v); }
public:
    FenwickTree(int n) { vt.assign(n+1, 0); }
    int rsq(int a)
    {
	int sum = 0;
	for(; a; a -= LSOne(a)) sum += vt[a];
	return sum;
    }
    int getValue(int a)
    {
	return rsq(a) - (a > 1) ? rsq(a-1) : 0;
    }
    void adjust(int k, int v)
    {
	for(; k < (int)vt.size(); k += LSOne(k)) vt[k] += v;
    }
};

void preproc(int &currIdx, int currNode, vector<list<int> > &tree, vector<int> &idx, vector<int> &sons)
{
    idx[currNode] = currIdx++;
    
    for(list<int>::iterator i = tree[currNode].begin(); i != tree[currNode].end(); i++)
	preproc(currIdx, *i, tree, idx, sons);
    
    sons[currNode] = currIdx;
} 

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N, M;
    vector<int> index;
    vector<list<int> > hierarchy;
    vector<int> sons;
    vector<int> wages;
    
    scanf("%d %d", &N, &M);
    
    index.resize(N+1);
    hierarchy.resize(N+1);
    sons.resize(N+1);
    wages.resize(N+1);
    FenwickTree ft(N);
    
    scanf("%d", &wages[1]);
    
    for(int i = 2; i <= N; i++)
    {
	int boss;
	scanf("%d %d\n", &wages[i], &boss);
	hierarchy[boss].push_back(i);
	sons[boss]++;
    }
    
    int currI = 1;
    
    preproc(currI, 1, hierarchy, index, sons);
    
    char c;
    for(int i = 0; i < M; i++)
    {
	scanf("%c", &c);
	if(c == 'u')
	{
	    int toCheck;
	    scanf("%d\n", &toCheck);
	    printf("%d\n", wages[toCheck] + ft.rsq(index[toCheck]));
	}
	if(c == 'p')
	{
	    int boss, modifier;
	    scanf("%d %d\n", &boss, &modifier);
	    ft.adjust(index[boss]+1, modifier);
	    ft.adjust(sons[boss], -modifier);
	}
    }
    
    return 0;
}