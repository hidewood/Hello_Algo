#include <stdio.h>
#include <stdlib.h>

/* 基于数组实现的栈 */
typedef struct {
    int *data;
    int size;
} ArrayStack;

/* 构造函数 */
ArrayStack *newArrayStack() {
    ArrayStack *stack = malloc(sizeof(ArrayStack));
    stack->data = malloc(sizeof(int) * MAX_SIZE);
    stack->size = 0;
    return stack;
}

/* 析构函数 */
void delArrayStack(ArrayStack *stack) {
    free(stack->data);
    free(stack);
}

/* 获取栈的长度 */
int size(ArrayStack *stack) {
    return stack->size;
}

/* 判断栈是否为空 */
bool isEmpty(ArrayStack *stack) {
    return stack->size == 0;
}

/* 入栈 */
void push(ArrayStack *stack, int num) {
    if (stack->size == MAX_SIZE) {
        printf("Stack is full~\n");
        return ;
    }
    stack->data[size(stack)] = num;
    stack->size ++;
}

/* 访问栈顶元素 */
int peek(ArrayStack *stack) {
    if (size(stack) == 0) {
        printf("Stack is empty~\n");
        return INT_MAX;
    }
    return stack->data[size(stack) - 1];
} 

/* 出栈 */
int pop(ArrayStack *stack) {
    int temp = stack->data[size(stack) - 1];
    stack->size --;

    return temp;
}

int main()
{   
    

    return 0;
}