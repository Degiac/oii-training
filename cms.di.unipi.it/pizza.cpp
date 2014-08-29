#include <queue>
#include "pizza.h"

using namespace std;

queue<int> ordini[256];
int ingredienti[8];
int orderN;
int ava;

void Init()
{
    orderN = 0;
    ava = 0;
    for(int i = 0; i < 8; i++)
        ingredienti[i] = 0;
}

bool isBakable(int pizza)
{
    return ((pizza & ava) == pizza);
}

void cook(int pizza)
{
    for(int i = 0; i < 8; i++)
        if((pizza & (1 << i)) != 0)
        {
            ingredienti[i]--;
            if(ingredienti[i] == 0)
                ava &= ~(1 << i);
        }
}

void Delivery(int I)
{
    ingredienti[I]++;
    ava |= (1 << I);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for(int i = 0; i < 256; i++)
        if(!ordini[i].empty() && isBakable(i))
        {
            pq.push(make_pair(ordini[i].front(), i));
        }

    if(!pq.empty())
    {
        cook(pq.top().second);
        Bake(pq.top().first);
        ordini[pq.top().second].pop();
    }
}

void Order(int N, int *A)
{
    int pizza = 0;
    for(int i = 0; i < N; i++)
        pizza |= (1 << A[i]);

    ordini[pizza].push(orderN);

    if(isBakable(pizza))
    {
        cook(pizza);
        Bake(orderN);
        ordini[pizza].pop();
    }

    orderN++;
}
