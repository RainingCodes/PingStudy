#include <stdio.h>
#include <stdlib.h>
int rectangle(int, int *);
int main(void)
{
	int n, i, *M;
	scanf("%d", &n);
	M = (int *) malloc(sizeof(int) * (n + 1));
	for(i = 1; i <= n; i++)
		M[i] = 0;
	printf("%d", rectangle(n, M));
}
int rectangle(int n, int *M)
{
	if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	else {
		if(!M[n - 1])
			M[n - 1] = rectangle(n - 1, M);
		if(!M[n - 2])
			M[n - 2] = rectangle(n - 2, M);
		M[n] = M[n - 1] + M[n - 2];
		return M[n] % 10007;
	}
}
