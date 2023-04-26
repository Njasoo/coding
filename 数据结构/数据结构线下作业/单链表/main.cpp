#include "def.h"
#include "functions.h"

const int N = 105;
const int NUM_OP = 20;
int num_list, now = 1;
LinkList g_list[N];

void init() {
    for (int i = 0; i < N; i++) {
        g_list[i] = nullptr;
    }
}

void run() {
    system("cls");
    printf("-----------------------------------------------------------------\n");
    printf("\t1. InitList\t\t\t2. DestroyList\n");
    printf("\t3. ClearList\t\t\t4. ListEmpty\n");
    printf("\t5. ListLength\t\t\t6. GetElem\n");
    printf("\t7. LocateElem\t\t\t8. PriorElem\n");
    printf("\t9. NextElem\t\t\t10. ListInsert\n");
    printf("\t11. ListDelete\t\t\t12. ListTraverse\n");
    printf("\t13. SaveList\t\t\t14. LoadList\n");
    printf("\t15. sortList\t\t\t16. reverseList\n");
    printf("\t17. RemoveNthFromEnd\t\t18. Create File\n");
    printf("\t19. List Shift\t\t\t20. Create New List\n");
    printf("-----------------------------------------------------------------\n");
    printf("Please input number [1~%d] to operate the list: ", NUM_OP);
    int op;
    scanf("%d", &op);
    if (op < 1 || op > NUM_OP) {
        return (void)puts("Invalid input!");
    }
    if (op == 1) {
        if (num_list == 0) {
            printf("There is no list!\n");
            return;
        }
        int res = InitList(g_list[now]);
        if (res == -1) {
            printf("Invalid operation, the list has already been initialized!\n");
            return;
        } else {
            printf("Initialization completed!\n");
            printf("List id: %d\n", now);
            return;
        }
    } else if (op == 2) {
        if (num_list == 0) {
            printf("There is no list!\n");
            return;
        }
        int res = DestroyList(g_list[now]);
        // printf("res = %d\n", res);
        if (res == -1) {
            printf("Invalid operation, you can't destory an uninitialized list!\n");
            return;
        } else {
            printf("The list has been destroyed successfully!\n");
            return;
        }
    } else if (op == 3) {
        int res = ClearList(g_list[now]);
        if (res == -1) {
            printf("Invalid operation, you can't clear an uninitialized list!\n");
            return;
        } else {
            printf("The list has been cleared successfully!\n");
            return;
        }
    } else if (op == 4) {
        int res = ListEmpty(g_list[now]);
        if (res == -1) {
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else {
            if (res == 0) {
                printf("The list is not empty!\n");
            } else {
                printf("The list is empty!\n");
            }
            return;
        }
    } else if (op == 5) {
        int res = ListLength(g_list[now]);
        if (res == -1) {
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else {
            printf("The length of the list is %d.\n", res);
        }
    } else if (op == 6) {
        printf("Input the position: ");
        int pos;
        scanf("%d", &pos);
        int elem;
        int res = GetElem(g_list[now], pos, elem);
        if (res == -1) {
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else if (!res) {
            printf("Invalid position!\n");
            return;
        } else {
            printf("The %d-th element is %d\n", pos, elem);
        }
    } else if (op == 7) {
        printf("Input the element that you want to search!\n");
        int elem;
        scanf("%d", &elem);
        int res = LocateElem(g_list[now], elem);
        if (res == -1) {
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else if (!res) {
            printf("The element doesn't exist!\n");
            return;
        } else {
            printf("Element(%d) is at %d-th position.\n", elem, res);
            return;
        }
    } else if (op == 8) {
        printf("Input the element: ");
        int elem;
        scanf("%d", &elem);
        int pre;
        int res = PriorElem(g_list[now], elem, pre);
        if (res == -1) {
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else if (!res) {
            printf("Element doesn't exist!\n");
            return;
        } else {
            printf("The prior of %d is %d.\n", elem, pre);
        }
    } else if (op == 9) {
        printf("Input the element: ");
        int elem;
        scanf("%d", &elem);
        int nex;
        int res = NextElem(g_list[now], elem, nex);
        if (res == -1) {
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else if (!res) {
            printf("Element doesn't exist!\n");
            return;
        } else {
            printf("The next elem of %d is %d.\n", elem, nex);
        }
    } else if (op == 10) {
        printf("Input the position(start from 1): ");
        int pos;
        scanf("%d", &pos);
        printf("Input the element that you want to insert: ");
        int elem;
        scanf("%d", &elem);
        int res = ListInsert(g_list[now], pos, elem);
        if (res == -1) {
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else if (res == 0) {
            printf("Position out of range!\n");
            return;
        } else {
            printf("Element has been inserted to the list successfully!\n");
            return;
        }
    } else if (op == 11) {
        printf("Input the positionf(start from 1): ");
        int pos;
        scanf("%d", &pos);
        int elem;
        int res = ListDelete(g_list[now], pos, elem);
        if (res == -1) {
            printf("Invalid operation, you can't operate an uninitialized list!\n");
            return;
        } else if (!res) {
            printf("Position out of range!\n");
            return;
        } else {
            printf("The %d-th element(%d) has been deleted successfully!\n", pos, elem);
            return;
        }
    } else if (op == 12) {
        int res = ListTraverse(g_list[now]);
        if (res == -1) {
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else {
            printf("Traverse successfully!\n");
            return;
        }
    } else if (op == 13) {
        printf("Input the filename: ");
        char filename[105];
        scanf("%s", filename);
        int res = SaveList(g_list[now], filename);
        if (res == -1) {
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else {
            printf("The list has been saved to %s successfully!\n", filename);
            return;
        }
    } else if (op == 14) {
        printf("Input the filename: ");
        char filename[105];
        scanf("%s", filename);
        int res = LoadList(g_list[now], filename);
        if (res == -1) {
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else {
            printf("The list has been load from %s successfully!\n", filename);
            return;
        }
    } else if (op == 15) {
        int res = sortList(g_list[now]);
        if (res == -1) {
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else {
            printf("The list has been sorted successfully!\n");
            return;
        }
    } else if (op == 16) {
        int res = reverseList(g_list[now]);
        if (res == -1) {
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else {
            printf("The list has been reversed successfully!\n");
            return;
        }
    } else if (op == 17) {
        printf("Input the position: ");
        int n;
        scanf("%d", &n);
        int res = RemoveNthFromEnd(g_list[now], n);
        if (res == -1) {
            printf("Invalid operation, the list is uninitialized!\n");
            return;
        } else if (res == 0) {
            printf("Position out of range!\n");
            return;
        } else {
            printf("The %d-th(from end) has been deleted successfully!\n", n);
            return;
        }
    } else if (op == 18) {
        printf("Input the filename: ");
        char filename[105];
        scanf("%s", filename);
        CreateFile(filename);
        printf("File created successfully!\n");
        return;
    } else if (op == 19) {
        printf("Input the position: ");
        int pos;
        scanf("%d", &pos);
        int res = ListShift(now, pos, num_list);
        if (!res) {
            printf("Position out of range!");
            return;
        } else {
            printf("Shifted successfully!\n");
            return;
        }
    } else if (op == 20) {
        num_list++;
        printf("A new list has been created!\n");
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