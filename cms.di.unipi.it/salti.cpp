#include <cstdio>

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unsigned int D; 
    scanf("%d", &D);

    int cont = 0;    

    for(int i = 0; i < 32; i++)    
	if(D & (1 << i)) cont++;

    printf("%d\n", cont);

    return 0;
}
	
