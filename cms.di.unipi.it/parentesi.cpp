#include <cstdio>
#include <stack>

using namespace std;

bool chiude(char a)
{
	if(a == '(' || a == '[' || a == '<' || a == '{') return false;
	else return true;
}

int tipo(char a)
{
	if(a == '(' || a == ')') return 1;
	if(a == '[' || a == ']') return 2;
	if(a == '{' || a == '}') return 3;
	if(a == '<' || a == '>') return 4;
	return -1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int N; scanf("%d\n", &N);
	char c;
	stack<int> q;
	bool corr = true;
	
	for(int i = 0; i < N; ++i)
	{
		c = getchar_unlocked();
		if(chiude(c))
		{
			if(!q.empty())
			{
				if(q.top() == tipo(c)) q.pop();
				else
				{
					corr = false;
					break;
				}
			}
			else 
			{
				corr = false;
				break;
			}
		}
		else q.push(tipo(c));
	}
	
	if(corr && q.empty()) printf("corretta\n");
	else printf("malformata\n");
	
	return 0;
}
