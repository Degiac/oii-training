#include <algorithm>
#include <vector>

struct moz
{
    int pos;
    int key;
};

bool cmp_moz(const moz &a, const moz &b)
{
    return (a.key > b.key);
}

long long solve(int N, int* M, int* P) {
    long long somma = 0;
    std::vector<moz> diff;
    diff.resize(N);

    for(int i = 0; i < N; i++)
    {
        diff[i].key = M[i]-P[i];
        diff[i].pos = i;
    }

    std::nth_element(diff.begin(), diff.begin()+(N/2), diff.end(), cmp_moz);

    for(int i = 0; i < N/2; i++)
        somma += M[diff[i].pos];

    for(int i = N/2; i < N; i++)
        somma += P[diff[i].pos];

    return somma;
}
