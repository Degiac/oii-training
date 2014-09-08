#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <queue>

using namespace std;

typedef vector<int> vi;

int N, M;
vi graph[100];
int indegree[100];
map<string, int> idx;
string names[100];
vi ans;

void kahn()
{
    priority_queue<int, vi, greater<int> > pq;
    for(int i = 0; i < N; i++)
        if(indegree[i] == 0) pq.push(i);

    while(!pq.empty())
    {
        int c = pq.top();
        ans.push_back(c);
        pq.pop();
        for(int i = 0; i < (int)graph[c].size(); i++)
        {
            indegree[graph[c][i]]--;
            if(indegree[graph[c][i]] == 0) pq.push(graph[c][i]);
        }
    }
}

int main()
{
    int test = 0;
    while(scanf("%d", &N) != EOF)
    {
        test++;
        for(int i = 0; i < N; i++) graph[i].clear();
        memset(indegree, 0, sizeof indegree);
        ans.clear();
        for(int i = 0; i < N; i++)
        {
            char word[52];
            scanf("%s", word);
            string s = word;
            names[i] = s;
            idx[s] = i;
        }
        scanf("%d", &M);
        for(int i = 0; i < M; i++)
        {
            char h[52], t[52];
            scanf("%s %s", h, t);
            int he = idx[string(h)], ta = idx[string(t)];
            graph[he].push_back(ta);
            indegree[ta]++;
        }
        kahn();
        printf("Case #%d: Dilbert should drink beverages in this order: ", test);
        for(int i = 0; i < (int)ans.size()-1; i++)
            printf("%s ", names[ans[i]].c_str());
        printf("%s.\n\n", names[ans.back()].c_str());
    }
    return 0;
}
