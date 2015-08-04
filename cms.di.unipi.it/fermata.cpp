#include <fstream>
#include <vector>
using namespace std;
int n,s,c;
pair<int,int> tab_trans[10000000]; //first = nuovo stato, second = spostamento
int tab_vis[1000000];
int strip[1000000];
ifstream in("input.txt");
ofstream out("output.txt");
bool visit(int state, int index){
int actual = state * n + index;
switch(tab_vis[actual]){
case 0:
tab_vis[actual] = 1;
break;
case -1:
return false;
case 1:
return false;
case 2:
return true;
}
int value = strip[index];
int new_index = index + tab_trans[state * c + value].second;
if(new_index < 0 || new_index >= n){
tab_vis[actual] = -1;
return false;
}
bool ret = visit(tab_trans[state * c + value].first, new_index);
if(ret){
tab_vis[actual] = 2;
return true;
}else{
tab_vis[actual] = -1;
return false;
}
}
int main(int argc, char **argv)
{
in >> n >> s >> c;
for(int i = 0; i < s*c; i++){
int t1, t2, t3, t4;
in >> t1 >> t2 >> t3 >> t4;
tab_trans[t1 * c + t2] = make_pair(t3, t4);
}
for(int i = 0; i < n; i++){
int temp;
in >> temp;
strip[i] = temp;
}
for(int i = 0; i < s; i++){
tab_vis[i * n] = 2;
}
int result[n];
int counter = 0;
for(int i = 0; i < n; i++){
if(visit(0, i))	result[counter++] = i;
}
out << counter << endl;
for(int i = 0; i < counter; i++){
out << result[i] << endl;
}
return 0;
}

/*#include <fstream>
#include <vector>

using namespace std;

int N, S, C;
pair<int, int> comandi[10000000]; //first stato second offset
int visited[1000000]; // 0 niente 1 visita -1 non termina 2 termina
int nastro[1000000];

bool vaimo(int stato, int cella)
{
    int pos = stato*N + cella;
    
    switch(visited[pos])
    {
	case 0:
	    visited[pos] = 1;
	    break;
	case 1:
	    return false;
	case -1:
	    return false;
	case 2:
	    return true;
    }
    
    int letto = nastro[cella];
    int newCella = cella + comandi[stato*C + letto].second;
    
    if(newCella < 0 || newCella >= N) 
    {
	visited[pos] = -1;
	return false;
    }
    
    bool continua = vaimo(comandi[stato*C + letto].first, newCella);
    
    if(continua)
    {
	visited[pos] = 2;
	return true;
    }
    else
    {
	visited[pos] = -1;
	return false;
    }
}

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    in >> N >> S >> C;
    
    int t1,t2, t3, t4;
    for(int i = 0; i < S*C; i++)
    {
	in >> t1 >> t2 >> t3 >> t4;
	comandi[t1*C + t2] = make_pair(t3, t4);
    }
    
    for(int i = 0; i < N; i++)
	in >> nastro[i];
    
    for(int i = 0; i < N; i++)
	visited[i*N] = 2;
   
    vector<int> result;
    
    for(int i = 0; i < N; i++)
	if(vaimo(0, i)) result.push_back(i);
    
    out << (int)result.size() << "\n";
    for(int i = 0; i < (int)result.size(); i++)
	out << result[i] << "\n";
    
    return 0;    
}
*/