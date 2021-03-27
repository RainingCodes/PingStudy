#include <stdio.h>
#include <stdlib.h>
//오름차순 선택정렬
void ascendingSelectionSort(int* A, int n)
{
	int i, j;
	int max, max_idx;

	for (i = 0; i < n - 1; i++) { //n-1 반복
		max = A[0]; max_idx = 0;
		for (j = 1; j <= n - 1 - i; j++)
			if (max <= A[j])
			{
				max = A[j];
				max_idx = j;
			}
		A[max_idx] = A[n - 1 - i];
		A[n - 1 - i] = max;

	}
}
//내림차순 선택정렬
void descendingSelectionSort(int* A, int n)
{
	int i, j;
	int min, min_idx;

	for (i = 0; i < n - 1; i++) { //n-1 반복
		min = 100;
		min_idx = 0;
		for (j = 0; j <= n - 1 - i; j++)
			if (min >= A[j])
			{
				min = A[j];
				min_idx = j;
			}
		A[min_idx] = A[n - 1 - i];
		A[n - 1 - i] = min;
	}
}
int main(void)
{
	int n, i;
	int* a;
	int* b;
	int result = 0;

	scanf("%d", &n);

	a = (int*)malloc(sizeof(int) * n);
	b = (int*)malloc(sizeof(int) * n);

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &b[i]);

	//a 배열을 오름차순, b배열을 내림차순으로 정렬
	ascendingSelectionSort(a, n);
	descendingSelectionSort(b, n);

	//제일 큰 수와 제일 작은 값을 곱한 값들을 더하면 최솟값이 나옴
	for (i = 0; i < n; i++) 
		result += a[i] * b[i];
	
	printf("%d", result);

	free(a);
	free(b);
}