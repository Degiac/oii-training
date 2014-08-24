#include <iostream>
#include <fstream>

using namespace std;

struct nodo
{
   // int s, e;   //inizio e fine del segmento, s == e per i figli
    int lazy;   //flag per l'update
    int mod0;   //mod0 = n%3 = 0, mod1 = n%3 = 1, mod2 = n%3 = 2
    int mod1;
    int mod2;
};

void build_tree(int s, int e, int index, nodo tree[])
{     
    tree[index].lazy = 0;
    tree[index].mod0 = e - s + 1;
    tree[index].mod1 = tree[index].mod2 = 0;
    
    if(s == e) return;
    
    build_tree(s, s + (e-s)/2, 2*index, tree);
    build_tree(s + (e-s)/2+1, e, 2*index+1, tree);
}

void rotate(int &mod0, int &mod1, int &mod2)
{
    int c = mod0;
    int l = mod1;
    
    mod0 = mod2;
    mod1 = c;
    mod2 = l;
}

void add_one(int start, int end, int s, int e, int index, nodo tree[])
{   
    if(tree[index].lazy > 0)
    {
	tree[index].lazy %= 3;
	for(int i = 0; i < tree[index].lazy; i++)
	    rotate(tree[index].mod0, tree[index].mod1, tree[index].mod2);
	
	if(start != end)
	{
	    tree[index*2].lazy += tree[index].lazy;
	    tree[index*2+1].lazy += tree[index].lazy;
	}
	
	tree[index].lazy = 0;
    }
    
    if(start > e || end < s) return;
    
    if(start >= s && end <= e)
    {
	rotate(tree[index].mod0, tree[index].mod1, tree[index].mod2); 
	
	if(end != start)
	{
	    tree[index*2].lazy++;
	    tree[index*2+1].lazy ++;
	}
	return;
    }
    
    add_one(start, start + (end-start)/2, s, e, index*2, tree);
    add_one(start + (end-start)/2 + 1, end, s, e, index*2+1, tree);   
    
    tree[index].mod0 = tree[index*2].mod0 + tree[index*2+1].mod0;
    tree[index].mod1 = tree[index*2].mod1 + tree[index*2+1].mod1;
    tree[index].mod2 = tree[index*2].mod2 + tree[index*2+1].mod2;
}

int query(int start, int end, int s, int e, int index, nodo tree[])
{
    if(start > e || end < s) return 0;
    
    if(tree[index].lazy > 0)
    {
	tree[index].lazy %= 3;
	for(int i = 0; i < tree[index].lazy; i++)
	    rotate(tree[index].mod0, tree[index].mod1, tree[index].mod2);
	
	if(start != end)
	{
	    tree[index*2].lazy += tree[index].lazy;
	    tree[index*2+1].lazy += tree[index].lazy;
	}
	
	tree[index].lazy = 0;
    }
    
    if(start >= s && end <= e)
	return tree[index].mod0;
    
    return query(start, start + (end-start)/2, s, e, index*2, tree) + query(start + (end-start)/2 + 1, end, s, e, index*2+1, tree);
}

/*void print_tree(int index, nodo tree[])
{
    cout << "[" << start << ", " << end << "] " << tree[index].mod0 << "\n";
    
    if(end == start) return;
    
    print_tree(index*2, tree);
    print_tree(index*2+1, tree);
}*/

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N, Q;
    
    in >> N >> Q;
    
    int dim = 2;
    
    while(dim < 2*N)
	dim *= 2;
    
    nodo rtree[dim];
    
    build_tree(0, N-1, 1, rtree);
    
    //print_tree(1, rtree);
    
    int com, s, e;
    for(int i = 0; i < Q; i++)
    {
	in >> com >> s >> e;
	if(com == 0)
	    add_one(0, N-1, s, e, 1, rtree);
	else
	    out << query(0, N-1, s, e, 1, rtree) << endl;
    }
    
    // cout << "End of input\n";
    
    // print_tree(1, rtree);
    
    return 0;
}