#include <cstdio>

int main()
{
    int H, U, D, F;
    
    scanf("%d %d %d %d", &H, &U, &D, &F);
    
    while(H != 0)
    {
	float currH = 0;
	int day = 0;
	float lost = (float)U/100*(float)F;
	float speed = U;
	while(true)
	{
	    day++;
	    currH += speed;
	    if(currH > H) break;
	    currH -= D;
	    speed = (speed-lost < 0) ? 0 : speed-lost;
	    if(currH < 0) break;
	}
	if(currH < 0)
	    printf("failure on day %d\n", day);
	else
	    printf("success on day %d\n", day);
	
	scanf("%d %d %d %d", &H, &U, &D, &F);
    }
    
    return 0;
}
