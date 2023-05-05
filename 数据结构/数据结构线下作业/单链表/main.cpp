#include "def.h"
#include "functions.h"

const int N = 105; // 多表最大容量
const int NUM_OP = 21; // 操作选项数量
int num_list, now = 1; // num_list: 当前多表数量，now: 当前所在链表下标
LinkList g_list[N]; // 链表头结点数组

void init() { // 链表头结点初始化
    for (int i = 0; i < N; i++) {
        g_list[i] = nullptr;
    }
}

void run() {
    system("cls");
    printf("-----------------------------------------------------------------\n");
    printf("\t1. Creat and InitList\t\t2. DestroyList\n");
    printf("\t3. ClearList\t\t\t4. ListEmpty\n");
    printf("\t5. ListLength\t\t\t6. GetElem\n");
    printf("\t7. LocateElem\t\t\t8. PriorElem\n");
    printf("\t9. NextElem\t\t\t10. ListInsert\n");
    printf("\t11. ListDelete\t\t\t12. ListTraverse\n");
    printf("\t13. SaveList\t\t\t14. LoadList\n");
    printf("\t15. sortList\t\t\t16. reverseList\n");
    printf("\t17. RemoveNthFromEnd\t\t18. Create File\n");
    printf("\t19. List Shift\t\t\t20. Consecutive Insert\n");
    printf("\t21. Show Information\n");
    printf("-----------------------------------------------------------------\n");
    printf("Please input number [1~%d] to operate the list: ", NUM_OP);
    int op; // 输入的选项
    scanf("%d", &op);
    if (op < 1 || op > NUM_OP) { // 选项数字越界
        return (void)puts("Invalid input!");
    }
    if (op == 1) { // 初始化列表
        now = ++num_list;
        printf("Input the name of the list: ");
        char name[105]; // 输入的名字
        scanf("%s", name);
        int res = InitList(g_list[now], g_list, name, num_list); // 函数返回结果
        if (res == -1) { // 链表未初始化
            printf("Invalid operation, the list has already been initialized!\n");
            return;
        } else if (res == 0) { // 名字已被使用
            printf("The name has been used!\n");
            return;
        } else {
            printf("Initialization completed!\n");
            printf("List name: %s\n", g_list[now]->name);
            return;
        }
    } else if (op == 2) { // 销毁链表
        if (num_list == 0) {
            printf("There is no list!\n");
            return;
        }
        int res = DestroyList(g_list[now]); // 函数返回结果
        // printf("res = %d\n", res);
        if (res == -1) { // 链表未初始化
            printf("Invalid operation, you can't destory an uninitialized list!\n");
            return;
        } else { // 销毁成功
            printf("The list has been destroyed successfully!\n");
            return;
        }
    } else if (op == 3) { // 清空链表
        int res = ClearList(g_list[now]);
        if (res == -1) {
            printf("Invalid operation, you can't clear an uninitialized list!\n");
            return;
        } else {
            printf("The list has been cleared successfully!\n");
            return;
        }
    } else if (op == 4) { // 判断链表是否为空
        int res = ListEmpty(g_list[now]);
        if (res == -1) { // 链表为初始化
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else {
            if (res == 0) { // 非空
                printf("The list is not empty!\n");
            } else { // 空
                printf("The list is empty!\n");
            }
            return;
        }
    } else if (op == 5) { // 获取链表长度
        int res = ListLength(g_list[now]);
        if (res == -1) { // 链表未初始化
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else {
            printf("The length of the list is %d.\n", res);
        }
    } else if (op == 6) { // 获取链表对应位置的元素
        printf("Input the position: ");
        int pos; // 位置
        scanf("%d", &pos);
        int elem; // 元素
        int res = GetElem(g_list[now], pos, elem); // 函数返回结果
        if (res == -1) { // 链表未初始化
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else if (!res) { // 下标越界
            printf("Invalid position!\n");
            return;
        } else {
            printf("The %d-th element is %d\n", pos, elem);
        }
    } else if (op == 7) { // 查找对应位置的元素
        printf("Input the element that you want to search!\n");
        int elem; // 元素
        scanf("%d", &elem);
        int res = LocateElem(g_list[now], elem); // 函数返回结果
        if (res == -1) { // 链表未初始化
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else if (!res) { // 找不到元素
            printf("The element doesn't exist!\n");
            return;
        } else {
            printf("Element(%d) is at %d-th position.\n", elem, res);
            return;
        }
    } else if (op == 8) { // 获取元素前驱
        printf("Input the element: ");
        int elem; // 元素
        scanf("%d", &elem);
        int pre; // 保存前驱
        int res = PriorElem(g_list[now], elem, pre); // 函数返回结果
        if (res == -1) { // 链表未初始化
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else if (!res) { // 找不到前驱
            printf("Element doesn't exist!\n");
            return;
        } else {
            printf("The prior of %d is %d.\n", elem, pre);
        }
    } else if (op == 9) { // 寻找元素后继
        printf("Input the element: ");
        int elem; // 元素
        scanf("%d", &elem);
        int nex; // 保存后继
        int res = NextElem(g_list[now], elem, nex); // 函数返回结果
        if (res == -1) { // 链表为初始化
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else if (!res) { // 找不到后继
            printf("Element doesn't exist!\n");
            return;
        } else {
            printf("The next elem of %d is %d.\n", elem, nex);
        }
    } else if (op == 10) { // 插入元素到对应位置
        printf("Input the position(start from 1): ");
        int pos; // 位置
        scanf("%d", &pos);
        printf("Input the element that you want to insert: ");
        int elem; // 元素
        scanf("%d", &elem);
        int res = ListInsert(g_list[now], pos, elem);
        if (res == -1) { // 链表未初始化
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else if (res == 0) { // 下标越界
            printf("Position out of range!\n");
            return;
        } else {
            printf("Element has been inserted to the list successfully!\n");
            return;
        }
    } else if (op == 11) { // 删除元素
        printf("Input the positionf(start from 1): ");
        int pos; // 位置
        scanf("%d", &pos);
        int elem; // 元素
        int res = ListDelete(g_list[now], pos, elem); // 函数返回结果
        if (res == -1) { // 链表未初始化
            printf("Invalid operation, you can't operate an uninitialized list!\n");
            return;
        } else if (!res) { // 下标越界
            printf("Position out of range!\n");
            return;
        } else {
            printf("The %d-th element(%d) has been deleted successfully!\n", pos, elem);
            return;
        }
    } else if (op == 12) { // 遍历链表
        int res = ListTraverse(g_list[now]); // 函数返回结果
        if (res == -1) { // 链表未初始化
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else {
            printf("Traverse successfully!\n");
            return;
        }
    } else if (op == 13) { // 保存链表到对应文件
        printf("Input the filename: ");
        char filename[105]; // 文件名
        scanf("%s", filename);
        int res = SaveList(g_list[now], filename); // 函数返回结果
        if (res == -1) {
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else {
            printf("The list has been saved to %s successfully!\n", filename);
            return;
        }
    } else if (op == 14) { // 从对应文件加载链表
        printf("Input the filename: ");
        char filename[105]; // 文件名
        scanf("%s", filename);
        int res = LoadList(g_list[now], filename); // 函数返回结果
        if (res == -1) { // 链表未初始化
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else {
            printf("The list has been load from %s successfully!\n", filename);
            return;
        }
    } else if (op == 15) { // 排序列表
        int res = sortList(g_list[now]);
        if (res == -1) { // 链表未初始化
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else {
            printf("The list has been sorted successfully!\n");
            return;
        }
    } else if (op == 16) { // 翻转链表
        int res = reverseList(g_list[now]); // 函数返回结果
        if (res == -1) { // 链表未初始化
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else {
            printf("The list has been reversed successfully!\n");
            return;
        }
    } else if (op == 17) { // 删除倒数第n个元素
        printf("Input the position: ");
        int n; // 位置
        scanf("%d", &n);
        int res = RemoveNthFromEnd(g_list[now], n); // 函数返回结果
        if (res == -1) { // 链表未初始化
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else if (res == 0) { // 下标越界
            printf("Position out of range!\n");
            return;
        } else {
            printf("The %d-th(from end) has been deleted successfully!\n", n);
            return;
        }
    } else if (op == 18) { // 创建文件
        printf("Input the filename: ");
        char filename[105];
        scanf("%s", filename);
        CreateFile(filename);
        printf("File created successfully!\n");
        return;
    } else if (op == 19) { // 切换多表
        printf("Input the name: ");
        char name[105]; // 名字
        scanf("%s", name);
        int res = ListShift(g_list, now, name, num_list); // 函数返回结果
        if (!res) {
            printf("Can't find the List!\n");
            return;
        } else {
            printf("Shifted successfully!\n");
            return;
        }
    } else if (op == 20) { // 连续插入元素
        printf("Input the number of elements that you are going to insert: ");
        int n;
        scanf("%d", &n);
        int res = ConsecutiveInsert(g_list[now], n); // 函数返回结果
        if (res) {
            printf("Insertion complete!\n");
        }
        return;
    } else if (op == 21) { // 显示当前链表姓名
        printf("List name: %s\n", g_list[now]->name);
        return;
    }
}

int main() {
    init();
    while (1) {
        run();
        system("pause");
    }
    return 0;
}