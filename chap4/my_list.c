// C语言实现列表list

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *arr;
    int capacity;
    int size;
    int extendRatio;
}MyList;

// 构造函数
MyList *newMyList() {
    MyList *mylist = (MyList *)malloc(sizeof(MyList));
    mylist->capacity = 10;
    mylist->arr = (int *)malloc(sizeof(int) * (mylist->capacity));
    mylist->size = 0;
    mylist->extendRatio = 2;

    return mylist;
}

// 析构函数
void delMyList(MyList *nums) {
    free(nums->arr);
    free(nums);
}

// 获取列表长度
int size(MyList *nums) {
    return nums->size;
}

// 获取列表容量
int capacity(MyList *nums) {
    return nums->capacity;
}

// 列表扩容
void extendCapacity(MyList *nums) {
    int newCapacity = capacity(nums) * nums->extendRatio;
    int *extend = (int *)malloc(sizeof(int) * newCapacity);
    int *temp = nums->arr;

    // 将旧数据拷贝到新数据
    for (int i = 0; i < size(nums); i ++) extend[i] = nums->arr[i];

    free(temp);

    nums->arr = extend;
    nums->capacity = newCapacity;
}

// 访问元素
int get(MyList *nums, int index) {
    if (index < 0 || index >= nums->size)  return -1;
    return nums->arr[index];
}

// 更新元素
void set(MyList *nums, int index, int num) {
    if (index < 0 || index >= nums->size)  return ;
    nums->arr[index] = num;
}

// 在尾部添加元素
void add(MyList *nums, int num) {
    if (size(nums) == capacity(nums))  extendCapacity(nums);
    nums->arr[size(nums)] = num;
    nums->size++;
}

// 在中间插入元素
void insert(MyList *nums, int index, int num) {
    if (index < 0 || index >= nums->size)  return ;

    if (size(nums) == capacity(nums))  extendCapacity(nums);
    for (int i = size(nums); i > index; i --) {
        nums->arr[i] = nums->arr[i - 1];
    }
    nums->arr[index] = num;
    nums->size ++;
}

// 删除元素
int removeItem(MyList *nums, int index) {
    if (index < 0 || index >= nums->size)  return -1;

    int num = nums->arr[index];
    for (int i = index; i < size(nums) - 1; i ++) {
        nums->arr[i] = nums->arr[i + 1];
    }
    nums->size --;
    return num;
}

// 将列表转换为 Array 用于打印
int *toArray(MyList *nums) {
    return nums->arr;
}

int main() {
    // 1. 初始化列表
    MyList *list = newMyList();
    printf("--- 初始化列表 ---\n");
    printf("長度: %d, 容量: %d\n\n", size(list), capacity(list));

    // 2. 測試 add (添加 12 個元素，觸發從 10 到 20 的擴容)
    printf("--- 測試連續添加 (觸發擴容) ---\n");
    for (int i = 1; i <= 12; i++) {
        add(list, i * 10);
    }
    printf("添加後長度: %d, 容量: %d\n", size(list), capacity(list));
    printf("當前元素: ");
    for (int i = 0; i < size(list); i++) {
        printf("%d ", get(list, i));
    }
    printf("\n\n");

    // 3. 測試 insert (在索引 2 插入 99)
    printf("--- 測試中間插入 ---\n");
    insert(list, 2, 99);
    printf("在索引 2 插入 99 後: ");
    for (int i = 0; i < size(list); i++) {
        printf("%d ", get(list, i));
    }
    printf("\n\n");

    // 4. 測試 removeItem (刪除索引 0 的元素)
    printf("--- 測試刪除元素 ---\n");
    int removed = removeItem(list, 0);
    printf("刪除了: %d\n", removed);
    printf("刪除後剩餘元素: ");
    for (int i = 0; i < size(list); i++) {
        printf("%d ", get(list, i));
    }
    printf("\n\n");

    // 5. 測試 set (修改索引 1 的值)
    printf("--- 測試更新元素 ---\n");
    set(list, 1, 888);
    printf("將索引 1 修改為 888 後: %d\n", get(list, 1));

    // 6. 釋放內存
    delMyList(list);
    printf("\n--- 測試結束，內存已釋放 ---\n");

    return 0;
}
