//20190936 고지수 백준 9012
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;
// 스택 초기화 함수
void init(StackType* s)
{
    s->top = -1;
}
// 공백 상태 검출 함수
int is_empty(StackType* s)
{
    return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->stack[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->stack[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->stack[s->top];
}
// 문자열 동적할당 함수
char* inputString()
{
    char stringValue[52];
    char* temp;
    //printf("입력: ");
    scanf("%s", stringValue);

    temp = (char*)malloc(sizeof(stringValue) + 1);
    strcpy(temp, stringValue);

    return temp;
}
//vps 테스트하는 함수
int check_VPS(char *input)
{
    StackType s;
    char ch; //다음문자
    char open;
    int i, n = strlen(input);
    init(&s);

    for (i = 0; i < n; i++) {
        ch = input[i]; //괄호를 하나씩 스택에 삽입
        switch (ch) {
        case '(': //여는 괄호면 스택에 삽입
            push(&s, ch);
            break;
        case ')': //닫는 괄호면 스택에서 pop
            if (is_empty(&s)) return 0;
            else
                open = pop(&s);
            break;
        }
    }

    if (!is_empty(&s)) return 0; //스택에 괄호가 남아있으면
    return 1;
    
}
int main(void)
{
   int size, i;
   char* vps;

   //printf("Enter a number: ");
   scanf("%d", &size);

   for (i = 0; i < size; i++) {
       vps = inputString(); //체크하려는 문자열을 동적할당
       if (check_VPS(vps))
           printf("YES");
       else
           printf("NO");
       printf("\n");
   }
}