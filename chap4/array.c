#include <stdio.h>
#include <stdlib.h>

// 随机访问元素
int randomAccess(int* nums, int size) {
    // 在 [0, size)中随机选择一个元素
    int randomIndex = rand() % size;   // rand生成的是伪随机数
    
    int randomNum = nums[randomIndex];
    return randomNum;
}

// 插入元素
// 我们这里的size是指数组实际的大小，包括其为0的位置，其最后一个元素会被覆盖
void insert(int *nums, int size, int num, int index) {
    for (int i = size - 1; i > index; i --) {
        nums[i] = nums[i - 1];
    }
    nums[index] = num;
}

// 删除元素
void removeItem(int *nums, int size, int index) {
    for (int i = index; i < size - 1; i ++) {
        nums[i] = nums[i + 1];
    }
}

// 打印数组
void printArray(int *nums, int size) {
    for (int i = 0; i < size - 1; i ++) {
        printf("%d ", nums[i]);
    }
    printf("%d\n", nums[size - 1]);
}

// 遍历数组
void traverse(int *nums, int size) {
    int count = 0;
    for (int i = 0; i < size; i ++) {
        count += nums[i];
    }
    printf("count = %d\n", count);
}

// 查找元素
int find(int *nums, int size, int target) {
    for (int i = 0; i < size; i ++) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

// 扩容数组
int *extend(int *nums, int size, int enlarge) {
    // 初始化一个扩展长度后的数组
    int *res = (int *)malloc(sizeof(int) * (size + enlarge));
    // 将原数组中的所有元素复制到新数组
    for (int i = 0; i < size; i ++) {
        res[i] = nums[i];
    }
    // 初始化扩展后的空间
    for (int i = size; i < size + enlarge; i ++) {
        res[i] = 0;
    }
    // 返回扩展后的新数组
    return res;
}

int main()
{
    // 因为索引本质上是内存地址的偏移量，所以首个元素的下标为0
    int nums[5] = {1, 2, 3, 4, 5};

    // 随机访问元素
    printf("随机访问的结果是：%d\n", randomAccess(nums, sizeof(nums) / sizeof(nums[0])));

    // 插入元素
    insert(nums, sizeof(nums) / sizeof(nums[0]), 9, 1);
    printArray(nums, sizeof(nums) / sizeof(nums[0]));

    // 删除元素
    removeItem(nums, sizeof(nums) / sizeof(nums[0]), 1);
    printArray(nums, sizeof(nums) / sizeof(nums[0]));

    // 遍历数组
    traverse(nums, sizeof(nums) / sizeof(nums[0]));

    // 查找元素
    int index = find(nums, sizeof(nums) / sizeof(nums[0]), 4);
    if (index == -1) {
        printf("没找到\n");
    } else {
        printf("找到了，下标为: %d\n", index);
    }

    // 扩容数组
    // 这里有一个出错点，就是不能通过sizeof(newArray) / sizeof(newArray[0]) 的方式计算数组长度了，因为新数组是通过指针来索引的，我们sizeof到的是固定的指针的大小。
    int *newArray = extend(nums, sizeof(nums) / sizeof(nums[0]), 10);
    printf("新数组为：\n");
    printArray(newArray, sizeof(nums) / sizeof(nums[0]) + 10);

    return 0;
}
