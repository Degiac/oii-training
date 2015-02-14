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

using namespace std;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N; scanf("%d", &N);
    char c;
   
    scanf("%c", &c);
   
    for(int i = 0; i < N; i++)
    {
        scanf("%c", &c); 
        //97 - 122 compresi minuscole
        //65 - 90 compresi maiuscole
        
        if(c > 96 && c < 123) c -= 32;
        else if(c > 64 && c < 91) c += 32;
        
        printf("%c", c);
    }
    
    printf("\n");
    
    return 0;
}
