#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <utility>

using namespace std;

int N;

struct nodo
{
    bool lazy;  // flag per la lazy propagation
    int s, e;   // per gli hub, indici di inizio e fine sequenza
    int value;  // 0 = croce, 1 = testa
};

void build_tree(int s, int e, int index, nodo tree[])
{   
    tree[index].s = s;
    tree[index].e = e;   
    tree[index].lazy = false;
    tree[index].value = 0;
    
    if(s == e) return;
    
    build_tree(s, s + (e-s)/2, 2*index, tree);
    build_tree(s + (e-s)/2+1, e, 2*index+1, tree);
}

void flip_coins(int s, int e, int index, nodo tree[])
{   
    if(tree[index].lazy)
    {
	tree[index].value = (tree[index].e - tree[index].s + 1) - tree[index].value;
	
	if(tree[index].s != tree[index].e)
	{
	    tree[index*2].lazy = !tree[index*2].lazy;
	    tree[index*2+1].lazy = !tree[index*2+1].lazy;
	}
	
	tree[index].lazy = false;
    }
    
    if(tree[index].s > e || tree[index].e < s) return;
    
    if(tree[index].s >= s && tree[index].e <= e)
    {
	tree[index].value = (tree[index].e - tree[index].s + 1) - tree[index].value; 
	
	if(tree[index].e != tree[index].s)
	{
	    tree[index*2].lazy = !tree[index*2].lazy;
	    tree[index*2+1].lazy = !tree[index*2+1].lazy;
	}
	return;
    }
    
    flip_coins(s, e, index*2, tree);
    flip_coins(s, e, index*2+1, tree);   
    
    tree[index].value = tree[index*2].value + tree[index*2+1].value;
}

int query(int s, int e, int index, nodo tree[])
{
    if(tree[index].s > e || tree[index].e < s) return 0;
    if(tree[index].lazy)
    {
	tree[index].value = (tree[index].e - tree[index].s + 1) - tree[index].value;
	
	if(tree[index].s != tree[index].e)
	{
	    tree[index*2].lazy = !tree[index*2].lazy;
	    tree[index*2+1].lazy = !tree[index*2+1].lazy;
	}
	
	tree[index].lazy = false;
    }
    
    if(tree[index].s >= s && tree[index].e <= e)
	return tree[index].value;
    
    return query(s, e, index*2, tree) + query(s, e, index*2+1, tree);
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int Q;
    
    in >> N >> Q;
    
    int dim = 2;
    
    while(dim < 2*N)
	dim *= 2;
    
    nodo rtree[dim];
    
    build_tree(0, N-1, 1, rtree);
    
    int com, s, e;
    for(int i = 0; i < Q; i++)
    {
	in >> com >> s >> e;
	if(com == 0)
	    flip_coins(s, e, 1, rtree);
	else
	    out << query(s, e, 1, rtree) << endl;
    }
  
    return 0;
}
