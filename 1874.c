//20190936 ������ ���� 1874
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100000

char result[MAX_STACK_SIZE * 2];
int stack[MAX_STACK_SIZE];
int top = -1;
int main()
{
    int n, i, j, max_size;
    int* arr;
    int r_index = 0;

    int flag = 1;

    scanf("%d", &n);

    arr = (int*)malloc(sizeof(int) * n);
    max_size = n * 2;
  
    //�Է°� �ޱ�
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    i = 0; //������ �ε���
    j = 1; //���ÿ� �ִ� ����
    do {
        //������ top�� ������ ���� �� ���� ������ push
        if (top == -1 || stack[top] < arr[i]) {
            stack[++top] = j++;
            result[r_index++] = '+';
        }
        //������ top�� ������ ���� ���� ������ pop
        else if (stack[top] == arr[i]) {
            top--;
            result[r_index++] = '-';
            i++;
        }
        //������ top�� ������ ���� �� ���� ũ�� "NO"
        else {
            printf("NO");
            flag = 0;
            break;
        }

    } while (!(r_index == max_size)); //����� �迭�� �� ä��� ����

    //��� ���
    if (flag)
        for (i = 0; i < max_size; i++)
            printf("%c\n", result[i]);

    free(arr);
  
}