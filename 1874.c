//20190936 고지수 백준 1874
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
  
    //입력값 받기
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    i = 0; //수열의 인덱스
    j = 1; //스택에 넣는 정수
    do {
        //스택의 top이 수열의 현재 수 보다 작으면 push
        if (top == -1 || stack[top] < arr[i]) {
            stack[++top] = j++;
            result[r_index++] = '+';
        }
        //스택의 top이 수열의 현재 수와 같으면 pop
        else if (stack[top] == arr[i]) {
            top--;
            result[r_index++] = '-';
            i++;
        }
        //스택의 top이 수열의 현재 수 보다 크면 "NO"
        else {
            printf("NO");
            flag = 0;
            break;
        }

    } while (!(r_index == max_size)); //결과값 배열을 다 채우면 종료

    //결과 출력
    if (flag)
        for (i = 0; i < max_size; i++)
            printf("%c\n", result[i]);

    free(arr);
  
}