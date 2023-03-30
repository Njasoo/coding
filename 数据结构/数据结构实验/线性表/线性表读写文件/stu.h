status  SaveList(SqList L,char FileName[])
// 如果线性表L存在，将线性表L的的元素写到FileName文件中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem) {
        FILE *fp = fopen(FileName, "w");
        for (int i = 0; i < L.length; i++) {
            fprintf(fp, "%d ", L.elem[i]);
        }
        return OK;
    }
    return INFEASIBLE;

    /********** End **********/
}
status  LoadList(SqList &L,char FileName[])
// 如果线性表L不存在，将FileName文件中的数据读入到线性表L中，返回OK，否则返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (!L.elem) {
        L.elem = (ElemType*) malloc(10 * sizeof(ElemType));
        FILE *rp = fopen(FileName, "r");
        ElemType x;
        L.length = 0;
        while (fscanf(rp, "%d", &x) == 1) {
            if (!x) break;
            L.elem[L.length++] = x;
        }
        return OK;
    }
    return INFEASIBLE;

    /********** End **********/
}