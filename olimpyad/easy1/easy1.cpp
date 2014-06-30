#include <fstream>

using namespace std;

int main(int argc, char* args[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N;
    int max = -1001;
    int temp;

    in >> N;

    for(int i = 0; i < N; i++)
    {
        in >> temp;
        if(temp > max)
            max = temp;
    }

    out << max;

    return 0;
}
