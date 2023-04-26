// 1
status InitList(LinkList &L)
// 线性表L不存在，构造一个空的线性表，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == nullptr) {
        L = (LinkList)malloc(sizeof(LNode));
        L->next = NULL;
        return OK;
    } else {
        return INFEASIBLE;
    }

    /********** End **********/
}
// 2
status DestroyList(LinkList &L)
// 如果线性表L存在，销毁线性表L，释放数据元素的空间，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L == nullptr) {
        return INFEASIBLE;
    }
    while (L) {
        auto nex = L->next;
        free(L);
        L = nullptr;
        L = nex;
    }
    return OK;

    /********** End **********/
}
// 3

status ClearList(LinkList &L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L) return INFEASIBLE;
    auto p = L->next;
    while (p) {
        auto nex = p->next;
        free(p);
        p = nex;
    }
    L->next = nullptr;
    return OK;

    /********** End **********/
}
// 4
status ListEmpty(LinkList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L) return INFEASIBLE;
    if (L->next) return FALSE;
    return TRUE;

    /********** End **********/
}
// 5
int ListLength(LinkList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L) return INFEASIBLE;
    int res = 0;
    auto p = L->next;
    while (p) {
        res++;
        p = p->next;
    }
    return res;

    /********** End **********/
}
// 6
status GetElem(LinkList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L) return INFEASIBLE;
    int len = 0;
    auto p = L->next;
    while (p) {
        len++;
        p = p->next;
    }
    if (i < 1 || i > len) return ERROR;
    int now = 1;
    p = L->next;
    while (now < i) {
        p = p->next;
        now++;
    }
    e = p->data;
    return OK;

    /********** End **********/
}
// 7
status LocateElem(LinkList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号；如果e不存在，返回ERROR；当线性表L不存在时，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L) return INFEASIBLE;
    int now = 1;
    auto p = L->next;
    while (p) {
        if (p->data == e) return now;
        p = p->next;
        now++;
    }
    return ERROR;

    /********** End **********/
}
// 8
status PriorElem(LinkList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L) return INFEASIBLE;
    int e_pos = -1, now = 1;
    auto p = L->next;
    while (p) {
        if (p->data == e) {
            e_pos = now;
            break;
        }
        now++;
        p = p->next;
    }
    if (e_pos == -1 || e_pos == 1) return ERROR;
    p = L->next;
    now = 1;
    while (p) {
        if (now == e_pos - 1) {
            pre = p->data;
            break;
        }
        p = p->next;
        now++;
    }
    return OK;

    /********** End **********/
}
// 9
status NextElem(LinkList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L) return INFEASIBLE;
    int now = 1, e_pos = -1;
    auto p = L->next;
    int len = 0;
    while (p) {
        len++;
        p = p->next;
    }
    p = L->next;
    while (p) {
        if (p->data == e) {
            e_pos = now;
            break;
        }
        now++;
        p = p->next;
    }
    if (e_pos == len || e_pos == -1) return ERROR;
    p = L->next;
    now = 1;
    while (p) {
        if (now == e_pos + 1) {
            next = p->data;
            break;
        }
        now++;
        p = p->next;
    }
    return OK;

    /********** End **********/
}
// 10
status ListInsert(LinkList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L) return INFEASIBLE;
    int len = 0;
    auto p = L->next;
    while (p) {
        len++;
        p = p->next;
    }
    if (i <= 0 || i > len + 1) return ERROR;

    int now = 0;
    auto head = L;

    while (L) {
        if (now == i - 1) {
            auto new_node = (LinkList)malloc(sizeof(LNode));
            new_node->data = e;
            auto nex = L->next;
            L->next = new_node;
            new_node->next = nex;
            break;
        }
        now++;
        L = L->next;
    }
    L = head;
    return OK;

    /********** End **********/
}
// 11
status ListDelete(LinkList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L) return INFEASIBLE;

    int len = 0;
    auto p = L->next;

    while (p) {
        len++;
        p = p->next;
    }

    if (i <= 0 || i > len) return ERROR;

    int now = 0;
    auto head = L;
    while (L) {
        if (now == i - 1) {
            auto nex = L->next;
            L->next = L->next->next;
            e = nex->data;
            free(nex);
            break;
        }
        now++;
        L = L->next;
    }
    L = head;
    return OK;

    /********** End **********/
}
// 12
status ListTraverse(LinkList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L) return INFEASIBLE;
    auto head = L;
    L = L->next;
    while (L) {
        printf("%d ", L->data);
        L = L->next;
    }
    puts("");
    L = head;
    return OK;

    /********** End **********/
}
// 13
status SaveList(LinkList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    if (!L) return INFEASIBLE;

    FILE *fp = fopen(FileName, "w");
    auto p = L->next;

    while (p) {
        fprintf(fp, "%d ", p->data);
        p = p->next;
    }
    fclose(fp);
    return OK;

    /********** End 1 **********/
}
// 14
status LoadList(LinkList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    if (L) return INFEASIBLE;

    FILE *fp = fopen(FileName, "r");
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    auto head = L;
    while (fscanf(fp, "%d", &x) == 1) {
        if (x == 0) break;
        auto new_node = (LinkList)malloc(sizeof(LNode));
        new_node->data = x;
        L->next = new_node;
        L = L->next;
        L->next = nullptr;
    }
    L = head;
    fclose(fp);
    return OK;

    /********** End 2 **********/
}
// 15
status sortList(LinkList &L) {
    if (!L) return INFEASIBLE;
    int len = 0;
    auto p = L->next;
    while (p) {
        len++;
        p = p->next;
    }
    int i = 0;
    while (i < len) {
        int j = 0;
        p = L->next;
        while (j < len - 1 - i) {
            if (p->data > p->next->data) {
                int temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            j++;
            p = p->next;
        }
        i++;
    }
    return OK;
}
// 16
status reverseList(LinkList &L) {
    if (!L) return INFEASIBLE;
    LinkList cur = L->next; // 不是L
    LinkList pre = nullptr;
    while (cur) {
        LinkList nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
    }
    L->next = pre;
    return OK;
}
// 17
status RemoveNthFromEnd(LinkList &L, int n) {
    if (!L) return INFEASIBLE;
    int len = ListLength(L);
    if (n < 1 || n > len) return ERROR;

    // 删除尾结点的特例
    // 知道尾结点的前一个结点，然后把cur->next删掉
    if (n == 1) {
        LinkList cur = L;
        while (cur->next->next != nullptr) {
            cur = cur->next;
        }
        free(cur->next);
        cur->next = nullptr;
        return OK;
    }
    LinkList cur = L->next;
    int now = 1;
    int goal = len - n + 1;
    while (cur) {
        if (now == goal) {
            // 将下一个结点赋值给自己，然后把下一个结点删掉
            LinkList nex = cur->next;
            *cur = *(cur->next);
            free(nex);
            nex = nullptr;
            break;
        }
        now++;
        cur = cur->next;
    }
    return OK;
}
// 18
void CreateFile(char filename[]) {
    char temp[] = "type NUL> ";
    const char *command = strcat(temp, filename);
    system(command);
}
// 19
status ListShift(int &now, int i, int num_list) {
    if (i < 1 || i > num_list) return ERROR;
    now = i;
    return OK;
}