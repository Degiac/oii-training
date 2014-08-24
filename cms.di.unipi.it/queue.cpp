#include <utility>
#include <fstream>
#include <vector>
#include <queue>
#include <string>
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <utility>
#include <algorithm>

#define MAXN 10000000

using namespace std;

int N, K;
int mat[5000][5000]; // 1 VIP 0 VUOTO -1 OCC
bool vis[5000][5000];
int xvip, yvip;

vector<pair<float, pair<int, int> > > place(int x, int y)
{
    queue<pair<int, int> > q;

    q.push(make_pair(x, y));

    vector<pair<float, pair<int, int> > > sol;
    int i = 1;
    while(!q.empty())
    {
	pair<int, int> c = q.front();
	q.pop();
	if(c.first < 0 || c.second < 0 || c.first >= N || c.second >= N) continue;
	if(!vis[c.first][c.second])
	{
	    vis[c.first][c.second] = true;
	    if(mat[c.first][c.second] == 0)
	    {
		sol.push_back(make_pair( sqrt( (c.first-xvip)*(c.first-xvip) + (c.second-yvip)*(c.second-yvip) ), make_pair(c.first, c.second) ));
	    }
	    q.push(make_pair(c.first+1, c.second));
	    q.push(make_pair(c.first, c.second+1));
	    q.push(make_pair(c.first-1, c.second));
	    q.push(make_pair(c.first, c.second-1));
	    i++;
	}
	if(sol.size()==K+i) break;
    }

    return sol;
}

int main()
{
    char c;
    string input, output;
    stringstream ssi, sso;

    cout << "Inserisci numero input: ";
    cin >> c;

    ssi << "input_00" << c << ".txt";
    sso << "output_00" << c << ".txt";

    input = ssi.str();
    output = sso.str();

    ifstream in(input.c_str());
    ofstream out(output.c_str());

    in >> N >> K;

    char temp;

    for(int i = 0; i < N; i++)
	for(int j = 0; j < N; j++)
	{
	    in >> temp;
	    if(temp == '-') mat[i][j] = 0;
	    else if(temp == 'X') mat[i][j] = -1;
	    else if(temp == 'O')
	    {
		mat[i][j] = 1;
		xvip = i;
		yvip = j;
	    }

	}


    vector<pair<float, pair<int, int> > > sol = place(xvip, yvip);
    cout << sol.size() << "\n";

    nth_element(sol.begin(), sol.begin()+K, sol.end());

    for(int i = 0; i < K; i++)
    {
	mat[sol[i].second.first][sol[i].second.second] = -1;
    }

    for(int i = 0; i < N; i++)
    {
	for(int j = 0; j < N; j++)
	{
	    switch(mat[i][j])
	    {
		case 0:
		    out << "-";
		    break;
		case 1:
		    out << "O";
		    break;
		case -1:
		    out << "X";
	    }
	}
	out << "\n";
    }

    return 0;
}
