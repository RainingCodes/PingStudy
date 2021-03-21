#include <stdio.h>
//#include <stdlib.h>
int max(int a, int b)
{
	return  a > b ? a : b;
}
int main(void)
{
	int n,i;
	int stairs[300]; //계단의 값들이 있는 배열
	int sum[300]; //올라간 계단까지의 최댓값들이 있는 배열
	int a, b;

	//printf("Enter a number: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) 
		scanf("%d", &stairs[i]);
	
	sum[0] = stairs[0];
	sum[1] = stairs[0] + stairs[1];
	//첫번째 계단 -> 세번째 계단, 두번째 계단 -> 세번째 계단
	sum[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (i = 3; i < n; i++) {
		//1) 현재 계단의 전 계단을 밟았다면 전전계단을 밟을 수 없음
		a = sum[i - 3] + stairs[i - 1] + stairs[i];
		//2) 현재 계단의 전 계단을 밟지 않았다면 전전계단을 밟을 수 있음
		b = sum[i - 2] + stairs[i];
		//위 둘 중의 최댓값 저장
		sum[i] = max(a, b);
	}

	printf("%d", sum[n - 1]);
}