#include <stdio.h>
#include <algorithm>
#include <assert.h>

#define MAXN 100005
#define INF 1e9

using std::min;
int dist[MAXN];
int salta(int N, int E[]) {
    dist[0] = 0;
    int firstNonChecked = 0; 
    for(int i = 0; i < N; i++)
        for(int j = firstNonChecked + 1; j <= min(N, i + E[i]); j++, firstNonChecked++)
           dist[j] = dist[i]+1;
    
    return dist[N];
}

int E[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &E[i]));

    fprintf(fw, "%d\n", salta(N, E));
    fclose(fr);
    fclose(fw);
    return 0;
}
