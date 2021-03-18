#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;
void init_stack(StackType* s)
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
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
int check_seq(const int* seq[], int n)
{
	StackType s;
	char ans[200000];
	int index = 0, j = 0;
	init_stack(&s);
	for (int i = 1; i <= n; i++) {
		push(&s, i);
		ans[index++] = '+';
		while (peek(&s) == seq[j]) {
			pop(&s);
			ans[index++] = '-';
			j++;
			if (is_empty(&s)) break;
		}
	}
	ans[index] = '\n';
	if (is_empty(&s)) {
		for (int i = 0; ans[i] != '\n'; i++) {
			printf("%c\n", ans[i]);
		}
	}
	else return 0;
}
int main()
{
	int n;
	int seq[100000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}
	if (check_seq(seq, n) == 0)
		printf("NO\n");
}