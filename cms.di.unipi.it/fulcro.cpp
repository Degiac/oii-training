#include <fstream>
#include <queue>
#include <list>
#include <iostream>

using namespace std;

list<int> grafo[11];
bool visited[11];

int BFS(int toIgnore)
{
  visited[toIgnore] = true;

  queue<int> q;
  q.push(0);
  
  while(!q.empty())
  {
    int current = q.front();
    q.pop();
    
    if(!visited[current])
    {
      visited[current] = true;
      for(list<int>::iterator i = grafo[current].begin(); i != grafo[current].end(); i++)
	if(!visited[*i]) q.push(*i);
    }
  }
  
  int cont = 0;
  
  for(int i = 0; i < 11; i++)
    if(!visited[i]) cont++;
    
  return cont;
}

int main(int argc, char* args[])
{
  ifstream in ("input.txt");
  ofstream out ("output.txt");
  
  int N;
  
  in >> N;
  
  int v, c;
  
  for(int i = 0; i < N; i++)
  {
    in >> v >> c;
    grafo[v-1].push_back(c-1);
  }
  
  int max = -1;
  int toBlock = 0;
  
  for(int i = 1; i < 11; i++)
  {
    for(int j = 0; j < 11; j++)
      visited[j] = false;
    
    int temp = BFS(i);
    if(temp > max)
    {
      max = temp;
      toBlock = i;
    }
  }
      
  out << toBlock+1;
  
  return 0;
}
