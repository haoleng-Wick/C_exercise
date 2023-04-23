/*
 *
 * 用两个栈实现队列
 * 一个用来当作输入栈,另一个当作输出栈
 * 通过两个栈的互动实现翻转
 * 达到先进先出的效果
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 栈
typedef struct {
	int *base;
	int stk_size;
	int stk_max;
} Stack;

Stack *stack_create(int stk_max)
{
	Stack *stk = (Stack *)malloc(sizeof(Stack));
	stk->stk_max = stk_max;
	stk->base = (int *)malloc(sizeof(int) * stk_max);
	stk->stk_size = 0;
	return stk;
}

void stack_push(Stack *obj, int val)
{
	obj->base[(obj->stk_size)++] = val;
}

void stack_pop(Stack *obj)
{
	(obj->stk_size)--;
}

int stack_top(Stack *obj)
{
	return obj->base[(obj->stk_size) - 1];
}

bool stack_empty(Stack *obj)
{
	return obj->stk_size == 0;
}

void stack_free(Stack *obj)
{
	free(obj->base);
}

// 队列
typedef struct {
	Stack *in_stack;
	Stack *out_stack;
} CQueue;

CQueue *c_queue_create()
{
	CQueue *Q = (CQueue *)malloc(sizeof(CQueue));
	Q->in_stack = stack_create(1024);
	Q->out_stack = stack_create(1024);
	return Q;
}

// 将输入栈的栈顶元素压入输出栈
// 直至输入栈为空,即将输入栈的元素顺序反转
void in2out(CQueue *Q)
{
	while (!stack_empty(Q->in_stack)) {
		stack_push(Q->out_stack, stack_top(Q->in_stack));
		stack_pop(Q->in_stack);
	}
}

void c_queue_add(CQueue *Q, int val)
{
	stack_push(Q->in_stack, val);
}

int c_queue_del(CQueue *Q)
{
	// 如果输出栈是空的但输入栈不是空的,那么就...
	if (stack_empty(Q->out_stack)) {
		if (stack_empty(Q->in_stack)) {
			return -1;
		}
		in2out(Q);
	}
	int e = stack_top(Q->out_stack);
	stack_pop(Q->out_stack);
	return e;
}

int c_queue_size(CQueue *Q)
{
	return ((Q->in_stack->stk_size) + (Q->out_stack->stk_size));
}

void c_queue_free(CQueue *Q)
{
	stack_free(Q->in_stack);
	stack_free(Q->out_stack);
}

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		printf("Use: ./a.out <arr>\n");
		return -1;
	}
	int size = argc - 1;
	int val = 0;
	CQueue *Q = c_queue_create();
	for (int i = 0; i < size; ++i)
	{
		sscanf(argv[i + 1], "%d", &val);
		c_queue_add(Q, val);
	}

	size = c_queue_size(Q);
	printf("Queue's size = %d\n", size);
	printf("The output oreder is: [ ");
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", c_queue_del(Q));
	}
	printf("]\n");
	c_queue_free(Q);
	return 0;
}
