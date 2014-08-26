#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* args[])
{
  ifstream in("input.txt");
  ofstream out("output.txt");
  
  int N, D, M;
  vector<int> prezzi;
  
  in >> N >> D;
  
  prezzi.resize(N);
  
  for(int i = 0; i < N; i++)
    in >> prezzi[i];
  
  in >> M;
  
  sort(prezzi.begin(), prezzi.end());
  
  int guadagno = 0;
  
  for(int i = 0; i < N && M > 0; i++)
  {
    guadagno += prezzi[i];
    M--;
  }
  
  guadagno -= (M*D);
  
  out << guadagno;
  
  return 0;
}
