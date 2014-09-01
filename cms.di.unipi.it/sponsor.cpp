#include <vector>
#include <set>
#ifndef EVAL
#include "grader.cpp"
#endif // EVAL

using namespace std;

int solve(int N, int M, int* Q, int** sponsors, int* A, int* B)
{
    vector<vector<int> > sponsor(M+1);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < Q[i]; j++)
            sponsor[sponsors[i][j]].push_back(i+1);


    for(int i = 1; i < M; i++)
        for(int j = i+1; j <= M; j++)
        {
            if((int)sponsor[i].size() < (int)sponsor[j].size())
            {
                int jt = 0;
                int cont = 0;
                for(int it = 0; it < (int)sponsor[i].size(); it++)
                    while(sponsor[j][jt] <= sponsor[i][it] && jt < (int)sponsor[j].size())
                    {
                        if(sponsor[j][jt] == sponsor[i][it]) cont++;
                        jt++;
                    }

                if(cont == (int)sponsor[i].size() || cont == 0) continue;
                *A = i; *B = j; return 0;
            }
            else
            {
                int jt = 0;
                int cont = 0;
                for(int it = 0; it < (int)sponsor[j].size(); it++)
                    while(sponsor[i][jt] <= sponsor[j][it] && jt < (int)sponsor[i].size())
                    {
                        if(sponsor[i][jt] == sponsor[j][it]) cont++;
                        jt++;
                    }

                if(cont == (int)sponsor[j].size() || cont == 0) continue;
                *A = i; *B = j; return 0;
            }
        }

    return 1;
}
