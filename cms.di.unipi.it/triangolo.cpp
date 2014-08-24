#include <fstream>
#include <vector>

using namespace std;

/*int solve(vector<int> &albero, int pos, int riga)
{
    if(pos >= albero.size()) return 0;
    
    return albero[pos] + max(solve(albero, 2*pos+1-(pos-riga), riga+1), solve(albero, 2*pos+2 -(pos-riga), riga+1));
}*/

int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    int N;
    vector<int> albero;
    vector<int> sol;
    in >> N;
    
    int numeri = 0;
    int temp;
    
    for(int i = N; i > 0; i--) numeri += i;
    
    for(int i = 0; i < numeri; i++)
    {
	in >> temp;
	albero.push_back(temp);
	sol.push_back(temp);
    }
    
    int cont = 0;
    int riga = 0;
    
    for(int i = 0; i < numeri; i++)
    {
	if(i*2+1-(i-riga) < numeri) 
	    if(sol[i*2+1-(i-riga)] < sol[i] + albero[i*2+1-(i-riga)])
		sol[i*2+1-(i-riga)] = sol[i] + albero[i*2+1-(i-riga)];
	if(i*2+2-(i-riga) < numeri)
	    if(sol[i*2+2-(i-riga)] < sol[i] + albero[i*2+2-(i-riga)])
		sol[i*2+2-(i-riga)] = sol[i] + albero[i*2+2-(i-riga)];
	    
	if(cont == riga) { cont = 0; riga++; }
	else cont++;
	
    }
    
    int mas = sol[0];
    
    for(int i = 1; i < numeri; i++)
	mas = max(mas, sol[i]);
    
    out << mas;
    //out << solve(albero, 0, 0);
    
    return 0;
}