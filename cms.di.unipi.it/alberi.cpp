#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct nodo
{
    int value;
    nodo *left;
    nodo *right;
};

nodo* newNode(int value)
{
    struct nodo* n = new(struct nodo);
    n->value = value;
    n->left = NULL;
    n->right = NULL;

    return(n);
}

nodo* find_Tree(int sPre, int ePre, int sPost, int ePost, int *pre, int *post)
{

    nodo *curr = newNode(pre[sPre]);
    if(sPre == ePre) return curr;

    if(pre[sPre+1] != post[sPost-1])
    {
        int newSPre = sPre+2;
        int newSPost = sPost-2;

        while(pre[newSPre] != post[sPost-1]) newSPre++;
        while(post[newSPost] != pre[sPre+1]) newSPost--;

        curr->left = find_Tree(sPre+1, newSPre-1, newSPost, ePost, pre, post);
        curr->right = find_Tree(newSPre, ePre, sPost-1, newSPost+1, pre, post);
    }
    else    curr->left = find_Tree(sPre+1, ePre, sPost-1, ePost, pre, post);

    return curr;
}

void print(nodo *n, queue<int> &q)
{
    if(n == NULL) return;
    print(n->left, q);
    q.push(n->value);
    print(n->right, q);
}

void visita(int N, int *PRE, int *POST, int *SIMM )
{
    nodo *albero = find_Tree(0, N-1, N-1, 0, PRE, POST);

    queue<int> q;

    print(albero, q);
    int i = 0;
    while(!q.empty())
    {
        SIMM[i++] = q.front();
        q.pop();
    }

    return;
}
