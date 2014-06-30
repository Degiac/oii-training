#include <fstream>
#include <vector>

using namespace std;

struct player
{
  float y0, y1;
};

int main(int argc, char* args[])
{
  ifstream in("input.txt");
  ofstream out("output.txt");
  
  int d, A, D;
  
  vector<player> attaccanti;
  vector<player> difensori;
  vector<float> posA;
  vector<float> posD;
  
  in >> d >> A >> D;

  attaccanti.resize(A);
  difensori.resize(D);
  posA.resize(A);
  posD.resize(D);
  
  int temp;
  
  for(int i = 0; i < A; i++)
  {
    in >> temp >> attaccanti[i].y0 >> temp >> attaccanti[i].y1;
    posA[i] = (attaccanti[i].y1 - attaccanti[i].y0) * d/10 + attaccanti[i].y0;
  }
  
  for(int i = 0; i < D; i++)
  {
    in >> temp >> difensori[i].y0 >> temp >> difensori[i].y1;
    posD[i] = (difensori[i].y1 - difensori[i].y0) * d/10 + difensori[i].y0;
  }
  
  bool fuorigioco = false;
  
  float ultimoDifensore = posD[0];
  
  for(int i = 1; i < D; i++)
    if(posD[i] < ultimoDifensore) ultimoDifensore = posD[i];
    
  for(int i = 0; i < A; i++)
    if(posA[i] < ultimoDifensore) fuorigioco = true;
      
  if(fuorigioco) out << "F";
  else out << "R";
  
  return 0;
}
