#include <stdio.h>
#include <stdlib.h>
#define ASCENDING 0
#define DESCENDING 1
int partition(int [], int, int, int);
void quickSort(int *, int, int, int);
void swap(int [], int, int);
int getS(int *, int *, int);
int main() {
	int N, i;
	int *A;
	int *B;
	scanf("%d", &N);
	A = (int *) malloc(sizeof(int) * N);
	B = (int *) malloc(sizeof(int) * N);
	for(i = 0; i < N; i++)
		scanf("%d", &A[i]);
	quickSort(A, 0, N - 1, ASCENDING);
	for(i = 0; i < N; i++)
		scanf("%d", &B[i]);
	quickSort(B, 0, N - 1, DESCENDING);
	printf("%d", getS(A, B, N));
}
int partition(int A[], int p, int r, int f)
{
	int i, j;
	for(i = p - 1, j = p; j < r; j++) 
		if((f == ASCENDING && A[j] < A[r]) || (f == DESCENDING && A[j] > A[r])) {
			i++;
			swap(A, i, j);
		}
	i++;
	swap(A, i, r);
	return i;
}
void quickSort(int *A, int p, int r, int f)
{
	int q;
	if(p < r) {
		q = partition(A, p, r, f);
		quickSort(A, p, q - 1, f);
		quickSort(A, q + 1, r, f);
	}
}

void swap(int A[], int a, int b)
{
	int tmp;
	tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;
}
int getS(int *A, int *B, int N)
{
	int S = 0, i;
	for(i = 0; i < N; i++)
		S += A[i] * B[i];
	return S;
}
