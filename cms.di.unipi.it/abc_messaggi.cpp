#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define MAXN 200000

using namespace std;

unordered_map<string, vector<string> > ricevuti;
unordered_map<string, vector<string> > inviati;

int main(int argc, const char *argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int N, R; cin >> N >> R;
	
	for(int i = 0; i < N; i++)
	{
		string m, d; cin >> m >> d;
		ricevuti[d].push_back(m);
		inviati[m].push_back(d);
	}

	for(int i = 0; i < R; i++)
	{
		string com, nom; cin >> nom >> com;
		vector<string> v;

		if(com == "INVIATI")
			v = inviati[nom];
		else
			v = ricevuti[nom];

		cout << v.size();
		for(auto t : v)
			cout << " " << t;

		cout << "\n";
	}
	return 0;
}
