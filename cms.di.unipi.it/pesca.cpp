#include <cstdio>
#include <algorithm>
#include <list>
#include <vector>

using namespace std;

struct point
{
    int x, y;
};

bool cmp(const point &a, const point &b)
{
    return a.x < b.x;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int P;
    vector<point> pesci;
    point inizio;
    vector<int> mov[2];

    scanf("%d", &P);
    scanf("%d %d", &inizio.x, &inizio.y);

    while(P--)
    {
        point temp;
        scanf("%d %d", &temp.x, &temp.y);
        if(temp.x < inizio.x || temp.y < inizio.y) continue;
        pesci.push_back(temp);
    }

    sort(pesci.begin(), pesci.end(), cmp);

    int up, dwn;
    int temp;

    mov[0].push_back(0);
    mov[1].push_back(0);

    while(scanf("%d", &temp), temp != 0)
    {
        if((temp < 0 && mov[0].back() < 0) || (temp > 0 && mov[0].back() > 0)) mov[0].back() += temp;
        else mov[0].push_back(temp);
    }

    if(mov[0][1] > 0) { up = 0; dwn = 1; }
    else { up = 1; dwn = 0; }

    while(scanf("%d", &temp),  temp != 0)
    {
        if((temp < 0 && mov[1].back() < 0) || (temp > 0 && mov[1].back() > 0)) mov[1].back() += temp;
        else mov[1].push_back(temp);
    }

    int pos = 0;
    int cont = 0;
    point t = inizio;
    for(int i = 1; i < (int)mov[up].size(); i++)
    {
        if(mov[up][i] > 0) t.y += mov[up][i];
        else
        {
            t.x -= mov[up][i];
            while(pesci[pos].x < t.x && pos < (int)pesci.size())
            {
                if(pesci[pos].y > t.y) cont++;
                pos++;
            }
        }
    }

    while(pesci[pos].x == t.x && pos < (int)pesci.size())
    {
        if(pesci[pos].y > t.y) cont++;
        pos++;
    }

    cont += ((int)pesci.size()-pos);

    t = inizio;
    pos = 0;
    for(int i = 1; i < (int)mov[dwn].size(); i++)
    {
        if(mov[dwn][i] > 0) t.y += mov[dwn][i];
        else
        {
            t.x -= mov[dwn][i];
            while(pesci[pos].x <= t.x && pos < (int)pesci.size())
            {
                if(pesci[pos].y < t.y) cont++;
                pos++;
            }
        }
    }

    printf("%d\n", (int)pesci.size()-cont);

    return 0;
}
