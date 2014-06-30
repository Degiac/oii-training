#include <fstream>

using namespace std;

int griglia[1000][1000], N;

void solve(int row, int col, int c)
{
    griglia[row][col] = c;

    for(int i = -1; i < 2; i++)
        for(int j = -1; j < 2; j++)
        {
            if(i+row < 0 || i+row > N-1 || j+col < 0 || j+col > N-1);
            else if(griglia[row+i][col+j] > c+1 || griglia[row+i][col+j] == 0)solve(row+i, col+j, c+1);

        }

    return;
}

int main(int argc, char* args[])
{
    ifstream in("input.txt");
    ofstream out("output.txt");

    char temp;

    in >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
        {
            in >> temp;
            if(temp == '+') griglia[i][j] = -1;
            if(temp == '*') griglia[i][j] = 0;
        }

    solve(0, 0, 1);

    out << griglia[N-1][N-1];

    return 0;
}
