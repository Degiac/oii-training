#include <fstream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N, T, P;
    
    vector<int> taskValue;
    vector<vector<int> > taskS;
    vector<int> score;
    
    in >> N >> T >> P;
    
    taskValue.resize(T);
    taskS.resize(N);
    score.resize(N);
    
    for(int i = 0; i < N; i++)
    {
	score[i] = 0;
	for(int j = 0; j < T; j++)
	{
	    int temp;
	    in >> temp;
	    if(temp == 0) taskValue[j]++;
	    else taskS[i].push_back(j);
	}
    }
    
    for(int i = 0; i < N; i++)
	for(int j = 0; j < taskS[i].size(); j++)
	    score[i] += taskValue[taskS[i][j]];
    
    out << score[P-1] << " ";
    
    int pos = 1;
    
    for(int i = 0; i < N; i++)
    {
	if(score[i] > score[P-1]) pos++;
	else if(score[i] == score[P-1])
	{
	    if(taskS[i].size() > taskS[P-1].size()) pos++;
	    else if(taskS[i].size() == taskS[P-1].size())
	    {
		if(i < P-1) pos++;
	    }
	}
    }
    
    out << pos;
	
    return 0;
}
