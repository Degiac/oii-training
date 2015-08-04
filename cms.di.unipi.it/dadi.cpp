#include <cstdio>

int t = 1, b = 6, lf = 2, rf = 3, lb = 4, rb = 5;

void X()
{
    int nlf = t, nb = lf, nrb = b, nt = rb;
    lf = nlf;
    b = nb;
    rb = nrb;
    t = nt;
}

void Y()
{
    int nlb = t, nb = lb, nrf = b, nt = rf;
    lb = nlb;
    b = nb;
    rf = nrf;
    t = nt;
}

void Z()
{
    int nlb = rb, nrb = rf, nrf = lf, nlf = lb;
    lb = nlb;
    rb = nrb;
    rf = nrf;
    lf = nlf;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int N; scanf("%d\n", &N);
    
    while(N--)
    {
        char c = getchar_unlocked();
        if(c == 'X') X();
        else if(c == 'Y') Y();
        else if(c == 'Z') Z();
        else if(c == 'F') printf("%d ", lf);
        else if(c == 'R') printf("%d ", rf);
        else if(c == 'T') printf("%d ", t);
    }
    
    return 0;
}
