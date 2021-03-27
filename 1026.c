#include <stdio.h>
#include <stdlib.h>
//�������� ��������
void ascendingSelectionSort(int* A, int n)
{
	int i, j;
	int max, max_idx;

	for (i = 0; i < n - 1; i++) { //n-1 �ݺ�
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
//�������� ��������
void descendingSelectionSort(int* A, int n)
{
	int i, j;
	int min, min_idx;

	for (i = 0; i < n - 1; i++) { //n-1 �ݺ�
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

	//a �迭�� ��������, b�迭�� ������������ ����
	ascendingSelectionSort(a, n);
	descendingSelectionSort(b, n);

	//���� ū ���� ���� ���� ���� ���� ������ ���ϸ� �ּڰ��� ����
	for (i = 0; i < n; i++) 
		result += a[i] * b[i];
	
	printf("%d", result);

	free(a);
	free(b);
}