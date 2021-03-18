#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int sq[1001] = { 0 };
int check(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	
	if (sq[n - 2] == 0)
		sq[n - 2] = check(n - 2) % 10007;
	if (sq[n - 1] == 0)
		sq[n - 1] = check(n - 1) % 10007;
	
	sq[n] = (sq[n - 2] + sq[n - 1]) % 10007;

	return sq[n];
	
}
int main()
{
	int n, ans;

	scanf("%d", &n);

	ans = check(n);

	printf("%d\n", ans % 10007);
}