int solve(int N, int K, int* S)
{    
    int curr = 0;
    int i;
    int j = 0;
    int sol = 0;
    
    for(i = N-1; i >= 0; i--)
    {
	if(S[i] == 0) sol++;
	curr += S[i];
    }
    
    i = 0;
    int soluzione = 0;
    
    while(j < N)
    {
	while(curr > K && i < N)
	{
	    if(S[i] == 0) sol--;
	    curr -= S[i++];
	}
	
	if(i == N && curr > K) break;
	
	if(j <= i && sol > soluzione) soluzione = sol;
	
	if(S[j] == 0) sol++;
	curr += S[j++];
    }

    return soluzione;
}
