#include <fstream>
#include <vector>

using namespace std;

bool solve(vector<int> &password, vector<int> &stringa1, vector<int> &stringa2, int L, int N)
{
  for(int i = 0; i < L/2; i++)
  {
    if(stringa1[i]-48 < N)
    {
      if(stringa2[L/2-i-1]-48 < N) return false;
      else
      {
	if(password[stringa1[i]-48] == 0 || password[stringa1[i]-48] == stringa2[L/2-i-1])
	  password[stringa1[i]-48] = stringa2[L/2-i-1];
	else return false;
      }
    }
  }
  
  for(int i = 0; i < L/2; i++)
  {
    if(stringa2[i]-48 < N)
    {
      if(stringa1[L/2-i-1]-48 < N) return false;
      else
      {
	if(password[stringa2[i]-48] == 0 || password[stringa2[i]-48] == stringa1[L/2-i-1])
	  password[stringa2[i]-48] = stringa1[L/2-i-1];
	else return false;
      }
    }
  }
  
  for(int i = 0; i < N; i++)
    if(password[i] == 0) return false;
    
  return true;
}

int main()
{
  ifstream in("input.txt");
  ofstream out("output.txt");
  
  vector<int> password;
  vector<int> stringa1;
  vector<int> stringa2;
  
  int N, L;
  
  in >> N >> L;
  
  password.resize(N);
  stringa1.resize(L/2);
  stringa2.resize(L/2);
  
  char temp = in.get();
  
  for(int i = 0; i < L/2; i++)
    stringa1[i] = in.get();
  
  for(int i = 0; i < L/2; i++)
    stringa2[i] = in.get();
  
  for(int i = 0; i < N; i++) password[i] = 0;
  
  bool sol = solve(password, stringa1, stringa2, L, N);
  
  if(!sol) out << "impossibile";
  else
    for(int i = 0; i < N; i++)
    {
      char c = password[i];
      out << c;
    }

  return 0;
}
