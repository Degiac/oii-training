#include <fstream>
#include <vector>

using namespace std;

struct giocatore
{
       int x, y;
       int pallX, pallY;
       bool toccata;
       giocatore(): toccata(false) {};
};

struct p
{
       int x, y;
};

int main(int argc, char* args[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int X, Y, N;
    p palla;
    vector<giocatore> player;
    
    in >> X >> Y;
    in >> palla.x >> palla.y;
    
    in >> N;
    
    player.resize(N);
    
    for(int i = 0; i < N; i++)
            in >> player[i].x >> player[i].y >> player[i].pallX >> player[i].pallY;
            
    bool end = false;
    int cont = 0;
    
    while(!end)
    {
               int minimum = 1000000;
               int piuVicino;
               for(int i = 0; i < N; i++)
               {
                       int dis;
                       int x, y;
                       
                       if(player[i].x > palla.x) x = player[i].x - palla.x;
                       else x = palla.x - player[i].x;
                       
                       if(player[i].y > palla.y) y = player[i].y - palla.y;
                       else y = palla.y - player[i].y;
                       
                       dis = x+y;
                       if(dis == minimum)
                       {
                              if(player[i].x < player[piuVicino].x)
                              {
                                            piuVicino = i; 
                              }
                              else if(player[i].x == player[piuVicino].x && player[i].y < player[piuVicino].y) piuVicino = i;                       
                       } 
                       else if(dis < minimum)
                       {
                              minimum = dis;
                              piuVicino = i;
                       }
               }
               
               if(player[piuVicino].toccata) end = true;
               else
               {
                   player[piuVicino].toccata = true;
                   cont++;
                   
                   palla.x = player[piuVicino].pallX;
                   palla.y = player[piuVicino].pallY;
               }
    
    }
    
    out << cont;           
    
    return 0;
}
