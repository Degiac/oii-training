#include <stdio.h>
#include <assert.h>

int codifica(int N)
{
	int sol = N;
	int sum = 0;
	while(N != 0)
	{
		sum *= 10;
		sum += (N%10);
		N /= 10;
	}
	sol += sum;
	
	return sol;
}

int main() {
    FILE *fr, *fw;
    int N;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));

    fprintf(fw, "%d\n", codifica(N));
    fclose(fr);
    fclose(fw);
    return 0;
}
