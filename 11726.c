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
		//n = 1�� �� 1����, n = 2�� �� 2����, n = 3�� �� 3����, n = 4�� �� 5����, n = 5�� �� 8���� ...
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;

	printf("%d", dp[n - 1]);
	
	free(dp);

}