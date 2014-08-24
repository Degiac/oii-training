#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* args[])
{
  ifstream in ("input.txt");
  ofstream out ("output.txt");
  
  vector<int> panini;
  vector<int> soluzione;
  
  int N;
  
  in >> N;
  
  panini.resize(N);
  soluzione.resize(N);
  
  for(int i = 0; i < N; i++)
  {
    in >> panini[i];
    soluzione[i] = 1;
  }
  
  for(int i = 1; i < N; i++)
    for(int j = i-1; j >= 0; j--)
      if(panini[j] > panini[i] && soluzione[j] >= soluzione[i]) soluzione[i] = soluzione[j]+1;
  
  int max = soluzione[0];
      
  for(int i = 1; i < N; i++)
    if(soluzione[i] > max) max = soluzione[i];
    
  out << max;
      
  return 0;
}