#include <vector>
#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>

using namespace std;

int N, M;
ofstream out("output.txt");
vector<pair<int, pair<int, int> > > archi;
vector<int> p;
vector<int> r;

void init() { p.resize(N); r.assign(N, 1); for(int i = 0; i < N; i++) p[i] = i; }
int parent(int i) { return (p[i] == i) ? i : p[i] = parent(p[i]); }
bool isJoined(int i, int j) { return (parent(i) == parent(j)); }
void join(int i, int j)
{
	i = parent(i); j = parent(j);
	if(r[i] > r[j])	p[j] = i;
	else
	{
		p[i] = j;
		if(r[i] == r[j]) r[j]++;
	}
}

void readInt(int &torna)
{
    char c = getchar_unlocked();
    torna = 0;
    while(c == ' ' || c == '\n') c = getchar_unlocked();
    while(c != ' ' && c != '\n')
    {
        torna *= 10;
        torna += (c-'0');
        c = getchar_unlocked();
    }
}

int kruskal()
{
	int sol = 0;
	sort(archi.begin(), archi.end());
	int cont = 0;
	for(int i = 0; i < M && cont < N-1; i++)
	{
		int w = archi[i].first, h = archi[i].second.first, t = archi[i].second.second;
		if(!isJoined(h, t))
		{
			cont++;
			join(h, t);
            		out << h+1 << " " << t+1 << "\n";
			sol += w;
		}						
	}

	return sol;	
}

int main()
{
	freopen("input.txt", "r", stdin);
   	ios::sync_with_stdio(false);

   	readInt(N); readInt(M);
   	archi.reserve(M);
	init();

	for(int i = 0; i < M; i++)
	{
		int w, h, t; 
       	readInt(h); readInt(t); readInt(w);
		archi.push_back(make_pair(w, make_pair(h-1, t-1)));		
	}

   	out << "                                                \n";

	int sol = kruskal();

   	out.seekp(ios_base::beg);
   	out << sol;

	return 0;
}

