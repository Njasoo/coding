status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem) {
        i--;
        if (i < 0 || i > L.length) {
            return ERROR;
        }
        L.length++;
        if (L.listsize < L.length) L.listsize++;
        for (int j = L.length - 1; j >= i + 1; j--) {
            L.elem[j] = L.elem[j - 1];
        }
        L.elem[i] = e;
        return OK;
    }
    return INFEASIBLE;

    /********** End **********/
}
