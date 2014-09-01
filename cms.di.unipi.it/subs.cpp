#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* args[])
{
    freopen("input.txt", "r", stdin);
    #ifdef EVAL
    freopen("output.txt", "w", stdout);
    #endif // EVAL

    int N;
    char word[1000000];

    scanf("%d\n", &N);
    scanf("%c", &word[0]);
    int sol = 0;

    for(int i = 1; i < N; i++)
	{
        scanf("%c", &word[i]);
        if(word[i] > word[sol])
        { sol = i; continue; }
        if(word[i] == word[sol])
        {
            int j = 1;
            while(j+i < N)
            {
                scanf("%c", &word[i+j]);
                if(word[i+j] > word[sol])
                { sol = i+j; break; }
                if(word[i+j] < word[sol+j]) break;
                if(word[i+j] > word[sol+j])
                { sol = i; break; }
                j++;
            }
            i += j;
        }
	}

    printf("%d\n", sol);

    return 0;
}
