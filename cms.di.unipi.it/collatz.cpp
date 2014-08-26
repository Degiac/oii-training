#include <fstream>

using namespace std;

int main(int argc, char* args[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N;
    int cont = 1;
    
    in >> N;
    
    while(N != 1)
    {
       if(N%2 == 0) N = N/2;
       else N = N*3 +1;
       cont++;
    }
    
    out << cont;
    
    return 0;
}
