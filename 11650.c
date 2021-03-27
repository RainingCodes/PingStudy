#include <stdio.h>
#include <stdlib.h>
typedef struct point
{
	int x;
	int y;
} point;
//합병정렬
void merge(point* A, int p, int q, int r)
{
	int i = p, j = q + 1, k = 0;
	int a;
	point* temp;
	temp = (point*)malloc(sizeof(point) * (r - p + 1));

	while (i <= q && j <= r) {
		//x좌표를 먼저 비교
		if (A[i].x < A[j].x)
			temp[k] = A[i++];
		else if (A[i].x > A[j].x)
			temp[k] = A[j++];
		//x좌표가 같은 경우 y좌표 비교
		else {
			if (A[i].y < A[j].y)
				temp[k] = A[i++];
			else
				temp[k] = A[j++];
		}
		k++;

	}
	while (i <= q)
		temp[k++] = A[i++];
	while (j <= r)
		temp[k++] = A[j++];

	a = 0;
	for (i = p; i <= r; i++)
		A[i] = temp[a++]; //인덱스가 같으면 안됨 

	free(temp);

}
void mergeSort(point* A, int p, int r)//A[p … r]을 정렬
{
	int q;

	if (p == r)
		return;

	q = (p + r) / 2; //middle 계산
	mergeSort(A, p, q); //전반부 정렬
	mergeSort(A, q + 1, r); //후반부 정렬
	merge(A, p, q, r); //병합

}
void selectionSort(point* A, int n)
{
	int i, j;
	int min, min_idx;
	point temp = { 0, 0 };

	for (i = 0; i < n - 1; i++) { //n-1 반복
		min = 1000;
		min_idx = 0;
		for (j = 0; j <= n - 1 - i; j++)
			if (min >= A[j].x)
			{
				min = A[j].x;
				min_idx = j;
			}
		temp = A[min_idx];
		A[min_idx] = A[n - 1 - i];
		A[n - 1 - i] = temp;
	}
}

int main(void)
{
	int n, i;
	point* p;

	printf("Enter a number: ");
	scanf("%d", &n);

	p = (point*) malloc(sizeof(point) * n);

	for (i = 0; i < n; i++)
		scanf("%d %d", &p[i].x, &p[i].y);

	mergeSort(p, 0, n - 1);

	for (i = 0; i < n; i++)
		printf("%d %d\n", p[i].x, p[i].y);

	free(p);
}