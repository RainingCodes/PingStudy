#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 51
typedef char element;
typedef struct {
 element e[MAX_STACK_SIZE];
 int top;
} StackType;
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
 return s;
}
 
element pop(StackType *s)
{
 return s->e[s->top--];
}

void checkString(element *);
int main() 
{
	int n, i;
	element *input = (element *) malloc(sizeof(element) * MAX_STACK_SIZE);
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s", input);
		checkString(input);
	}
}
void checkString(element *string) 
{
	StackType s;
	init(&s);
	element *p = string;
	while(*p) {
		if(*p == '(')
			push(&s, *p);
		else if(is_empty(&s)) {
			printf("NO\n");
			return;
		}
		else
			pop(&s);
		p++;
	}
	if(is_empty(&s))
		printf("YES\n");
	else
		printf("NO\n");
	return;
}
