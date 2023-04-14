
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
