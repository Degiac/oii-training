#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M;
    in >> N >> M;
    double tradN = sqrt(N);
    int radN = ceil(tradN);
    vector<deque<int> > vasi(radN);

    for(int i = 0; i < N; i++)
        vasi[i/radN].push_back(i);

    for(int i = 0; i < M; i++)
    {
        char com;
        int a, b;
        in >> com;
        if(com == 'c')
        {
            in >> a;
            int arr = a/radN;
            int pos = a%radN;
            out << vasi[arr][pos] << " ";
        }
        else
        {
            in >> a >> b;
            if(a == b) continue;

            int arr1 = a/radN;
            int pos1 = a%radN;
            int arr2 = b/radN;
            int pos2 = b%radN;
            int value = vasi[arr1][pos1];

            vasi[arr1].erase(vasi[arr1].begin() + pos1);

            while(arr1 < arr2)
            {
                vasi[arr1].push_back(vasi[arr1+1].front());
                vasi[++arr1].pop_front();
            }

            while(arr1 > arr2)
            {
                vasi[arr1].push_front(vasi[arr1-1].back());
                vasi[--arr1].pop_back();
            }

            vasi[arr1].insert(vasi[arr1].begin() + pos2, value);
        }
    }

    out << "\n";

    return 0;
}
