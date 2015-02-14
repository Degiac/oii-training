#include <cstdio>

int main()
{
    freopen("input.txt", "r", stdin);
    #ifdef EVAL
    freopen("output.txt", "w", stdout);
    #endif // EVAL

    int N; scanf("%d", &N);

    int currPrice; scanf("%d", &currPrice);

    int sol = currPrice;

    for(int i = 1; i < N; i++)
    {
        currPrice++;
        int temp; scanf("%d", &temp);
        if(currPrice > temp)
            currPrice = temp;
        sol += currPrice;
    }

    printf("%d", sol);

    return 0;
}
