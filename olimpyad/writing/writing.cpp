#include <fstream>
#include <string>
#include <map>
#include <deque>
#include <iostream>

using namespace std;

int toNum(char c)
{
    int n;
    if(c < 'a') n = c - 65;
    else n = c - 71;
    
    return n;
}


int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    
    string g;
    string wall;
    int lG, lWall;
    int parola[52];
    int current[52];
    deque<char> leggi;
    
    in >> lG >> lWall;
    
    in >> g;
    
    for(int i = 0; i < 52; i++)
	parola[i] = current[i] = 0;
    
    for(int i = 0; i < lG; i++)
	parola[toNum(g[i])]++;
    
    int cont = 0;

    char a = in.get();
    for(int i = 0; i < lWall; i++)
    {	
	a = in.get();
	int n = toNum(a);
	leggi.push_back(n);
	current[leggi.back()]++;
	while(current[leggi.back()] > parola[leggi.back()])
	{
	    current[leggi.front()]--;
	    leggi.pop_front();
	}
	if(leggi.size() == lG) cont++;
    } 

    out << cont;
    
    return 0;
}
