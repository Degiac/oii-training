#include <fstream>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct car
{
    int peso, pos;
};

struct posto
{
    int costo;
    bool occ;
    posto(): occ(false) {}
};

int freeSpot(vector<posto> &park)
{
    for(int i = 0; i < park.size(); i++)
	if(!park[i].occ) return i;
	
    return -1;
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N, M;
    vector<car> cars;
    vector<posto> park;
    queue<int> q;
    int guadagno = 0;
    
    in >> N >> M;
    
    park.resize(N);
    cars.resize(M);
    
    for(int i = 0; i < N; i++)
	in >> park[i].costo;
    
    for(int i = 0; i < M; i++)
	in >> cars[i].peso;
    
    for(int i = 0; i < M*2; i++)
    {
	int temp;
	in >> temp;
	if(temp > 0)
	{
	    temp--;
	    q.push(temp);
	}
	else if(temp < 0)
	{
	    temp *= -1;
	    temp--;
	    park[cars[temp].pos].occ = false;
	}
	
	while(freeSpot(park) >= 0 && !q.empty())
	{
	    int current = q.front();
	    q.pop();
	    int j = freeSpot(park);
	    guadagno += cars[current].peso*park[j].costo;
	    park[j].occ = true;
	    cars[current].pos = j;
	}
    }
    
    out << guadagno;
    
    return 0;
}
