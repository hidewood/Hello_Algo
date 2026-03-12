#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
}ListNode;

// 构造函数
ListNode *newListNode(int val) {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// 遍历链表
void traverse(ListNode *node) {
    while (node != NULL) {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");
}

// 插入节点
void insert(ListNode *n0, ListNode *P) {
    ListNode *n1 = n0->next;
    P->next = n1;
    n0->next = P;
}

// 删除节点(n0之后)
void removeItem(ListNode *n0) {
    // 如果已经是最后一个节点
    if (!n0->next)  return ;

    ListNode* P = n0->next;
    ListNode* n1 = P->next;
    n0->next = n1;
    // 注意释放内存
    free(P);
}

// 访问节点(索引为index)
ListNode *access(ListNode *head, int index) {
    for (int i = 0; i < index; i ++) {
        if (head == NULL) return NULL;
        head = head->next;
    }
    return head;
}

// 查找节点
int find(ListNode *head, int target) {
    int index = 0;
    while (head) {
        if (head->val == target) return index;
        head = head->next;
        index ++;
    }
    return -1;
}

int main()
{
    // 初始化链表
    ListNode *n0 = newListNode(1);
    ListNode *n1 = newListNode(2);
    ListNode *n2 = newListNode(3);
    ListNode *n3 = newListNode(4);
    ListNode *n4 = newListNode(5);
    
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    traverse(n0);

    // 插入节点
    ListNode *n5 = newListNode(6);
    insert(n2, n5);
    traverse(n0);  // 预期 1 2 3 6 4 5

    // 删除节点
    removeItem(n2);
    traverse(n0);

    // 访问节点
    ListNode *cur = access(n0, 3);
    printf("cur = %d\n", cur->val);


    return 0;
}

// 题外话 —— 关于为什么定义结构体时需要将前驱/后继定义为指针的形式
/* 双向链表节点结构体 */
// typedef struct ListNode {
//     int val;               // 节点值
//     struct ListNode *next; // 指向后继节点的指针
//     struct ListNode *prev; // 指向前驱节点的指针
// } ListNode;

// 如上所示，我们的前驱和后继都使用指针来表示，这是因为我们的前驱和后继相对于本节点来说都是独立的，
// 他们有自己的信息，如果我们去掉指针，则前驱和后继就会变成本节点的附属品。
// 如果我们想独立地处理每个节点，则必须使用指针操作。
