#include <iostream>

#include <fstream>

using namespace std;

struct nodo
{
    int lsum, rsum, msum, sum;
};

void build_tree(int index, int l, int r, nodo tree[], int values[])
{ 
    if(l == r)
    {
	tree[index].lsum = tree[index].rsum = tree[index].msum = tree[index].sum = values[l];
	return;
    }
    
    build_tree(index*2, l, (l+r)/2, tree, values);
    build_tree(index*2+1, (l+r)/2 +1, r, tree, values);
    
    tree[index].lsum = max(tree[index*2].lsum, tree[index*2].sum + tree[index*2+1].lsum);
    tree[index].rsum = max(tree[index*2+1].rsum, tree[index*2+1].sum + tree[index*2].rsum);
    tree[index].msum = max(tree[index*2].rsum + tree[index*2+1].lsum, max(tree[index*2].msum, tree[index*2+1].msum));
    tree[index].sum = tree[index*2].sum + tree[index*2+1].sum;
}

void mod(int index, int l, int r, int pos, int value, nodo tree[])
{    
    if(r < pos || l > pos) return;
    
    if(l == r)
    {
	tree[index].lsum = tree[index].rsum = tree[index].msum = tree[index].sum = value;
	return;
    }
    
    mod(index*2, l, (l+r)/2, pos, value, tree);
    mod(index*2+1, (l+r)/2 +1, r, pos, value, tree);
    
    tree[index].lsum = max(tree[index*2].lsum, tree[index*2].sum + tree[index*2+1].lsum);
    tree[index].rsum = max(tree[index*2+1].rsum, tree[index*2+1].sum + tree[index*2].rsum);
    tree[index].msum = max(tree[index*2].rsum + tree[index*2+1].lsum, max(tree[index*2].msum, tree[index*2+1].msum));
    tree[index].sum = tree[index*2].sum + tree[index*2+1].sum;
}

nodo query(int index, int l, int r, int start, int end, nodo tree[])
{
    if(l == start && r == end)
	return tree[index];
    
    if(end <= (l+r)/2)
	return query(index*2, l, (l+r)/2, start, end, tree);
	
    if(start > (l+r)/2)
	return query(index*2+1, (l+r)/2+1, r, start, end, tree);
    
    nodo left = query(index*2, l, (l+r)/2, start, (l+r)/2, tree);
    nodo right = query(index*2+1, (l+r)/2 +1, r, (l+r)/2 +1, end, tree);
    
    nodo toReturn;
    toReturn.lsum = max(left.lsum, left.sum + right.lsum);
    toReturn.rsum = max(right.rsum, right.sum + left.rsum);
    toReturn.msum = max(left.rsum + right.lsum, max(left.msum, right.msum));
    toReturn.sum = left.sum + right.sum; 
    
    return toReturn;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N, M;
    in >> N;
    
    nodo rtree[N*4];
    int values[N];
    
    for(int i = 0; i < N; i++)
	in >> values[i];
    
    build_tree(1, 0, N-1, rtree, values);
    
    in >> M;
    
    int com, s, e;
    
    for(int i = 0; i < M; i++)    
    {
	in >> com >> s >> e;
	if(com == 0) mod(1, 0, N-1, s-1, e, rtree);

	else out << query(1, 0, N-1, s-1, e-1, rtree).msum << "\n";
    }
    
    return 0;
}