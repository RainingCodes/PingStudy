#include <stdio.h>
#include <stdlib.h>
void quickSort(int **, int, int);
int partition(int **, int, int);
void swap(int **, int, int);
void printList(int **, int, int);
int main() {
	int N, i;
	int **coordinates;
	scanf("%d", &N);
	coordinates = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++) {
		coordinates[i] = (int *) malloc(sizeof(int) * 2);
		scanf("%d %d", &coordinates[i][0], &coordinates[i][1]);
		
	}
	quickSort(coordinates, 0, i - 1);
	printList(coordinates, 0, i - 1);
}
void swap(int **c, int a, int b)
{
	int tmp[1][2];
	tmp[0][0] = c[a][0];
	tmp[0][1] = c[a][1];
	c[a][0] = c[b][0];
	c[a][1] = c[b][1];
	c[b][0] = tmp[0][0];
	c[b][1] = tmp[0][1];
}
int partition(int **c, int p, int r)
{
	int i, j;
	for(i = p - 1, j = p; j < r; j++) 
		if(c[j][0] < c[r][0] || (c[j][0] == c[r][0] && c[j][1] < c[r][1])) {
			i++;
			swap(c, i, j);
		}	
	i++;
	swap(c, i, r);
	return i;
}

void quickSort(int **c, int p, int r) {
	int q;
	if(p < r) {
		q = partition(c, p, r);
		quickSort(c, p, q -1);
		quickSort(c, q + 1, r);
	}
}
void printList(int **c, int s, int e)
{
	int i, j;
	for(i = s; i <= e; i++)
		printf("%d %d\n", c[i][0], c[i][1]);
}
