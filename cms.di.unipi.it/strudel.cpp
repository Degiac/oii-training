#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <queue>
#include <utility>
#include <functional>
#include <queue>
#include <map>
#include <set>
#include <assert.h>
#include <math.h>

#define INF 1000000005
#define MAX_N 100005
#define MAX_M 100005
#define MOD int(1e9)+7

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector< ii > vii;

void readInt(int &n){
    n = 0;
    int ch = getchar_unlocked();
    int sign = 1;
    while(ch < '0' || ch > '9'){
        if(ch == '-') 
            sign = -1; 
        ch = getchar_unlocked();
    }

    while(ch >= '0' && ch <= '9'){
            n = (n << 3) + (n << 1) + ch - '0';
            ch = getchar_unlocked();
    }
    n *= sign;
}   

struct pp{
    int f, s;
    bool operator<(pp const&a)const{
        return f < a.f;
    }
};

int n, sol, d[MAX_N];
set< pp > s;

int main(){
    #ifdef EVAL
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    
    int curr = 0, currInd = INF;

    readInt(n);
    
    for(int i = 0; i < n; i++)
        readInt(d[i]);
    
    for(int i = 0; i < n; i++){
        int t; 
        readInt(t);
        d[i] -= t;
        d[i] *= -1;
        if(i != 0)
            d[i] += d[i - 1];
        if(d[i] > 0)
            sol = i + 1;
        else{
            pp temp; 
            temp.f = -d[i];
            set< pp >::iterator it = s.upper_bound(temp);
            if(it != s.end()){
                if(it != s.begin()){
                    it--;
                    sol = max(sol, i - (*it).s);
                }
            }
            else
                if(-d[i] < curr)
                    sol = max(sol, i - currInd);
            
        }
        if(-d[i] > curr){
            pp temp;
            temp.f = curr; temp.s = i;
            s.insert(temp);
            curr = -d[i];
            currInd = i;
        }
    }

    cout<<sol;

    return 0;
}
