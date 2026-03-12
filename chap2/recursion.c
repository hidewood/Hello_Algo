#include <stdio.h>

int forLoopRecur(int n) {
    int stack[1000];
    int top = -1;  // 模拟栈顶
    int res = 0;

    for(int i = n; i > 0; i --) {  // 更好地模拟栈的行为，n放在栈底
        stack[1 + top++] = i;
    }
    while(top >= 0) {
        res += stack[top--];
    }

    return res;
}

int main()
{
    printf("%d\n", forLoopRecur(100));
    return 0;
}