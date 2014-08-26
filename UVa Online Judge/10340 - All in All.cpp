#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;

    while(cin >> s >> t)
    {
        bool found = true;
        int c = 0;

        for(int i = 0; i < (int)t.length() && found; i++)
            if(s[c] == t[i]) c++;

        (c == (int)s.size()) ? cout << "Yes\n" : cout << "No\n";
    }


    return 0;
}
