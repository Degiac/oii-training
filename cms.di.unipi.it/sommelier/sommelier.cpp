#include <fstream>

using namespace std;

int main(int argc, char* args[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;

    in >> N;

    int peso[N];
    int sol[N];

    for(int i = 0; i < N; i++)
    {
            in >> peso[i];
            sol[i] = 1;
    }

    for(int i = 2; i < N; i++)
    {
            for(int j = i-2; j >= 0; j--)
                    if(peso[i] >= peso[j] && sol[i] <= sol[j]) sol[i] = sol[j]+1;
    }

    int max = 0;

    for(int i = 0; i < N; i++)
            if(sol[i] > max) max = sol[i];

    out << max;

    return 0;
}
