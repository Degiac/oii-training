#include <cstdio>

const char EMPTY = '.';
const char UP = 'x';
const char HIT = '@';

int dr[4] = { 0,  0, 1, -1 };
int dc[4] = { 1, -1, 0,  0 };

int N;
char map[105][105];
bool found;

void isUp(int r, int c)
{
    if(r < 0 || r == N || c < 0 || c == N) return;
    if(map[r][c] == EMPTY) return;
    if(map[r][c] == UP) found = true;

    map[r][c] = EMPTY;
    
    for(int i = 0; i < 4; i++)
        isUp(r+dr[i], c+dc[i]);
}

int main()
{
    int T; scanf("%d", &T);
    for(int i = 1; i <= T; i++)
    {
        scanf("%d", &N);
        for(int j = 0; j < N; j++)
            scanf("%s", map[j]);
        
        int cont = 0;

        for(int j = 0; j < N; j++)
            for(int l = 0; l < N; l++)
                if(map[j][l] != EMPTY)
                {
                    isUp(j, l);
                    cont += found;
                    found = 0;
                }
        printf("Case %d: %d\n", i, cont);
    }

    return 0;
}
