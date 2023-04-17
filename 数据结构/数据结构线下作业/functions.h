//1
status InitList(SqList& L)
{
    if (L.elem != NULL) return INFEASIBLE;
    L.elem = (ElemType*)malloc(sizeof(ElemType));
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}
//2
status DestroyList(SqList& L)
{
    if (L.elem) {
        free(L.elem);
        L.length=0;
        L.name="";
        L.elem = NULL;
        return OK;
    }
    return INFEASIBLE;
}
//3
status ClearList(SqList& L)
// 如果线性表L存在，删除线性表L中的所有元素，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem) {
        L.length = 0;
        return OK;
    }
    return INFEASIBLE;

    /********** End **********/
}
//4
status ListEmpty(SqList L)
// 如果线性表L存在，判断线性表L是否为空，空就返回TRUE，否则返回FALSE；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem) {
        return L.length ? FALSE : TRUE;
    }
    return INFEASIBLE;

    /********** End **********/
}
//5
status ListLength(SqList L)
// 如果线性表L存在，返回线性表L的长度，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem) return L.length;
    return INFEASIBLE;

    /********** End **********/
}
//6
status GetElem(SqList L,int i,ElemType &e)
// 如果线性表L存在，获取线性表L的第i个元素，保存在e中，返回OK；如果i不合法，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem) {
        if (i - 1 >= L.length || i - 1 <= 0) return ERROR;
        e = L.elem[i - 1];
        return OK;
    }
    return INFEASIBLE;

    /********** End **********/
}
//7
int LocateElem(SqList L,ElemType e)
// 如果线性表L存在，查找元素e在线性表L中的位置序号并返回该序号；如果e不存在，返回0；当线性表L不存在时，返回INFEASIBLE（即-1）。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem) {
        for (int i = 0; i < L.length; i++) {
            if (L.elem[i] == e) {
                return i + 1;
            }
        }
        return 0;
    }
    return INFEASIBLE;

    /********** End **********/
}