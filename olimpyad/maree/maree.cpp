#include <list>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct punto
{
    list<int> toNext;
    int time, time1, timeLeft;
    punto(): time(1000000001), timeLeft(0), time1(1000000001) {}
};

void visita(vector<punto> &grafo, int T, int c)
{
    queue<int> q;
    q.push(c);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        for(list<int>::iterator i = grafo[current].toNext.begin(); i != grafo[current].toNext.end(); i++)
        {
            if(grafo[current].time+1 < grafo[*i].time && grafo[current].time+1 <= T)
            {
                grafo[*i].time = grafo[current].time+1;
                grafo[*i].timeLeft = T - grafo[*i].time;
                q.push(*i);
            }
        }
    }

}

void visita1(vector<punto> &grafo, int T, int c)
{
    queue<int> q;
    q.push(c);

    while(!q.empty())
    {
        int current = q.front();
        q.pop();
        for(list<int>::iterator i = grafo[current].toNext.begin(); i != grafo[current].toNext.end(); i++)
        {
            if(grafo[current].time1+1 < grafo[*i].time1 && grafo[current].time1+1 <= T)
            {
                grafo[*i].time1 = grafo[current].time1+1;
                q.push(*i);
            }
        }
    }

}

int solve(int N, int M, int T, int* S, int* E)
{
    vector<punto> marea;

    marea.resize(N);

    for(int i = 0; i < M; i++)
    {
        marea[S[i]].toNext.push_back(E[i]);
    }

    marea[0].time = 0;
    marea[0].timeLeft = T;
    marea[N-1].time1 = 0;


  /*  cout << "Marea:\n";
    for(int i = 0; i < N; i++)
    {
        cout << i << ") " << marea[i].time << "(" << marea[i].timeLeft << ")" << marea[i].time1 << "\n";
    } */
    visita(marea, T, 0);
    if(marea[N-1].time == 1000000001) visita1(marea, 100000001, N-1);
    else return marea[N-1].time;

  /*  cout << "Marea:\n";
    for(int i = 0; i < N; i++)
    {
        cout << i << ") " << marea[i].time << "(" << marea[i].timeLeft << ")" << marea[i].time1 << "\n";
    } */

    int minimum = marea[N-1].time;
   // cout << minimum << endl;
    int currentTime;

    for(int i = 0; i < N-1; i++)
    {
        currentTime = marea[i].time + marea[i].timeLeft + marea[i].time1;
        if(currentTime < 0) currentTime *= -1;
        if(currentTime < minimum)
            minimum = currentTime;
    }

   // cout << minimum << endl;
    if(minimum > 1000000000) return -1;
    else return minimum;
}
