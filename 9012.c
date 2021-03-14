//20190936 ������ ���� 9012
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
} StackType;
// ���� �ʱ�ȭ �Լ�
void init(StackType* s)
{
    s->top = -1;
}
// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
    return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
    return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType* s, element item)
{
    if (is_full(s)) {
        fprintf(stderr, "���� ��ȭ ����\n");
        return;
    }
    else s->stack[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->stack[(s->top)--];
}
// ��ũ�Լ�
element peek(StackType* s)
{
    if (is_empty(s)) {
        fprintf(stderr, "���� ���� ����\n");
        exit(1);
    }
    else return s->stack[s->top];
}
// ���ڿ� �����Ҵ� �Լ�
char* inputString()
{
    char stringValue[52];
    char* temp;
    //printf("�Է�: ");
    scanf("%s", stringValue);

    temp = (char*)malloc(sizeof(stringValue) + 1);
    strcpy(temp, stringValue);

    return temp;
}
//vps �׽�Ʈ�ϴ� �Լ�
int check_VPS(char *input)
{
    StackType s;
    char ch; //��������
    char open;
    int i, n = strlen(input);
    init(&s);

    for (i = 0; i < n; i++) {
        ch = input[i]; //��ȣ�� �ϳ��� ���ÿ� ����
        switch (ch) {
        case '(': //���� ��ȣ�� ���ÿ� ����
            push(&s, ch);
            break;
        case ')': //�ݴ� ��ȣ�� ���ÿ��� pop
            if (is_empty(&s)) return 0;
            else
                open = pop(&s);
            break;
        }
    }

    if (!is_empty(&s)) return 0; //���ÿ� ��ȣ�� ����������
    return 1;
    
}
int main(void)
{
   int size, i;
   char* vps;

   //printf("Enter a number: ");
   scanf("%d", &size);

   for (i = 0; i < size; i++) {
       vps = inputString(); //üũ�Ϸ��� ���ڿ��� �����Ҵ�
       if (check_VPS(vps))
           printf("YES");
       else
           printf("NO");
       printf("\n");
   }
}