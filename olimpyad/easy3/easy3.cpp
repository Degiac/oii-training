#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

int main(int argc, char* args[])
{
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");

    int N;
    int temp;
    int max = -1;
    int sum;
    std::vector<int> s;

    in >> N;

    for(int i = 0; i < N; i++)
    {
        in >> temp;
        s.push_back(temp);
    }

    std::sort(s.begin(), s.end(), std::greater<int>());

    for(int j = 1; j < N; j++)
    {
            sum = s[0] + s[j];
            if(sum%2 == 0 && sum > max)
            {
                max = sum;
                break;
            }
    }

    for(int j = 2; j < N; j++)
    {
            sum = s[1] + s[j];
            if(sum%2 == 0 && sum > max)
            {
                max = sum;
                break;
            }
    }


    out << max;

    return 0;
}
