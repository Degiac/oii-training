#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

#define pb      push_back
#define fi      first
#define se      second
#define mp      make_pair
#define sz(a)   (int)a.size()

#define EPS     1e-9
#define INF     (int)1e9
#define MAXN    1000005

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int main()
{
    #ifndef EVAL
    freopen("input.txt", "r", stdin);
    #endif
    
    long long int sol = 0;
    int hello_count = 0;
   
    char hello[6] = "hello";
    char world[6] = "world";
    
    int idxH = 0;
    int idxW = 0;
    
    char c = getchar_unlocked();
    
    for(int i = 0; c != '\n' && c != EOF; i++)
    {
        if(c == hello[idxH]) idxH++;
        else
	{
	  idxH = 0;
	  if(c == hello[idxH]) idxH++;
	}
        
        if(c == world[idxW]) idxW++;
        else 
	{
	  idxW = 0;
	  if(c == world[idxW]) idxW++;
	}
        
        if(idxH == 5) { hello_count++; idxH = 0; }
        if(idxW == 5) { sol += hello_count; idxW = 0; }
        
        c = getchar_unlocked();
    }
    
    printf("%lld\n", sol);
    
    return 0;
}
