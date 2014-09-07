#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define MAXC 5000000

using namespace std;

int M, F, C;
vector<pair<int, int> > cotte;
vector<int> lis;

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    if(a.first < b.first) return true;
    if(a.first == b.first && a.second > b.second) return true;
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);
    #ifdef EVAL
    freopen("output.txt", "w", stdout);
    #endif

    scanf("%d %d\n %d", &M, &F, &C);
    while(C--)
    {
        int m, f;
        scanf("%d %d", &m, &f);

        cotte.push_back(make_pair(m, f));
    }

    sort(cotte.begin(), cotte.end(), cmp);

    lis.push_back(cotte[0].second);

    for(int i = 1; i < (int)cotte.size(); i++)
    {
        vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), cotte[i].second);
        if(it == lis.end()) { lis.push_back(cotte[i].second); continue; }
        *it = cotte[i].second;
    }

    printf("%d\n", lis.size()*2);

    return 0;
}
