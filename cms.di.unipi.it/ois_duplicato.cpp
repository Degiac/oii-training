#include <stdio.h>
#include <assert.h>
#include <unordered_map>
#define MAXN 100000

using namespace std;

int trova(int N, int P[]) 
{
	unordered_map<int, int> pagine;
	
	for(int i = 0; i < 2*N-1; i++) pagine[P[i]]++;
	
	for(auto i = pagine.begin(); i != pagine.end(); ++i)
		if(i->second == 1) return i->first;
}

int P[2 * MAXN];
int main() {
    FILE *fr, *fw;
    int N, i;
    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<2*N-1; i++)
        assert(1 == fscanf(fr, "%d", &P[i]));
    fprintf(fw, "%d\n", trova(N, P));
    fclose(fr);
    fclose(fw);
    return 0;
}
