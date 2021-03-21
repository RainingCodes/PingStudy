#include <stdio.h>
#include <stdlib.h>
#define ONESTEP 0
#define TWOSTEP 1
int scoring(int, int, int *, int **);
int main(void)
{
	int N, i, j;
	int *score;
	int max, tmp;
	int **M;
	scanf("%d", &N);
	score = (int *) malloc(sizeof(int) * N);
	M = (int **)malloc(sizeof(int *) * (N + 1));

	for(i = 0; i < N; i++) {
		M[i + 1] = (int *) malloc(sizeof(int) * 2);
		scanf("%d", &score[i]);
		for(j = 0; j < 2; j++)
			M[i + 1][j] = 0;
	}
	max = scoring(N, ONESTEP, score, M);
	if(max < (tmp = scoring(N, TWOSTEP, score, M)))
		max = tmp;
	printf("%d", max);
}
int scoring(int N, int step, int *score, int **M)
{
	if(N == 1) 
		return score[N - 1];

	if(step == ONESTEP) {
		if(!M[N - 1][TWOSTEP])
			M[N - 1][TWOSTEP] = scoring(N - 1, TWOSTEP, score, M);
		M[N][step] = M[N - 1][TWOSTEP] + score[N - 1];
	}
	else {
		if(N == 2) 
			M[N][step] = score[N - 1];
		else {
			if(!M[N - 2][ONESTEP])
				M[N - 2][ONESTEP] = scoring(N - 2, ONESTEP, score, M);
			if(!M[N - 2][TWOSTEP])
				M[N - 2][TWOSTEP] = scoring(N - 2, TWOSTEP, score, M);
			M[N][step] = score[N - 1] + (M[N - 2][ONESTEP] > M[N - 2][TWOSTEP] ? M[N - 2][ONESTEP] : M[N - 2][TWOSTEP]);
		}
	}
	return M[N][step];
}
