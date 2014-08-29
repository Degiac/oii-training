#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    
    int S, B;
    int left[100005];
    int right[100005];
      
    while(scanf("%d %d", &S, &B), S || B)
    {
	for(int i = 1; i <= S; i++)
	{
	    left[i] = i - 1;
	    right[i] = i + 1;
	}
	
	right[S] = 0;
	int L, R;
	
	while(B--)
	{
	    scanf("%d %d", &L, &R);
	   
	    right[left[L]] = right[R];
	    left[right[R]] = left[L];
	    
	    if(left[right[R]] == 0) printf("* ");
	    else printf("%d ", left[right[R]]);
	    if(right[left[L]] == 0) printf("*\n");
	    else printf("%d\n", right[left[L]]);
	}
	    
	printf("-\n");
    }
    
    return 0;
}
