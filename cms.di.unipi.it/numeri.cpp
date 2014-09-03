#include <cstdio>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M, piante[1000001];
    int sx = 0, dx = -1;
    int sum = 0;
    int cont = 0;
    scanf("%d %d", &M, &N);

    for(int i = 0; i < N; i++) scanf("%d", piante+i);

    while(dx < N - 1)
    {
	while(sum < M && dx < N -1) sum += piante[++dx];
	while(sum == M && dx < N - 1)
	{
	    cont++;
	    while(piante[dx+1] == 0 && dx < N-1) dx++;
	    while(piante[dx] == 0 && sx < dx) { cont++; dx--; }
	    sum -= piante[sx++];
	}
	while(sum > M && sx < dx) sum -= piante[sx++];
    }

    printf("%d\n", cont);
    
    return 0;
}
