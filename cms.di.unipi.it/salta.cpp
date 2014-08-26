#include <fstream>
#include <vector>

int main(int argc, char* args[])
{
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");

    int N;
    int temp;
    std::vector<int> C;
    std::vector<bool> visited;
    in >> N;

    for(int i = 0; i <= N; i++)
    {
        in >> temp;
        C.push_back(temp);
        visited.push_back(false);
    }

    int i = 1;

    while(!visited[i])
    {
        visited[i] = true;
        i = ((i+C[i-1])%N) +1;
    }

    int cont = 0;

    for(int i = 1; i <= N; i++)
    {
        if(!visited[i])
            cont++;
    }

    out << cont << "\n";

    for(int i = 1; i <=N; i++)
    {
        if(!visited[i])
            out << i << " ";
    }

    return 0;
}
