#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 基于环形数组实现的队列 */
typedef struct {
    int *nums;
    int front;
    int queSize;  // 不需要队尾索引
    int queCapacity;
} ArrayQueue;

/* 构造函数 */
ArrayQueue *newArrayQueue(int capacity) {
    ArrayQueue *queue = (ArrayQueue *)malloc(sizeof(ArrayQueue));
    queue->queCapacity = capacity;
    queue->nums = (int *)malloc(sizeof(int) * queue->queCapacity);
    queue->front = queue->queSize = 0;
    return queue;
}

/* 析构函数 */
void delArrayQueue(ArrayQueue *queue) {
    free(queue->nums);
    free(queue);
}

/* 获取队列的容量 */
int capacity(ArrayQueue *queue) {
    return queue->queCapacity;
}

/* 获取队列的长度 */
int size(ArrayQueue *queue) {
    return queue->queSize;
}

/* 判断队列是否为空 */
bool empty(ArrayQueue *queue) {
    return queue->queSize == 0;
}

/* 访问队首元素 */
int peek(ArrayQueue *queue) {
    if (empty(queue)) {
        printf("队列为空！\n");
        return -1;
    }
    else {
        return queue->nums[queue->front];
    }
}

/* 入队 */
void push(ArrayQueue *queue, int num) {
    if (queue->queSize == capacity(queue)) {
        printf("队列已满！\n");
        return ;
    }
    else {
        int rear = (queue->front + queue->queSize) % queue->queCapacity;
        queue->nums[rear] = num;
        queue->queSize++;
    }
}

/* 出队 */
int pop(ArrayQueue *queue) {
    int num = peek(queue);
    queue->front = (queue->front + 1) % queue->queCapacity;
    queue->queSize --;
    return num;
}

/* 返回数组用于打印 */ 
int *toArray(ArrayQueue *queue, int *queSize) {
    *queSize = queue->queSize;
    int *res = (int *)calloc(queue->queSize, sizeof(int));
    int j = queue->front;
    for (int i = 0; i < queue->queSize; i ++) {
        res[i] = queue->nums[j % queue->queCapacity];
        j ++;
    }
    return res;
}

int main() {
    // 1. 初始化一个容量为 5 的环形队列
    int cap = 5;
    ArrayQueue *q = newArrayQueue(cap);
    printf("--- 环形数组队列测试 ---\n");

    // 2. 测试入队 (Push) 直到满
    printf("入队: 10, 20, 30, 40, 50\n");
    for (int i = 1; i <= 5; i++) {
        push(q, i * 10);
    }
    
    // 3. 测试队列已满的情况
    printf("尝试在满载时入队 (60): ");
    push(q, 60); 

    // 4. 使用 toArray 打印当前队列
    int count = 0;
    int *arr = toArray(q, &count);
    printf("当前队列内容 (长度 %d): ", count);
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    free(arr); // 必须释放 toArray 申请的内存

    // 5. 测试出队 (Pop) 并观察环形移动
    printf("出队两次: %d, %d\n", pop(q), pop(q));
    
    // 6. 再次入队，测试“环形”空间复用
    printf("再次入队: 70, 80\n");
    push(q, 70);
    push(q, 80);

    // 7. 最终查看队列顺序
    arr = toArray(q, &count);
    printf("此时队列内容 (注意顺序应为 30, 40, 50, 70, 80): \n");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    free(arr);

    // 8. 清空并销毁
    printf("清空队列...\n");
    while (!empty(q)) {
        printf("Pop: %d | Size: %d\n", pop(q), size(q));
    }
    
    delArrayQueue(q);
    printf("--- 测试结束，内存已释放 ---\n");

    return 0;
}
