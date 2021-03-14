#include <stdio.h>
#define MAX_STACK_SIZE 100000
typedef int element;
typedef struct {
 element e[MAX_STACK_SIZE];
 int top;
} StackType;
char flag[MAX_STACK_SIZE * 2];
int i = 0;
void init(StackType *s)
{
 s->top = -1;
}

int is_empty(StackType *s)
{
 return s->top == -1;
}
 
StackType *push(StackType *s, element e)
{
	s->top++;
	s->e[s->top] = e;
	flag[i++] = '+';
 	return s;
}
 
element pop(StackType *s)
{
	flag[i++] = '-';
 	return s->e[s->top--];
}

int main() {
	int n, j, k;
	StackType s;
	element input;
	scanf("%d", &n);
	init(&s);
	k = 1;
	for(j = 0; j < n; j++)	{
		scanf("%d", &input);
		while(k <= input) 
			push(&s, k++);
		if(pop(&s) != input) {
			printf("NO\n");
			return 0;
		}
	}
	for(j = 0; j < i; j++)
		printf("%c\n", flag[j]);
}
