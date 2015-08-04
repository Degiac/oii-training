#include <cstdio>
#include <algorithm>

using namespace std;

int dp[2][512][512];

int winner(int p1, int p2)
{
    bool winning = true;
    
    for(int i = 0; i < 3; i++)
    {
        winning = true;
        for(int j = 0; j < 3; j++)
           if((p1 & (1 << (i*3 + j))) == 0) winning = false; 
        
        if(winning) return 1;
    }
    
    for(int i = 0; i < 3; i++)
    {
        winning = true;
        for(int j = 0; j < 3; j++)
            if((p1 & (1 << (i + j*3))) == 0) winning = false;
        
        if(winning) return 1;
    }
    
    winning = true;
    for(int i = 0; i < 9; i += 4)
        if((p1 & (1 << i)) == 0) winning = false;
    
    if(winning) return 1;
    
    winning = true;
    for(int i = 2; i < 7; i += 2)
        if((p1 & (1 << i)) == 0) winning = false;
    
    if(winning) return 1;
   
    winning = true;
    for(int i = 0; i < 3; i++)
    {
        winning = true;
        for(int j = 0; j < 3; j++)
           if((p2 & (1 << (i*3 + j))) == 0) winning = false; 
        
        if(winning) return -1;
    }
    
    for(int i = 0; i < 3; i++)
    {
        winning = true;
        for(int j = 0; j < 3; j++)
            if((p2 & (1 << (i + j*3))) == 0) winning = false;
        
        if(winning) return -1;
    }
    
    winning = true;
    for(int i = 0; i < 9; i += 4)
        if((p2 & (1 << i)) == 0) winning = false;
    
    if(winning) return -1;
  
    winning = true;
    for(int i = 2; i < 7; i += 2)
        if((p2 & (1 << i)) == 0) winning = false;
    
    if(winning) return -1;
    
    return 0;
}

int solve(int p, int p1, int p2)
{
   if(dp[p][p1][p2] != -2) return dp[p][p1][p2];
   
   
   int win = winner(p1, p2);
   if(win != 0) return dp[p][p1][p2] = win;
   if(p1 + p2 == 511) return dp[p][p1][p2] = 0; 
   
   if(p == 0)
   {
      for(int i = 0; i < 9; i++)
        if((p1 & (1 << i)) == 0 && (p2 & (1 << i)) == 0)
        {
            int np1 = p1;
            np1 |= (1 << i);
            dp[p][p1][p2] = max(dp[p][p1][p2], solve(1, np1, p2));
        }
   }
   else
   {
       dp[p][p1][p2] = 2;
       for(int i = 0; i < 9; i++)
           if((p2 & (1 << i)) == 0 && (p1 & (1 << i)) == 0)
           {
                int np2 = p2;
                np2 |= (1 << i);
                dp[p][p1][p2] = min(dp[p][p1][p2], solve(0, p1, np2));
           }
   }
   
   return dp[p][p1][p2];
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int p1 = 0, p2 = 0, count = 0;
    
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 512; j++)
            for(int k = 0; k < 512; k++)
                dp[i][j][k] = -2;
                
    for(int i = 0; i < 3; i++)
    {
        char c[4]; scanf("%s", c);
        for(int j = 0; j < 3; j++)
        {
           if(c[j] == 'X')
           {
               p1 += (1 << (i*3 + j));
               count++;
           }
           if(c[j] == 'O')
           {
               p2 += (1 << (i*3 + j));
               count++;
           }
        }
    }
    
    int sol = solve(count%2, p1, p2);
    
    printf("%d\n", (sol == 1) ? 1 : 0); 
    
    return 0;
}
