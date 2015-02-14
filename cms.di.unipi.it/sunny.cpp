#include <fstream>
#include <queue>
#include <iostream>

using namespace std;

struct galleria
{
    int succ, lum;
    galleria(): lum(50001) {}
    galleria(int s, int l): succ(s), lum(l) {}
};

struct svincolo
{
    galleria coll;
    int distanza;
    bool visited;
    svincolo(): distanza(0), visited(false) {}
};

int main(int argc, char* args[])
{
    ifstream in ("input.txt");
    ofstream out ("output.txt");

    int N, M, H, S;
    vector<svincolo> svincoli;
    in >> N >> M >> H >> S;
    svincoli.resize(N);

    int u, v, l;

    for(int i = 0; i < M; i++)
    {
        in >> u >> v >> l;
        if(l < svincoli[u-1].coll.lum)
        {
            galleria temp(v-1, l);
            svincoli[u-1].coll = temp;
        }
        if(l < svincoli[v-1].coll.lum)
        {
            galleria temp(u-1, l);
            svincoli[v-1].coll = temp;
        }
    }

    for(int i = 0; i < N; i++)
    {
        cout << "Svincolo n." << i << " Collegato a: " << svincoli[i].coll.succ << "(" << svincoli[i].coll.lum << ")\n";
    }

    int current = H-1;
    int cont = 1;

    while(!svincoli[current].visited)
    {
        svincoli[current].visited = true;
        svincoli[current].distanza = cont;
        current = svincoli[current].coll.succ;
        cont++;
    }

    out << svincoli[S-1].distanza-1;

    return 0;
}
