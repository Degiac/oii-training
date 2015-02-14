#include <cstdio>
#include <algorithm>

#define MAXN 50005

using std::min;

int main()
{
    #ifdef EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // EVAL

    bool mag[MAXN]; int conta = 0;
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        char c = getchar_unlocked();
        if(c == '+') mag[conta++] = 1;
        else if(c == '-') mag[conta++] = 0;
    }

    int contaSx = 0;

    for(int i = 0; i < conta; i += 2)
        if(mag[i]) contaSx++;

    printf("%d", min(contaSx, conta/2-contaSx));
	
	return 0;
}
