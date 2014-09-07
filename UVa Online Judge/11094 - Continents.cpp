#include <cstdio>

int dr[4] = { 1, 0,  0, -1 };
int dc[4] = { 0, 1, -1,  0 };

int M, N; //M == rows, N == columns
char map[20][20]; 
char land;

int floodCount(int r, int c)
{
    if(r < 0 || r == M) return 0;
    if(c < 0) c = N-1;
    if(c == N) c = 0;
    if(map[r][c] != land) return 0;

    map[r][c] = 0;
    int count = 1;
    for(int i = 0; i < 4; i++)
        count += floodCount(r+dr[i], c+dc[i]);

    return count;
}

int main()
{
    while(scanf("%d %d", &M, &N) != EOF)
    {
        for(int i = 0; i < M; i++)
        {
            char line[30];
            scanf("%s", line);
            for(int j = 0; j < N; j++)
                map[i][j] = line[j];
        }
        int sR, sC;
        scanf("%d %d", &sR, &sC);
        land = map[sR][sC];
        floodCount(sR, sC);
        int max = 0;

        for(int i = 0; i < M; i++)
            for(int j = 0; j < N; j++)
            {
                if(map[i][j])
                {
                    int t = floodCount(i, j);
                    max = (t > max) ? t : max;
                }
            }

        printf("%d\n", max);
    }

    return 0;
}
