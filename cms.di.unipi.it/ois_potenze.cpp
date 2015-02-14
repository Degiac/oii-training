#include <cstdio>

int find_pow(int n)
{
	int i = 0;
	int num = 2;
	while(num <= n)
	{
		num *= 2;
		i++;
	}
	
	return i;
}

int pow(int b, int e)
{
	int n = b;
	for(int i = 1; i < e; i++)
		n *= b;
	
	return n;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int numero; scanf("%d", &numero);
	int esp = find_pow(numero), base = 2;
	int sol = pow(base, esp);
	int diff = numero - sol;	
	
	if(numero < 4) { printf("1\n"); return 0; } 
	
	while(esp >= 2)
	{
		base++;
		int t = pow(base, esp);
		while(t > numero)
		{
			esp--;
			t = pow(base, esp);
		}
		if(diff > numero - t && t <= numero)
		{
			diff = numero - t;
			sol = t;
		}
	}
	
	printf("%d\n", sol);
	
	return 0;
}
