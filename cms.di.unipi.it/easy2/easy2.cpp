#include <fstream>

int main(int argc, char* args[])
{
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");

    int N, n1, n2;
    int max = -1;
    in >> N;

    for(int i = 0; i < N; i++)
    {
        in >> n1;
        in >> n2;

        if((n1+n2)%2 == 0 && (n1+n2)>max)
            max = n1+n2;
    }

    out << max;

    return 0;
}
