#include <cstdio>
#include <utility>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

#define RIG 0
#define COL 1

using namespace std;

struct evento
{
    int R, C;
};

int N, M;
int memotab[1000][1001][2];
char memosol[1000][1001][2];
evento eve[1000];

int solve(int event, int pos, int scelta)
{
    if(event == N) return 0;
    if(memotab[event][pos][scelta]) return memotab[event][pos][scelta];

    int cpos, rpos, solIfR, solIfC;
    if(event == 0) cpos = rpos = 1;
    else
    {
        rpos = (scelta == RIG ? eve[event-1].R : pos);
        cpos = (scelta == COL ? eve[event-1].C : pos);
    }


    solIfR = solve(event+1, cpos, RIG) + abs(rpos-eve[event].R);
    solIfC = solve(event+1, rpos, COL) + abs(cpos-eve[event].C);

    if(solIfR < solIfC)
    {
        memotab[event][pos][scelta] = solIfR;
        memosol[event][pos][scelta] = 'R';
        return solIfR;
    }
    else
    {
        memotab[event][pos][scelta] = solIfC;
        memosol[event][pos][scelta] = 'C';
        return solIfC;
    }
}

void printsol()
{
    int rpos = 1, cpos = 1, scelta = 0, pos = 0;

    for(int i = 0; i < N; i++)
    {
        char ris = memosol[i][pos][scelta];
        if(ris == 'R')
        {
            rpos = eve[i].R;
            pos = cpos;
            scelta = RIG;
        }
        else
        {
            cpos = eve[i].C;
            pos = rpos;
            scelta = COL;
        }
        printf("%c\n", ris);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    #ifdef EVAL
    freopen("output.txt", "w", stdout);
    #endif

    scanf("%d %d", &N, &M);

    for(int i = 0; i < N; i++)
        scanf("%d %d", &eve[i].R, &eve[i].C);

    solve(0, 0, 0);
    printsol();

    return 0;
}
