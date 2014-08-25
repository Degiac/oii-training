#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

void find_Tree(int sPre, int ePre, int sPost, int ePost, int *pre, int *post, int *simm, int &idx)
{
    if(sPre == ePre) { simm[idx++] = pre[sPre]; return; }

    if(pre[sPre+1] != post[sPost-1])
    {
        int newSPre = sPre+2;
        int newSPost = sPost-2;

        while(pre[newSPre] != post[sPost-1]) newSPre++;
        while(post[newSPost] != pre[sPre+1]) newSPost--;

        find_Tree(sPre+1, newSPre-1, newSPost, ePost, pre, post, simm, idx);
        simm[idx++] = pre[sPre];
        find_Tree(newSPre, ePre, sPost-1, newSPost+1, pre, post, simm, idx);
    }
    else
    {
        find_Tree(sPre+1, ePre, sPost-1, ePost, pre, post, simm, idx);
        simm[idx++] = pre[sPre];
    }
}

void visita(int N, int *PRE, int *POST, int *SIMM )
{
    int idx = 0;

    find_Tree(0, N-1, N-1, 0, PRE, POST, SIMM, idx);
}
