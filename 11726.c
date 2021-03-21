#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, i;
	int *dp;

	scanf("%d", &n);

	dp = (int*)malloc(sizeof(int) * n);

	dp[0] = 1;
	dp[1] = 2;

	for (i = 2; i < n; i++)
		//n = 1일 때 1가지, n = 2일 때 2가지, n = 3일 때 3가지, n = 4일 때 5가지, n = 5일 때 8가지 ...
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;

	printf("%d", dp[n - 1]);
	
	free(dp);

}