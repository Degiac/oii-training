#include <fstream>

using namespace std;

int main(int argc, char* args[])
{
  ifstream in("input.txt");
  ofstream out("output.txt");
  
  int N;
  int giocatori[100] = {};
  
  in >> N;
  
  int temp, gol;
  
  for(int i = 0; i < N; i++)
  {
    in >> temp >> gol;
    giocatori[temp] += gol;
  }
  
  int max = giocatori[0];
  int pos = 0;
  
  for(int i = 1; i < 100; i++)
    if(giocatori[i] > max)
    {
      max = giocatori[i];
      pos = i;
    }
    
  out << pos << " " << max;
  
  return 0;
}


