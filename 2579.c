#include <stdio.h>
//#include <stdlib.h>
int max(int a, int b)
{
	return  a > b ? a : b;
}
int main(void)
{
	int n,i;
	int stairs[300]; //����� ������ �ִ� �迭
	int sum[300]; //�ö� ��ܱ����� �ִ񰪵��� �ִ� �迭
	int a, b;

	//printf("Enter a number: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++) 
		scanf("%d", &stairs[i]);
	
	sum[0] = stairs[0];
	sum[1] = stairs[0] + stairs[1];
	//ù��° ��� -> ����° ���, �ι�° ��� -> ����° ���
	sum[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);

	for (i = 3; i < n; i++) {
		//1) ���� ����� �� ����� ��Ҵٸ� ��������� ���� �� ����
		a = sum[i - 3] + stairs[i - 1] + stairs[i];
		//2) ���� ����� �� ����� ���� �ʾҴٸ� ��������� ���� �� ����
		b = sum[i - 2] + stairs[i];
		//�� �� ���� �ִ� ����
		sum[i] = max(a, b);
	}

	printf("%d", sum[n - 1]);
}