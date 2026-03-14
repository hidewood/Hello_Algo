#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 链表结构体 */
typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

/* 基于链表实现的队列 */
typedef struct {
    ListNode *front, *rear;
    int queSize;
} LinkedListQueue;

/* 构造函数 */
LinkedListQueue *newLinkedListQueue() {
    LinkedListQueue *queue = (LinkedListQueue *)malloc(sizeof(LinkedListQueue));

    queue->front = NULL;
    queue->rear = NULL;
    queue->queSize = 0;

    return queue;
}

/* 析构函数 */
void delLinkedListQueue(LinkedListQueue *queue) {
    while (queue->front != NULL) {
        ListNode *tmp = queue->front;
        queue->front = queue->front->next;
        free(tmp);
    }
    free(queue);
}

/* 获取队列的长度 */
int size(LinkedListQueue *queue) {
    return queue->queSize;
}

/* 判断队列是否为空 */
bool empty(LinkedListQueue *queue) {
    return queue->queSize == 0;
}

/* 入队 */
void push(LinkedListQueue *queue, int num) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = num;
    node->next = NULL;

    if (queue->front == NULL) {
        queue->front = node;
        queue->rear = node;
    }
    else {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->queSize ++;
}

/* 访问队首元素 */
int peek(LinkedListQueue *queue) {
    if (queue->queSize == 0) {
        printf("队列为空！\n");
        return -1;
    }
    return queue->front->val;
}

/* 出队 */
int pop(LinkedListQueue *queue) {
    if (queue->queSize == 0) {
        printf("队列为空！\n");
        return -1;
    }
    int temp = queue->front->val;
    // 这里不需要malloc，直接指向就行。
    ListNode *tmp = queue->front;; 
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(tmp);
    queue->queSize --;
    return temp;
}

/* 打印队列 */
void printLinkedListQueue(LinkedListQueue *queue) {
    if (queue->queSize == 0) {
        printf("队列为空！\n");
        return ;
    }
    else {
        // 同理不需要malloc
        ListNode *tmp = queue->front;
        while (tmp) {
            printf("%d ", tmp->val);
            tmp = tmp->next;
        }
        printf("\n");
    }
}

int main() {
    // 1. 初始化队列
    LinkedListQueue *q = newLinkedListQueue();
    printf("--- 队列功能测试 ---\n");

    // 2. 测试入队 (Push)
    printf("正在入队: 10, 20, 30\n");
    push(q, 10);
    push(q, 20);
    push(q, 30);
    printf("当前队列内容: ");
    printLinkedListQueue(q);
    printf("队列长度: %d\n\n", size(q));

    // 3. 测试查看队首 (Peek)
    printf("当前队首元素 (peek): %d\n\n", peek(q));

    // 4. 测试出队 (Pop)
    printf("执行出队 (pop): %d\n", pop(q));
    printf("执行出队 (pop): %d\n", pop(q));
    printf("当前队列内容: ");
    printLinkedListQueue(q);
    printf("队列长度: %d\n\n", size(q));

    // 5. 测试清空队列
    printf("再次执行出队: %d\n", pop(q));
    printf("此时队列是否为空: %s\n", empty(q) ? "是" : "否");
    printLinkedListQueue(q); // 预期输出：队列为空！
    printf("\n");

    // 6. 测试在空队列上操作 (异常处理)
    printf("尝试在空队列执行 pop: ");
    pop(q);
    printf("尝试在空队列执行 peek: ");
    peek(q);
    printf("\n");

    // 7. 再次入队测试
    printf("重新入队: 100\n");
    push(q, 100);
    printf("当前队列内容: ");
    printLinkedListQueue(q);

    // 8. 销毁队列，释放内存
    delLinkedListQueue(q);
    printf("--- 测试结束，内存已释放 ---\n");

    return 0;
}