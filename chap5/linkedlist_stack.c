#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/* 链表结构体 */
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

/* 基于链表实现的栈 */
typedef struct {
    ListNode *top;
    int size;
} LinkedListStack;

/* 构造函数 */
LinkedListStack *newLinkedListStack() {
    LinkedListStack *s = (LinkedListStack *)malloc(sizeof(LinkedListStack));
    s->top = NULL;
    s->size = 0;
    return s;
}

/* 析构函数 */
void delLinkedListStack(LinkedListStack *s) {
    while (s->top) {
        ListNode *n = s->top->next;
        free(s->top);
        s->top = n;
    }
    free(s);
}

/* 获取栈的长度 */
int size(LinkedListStack *s) {
    return s->size;
}

/* 判断栈是否为空 */
bool isEmpty(LinkedListStack *s) {
    return size(s) == 0;
}

/* 入栈 */
void push(LinkedListStack *s, int num) {
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node->next = s->top;
    node->val = num;
    s->top = node;
    s->size ++;
}

/* 访问栈顶元素 */
int peek(LinkedListStack *s) {
    if (size(s) == 0) {
        printf("栈为空\n");
        return INT_MAX;
    }
    return s->top->val;
}

/* 出栈 */
int pop(LinkedListStack *s) {
    if (size(s) == 0) {
        printf("栈为空\n");
        return INT_MAX;
    }
    int val = peek(s);
    ListNode *temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
    return val;
}

/* 打印栈内元素 */
void printStack(LinkedListStack *s) {
    if (size(s) == 0) {
        printf("栈为空\n");
        return ;
    }
    // 注意：不要动用我们的全局指针，否则会导致栈变为空栈。
    ListNode *cur = s->top;

    while (cur) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

int main()
{
    LinkedListStack *s = newLinkedListStack();

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);

    //printf("栈顶元素：%d\n", peek(s));
    printStack(s);

    pop(s);

    printStack(s);

    //printf("栈顶元素：%d\n", peek(s));

    return 0;
}