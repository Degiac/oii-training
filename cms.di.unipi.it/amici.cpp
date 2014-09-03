#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, K, T;

    vector<int> mov[27];
    vector<int> amici;

    scanf("%d %d %d", &N, &K, &T);

    amici.resize(K);
    mov[0].resize(N+1);

    for(int i = 1; i <= N; i++)
	scanf("%d", &mov[0][i]);

    for(int i = 0; i < K; i++)
        scanf("%d", &amici[i]);

    for(int i = 1; i < 27; i++)
    {
        mov[i].resize(N+1);
        for(int j = 1; j <= N; j++)
            mov[i][j] = mov[i-1][mov[i-1][j]];
    }

    for(int i = 0; i < 27; i++)
    {
        if(T & (1 << i))
            for(int j = 0; j < K; j++)
                amici[j] = mov[i][amici[j]];
    }

    sort(amici.begin(), amici.end());

    int skip = 1;
    int i = 0;

    for(; i < K; i++)
    {
        if(amici[i] == skip) { skip++; continue; }
        break;
    }

    if(i == K) printf("1\n");
    else printf("%d\n", amici[i]);

    return 0;
}
