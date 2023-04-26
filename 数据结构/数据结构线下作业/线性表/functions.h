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
        if (i - 1 >= L.length || i - 1 < 0) return ERROR;
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
//8
status PriorElem(SqList L,ElemType e,ElemType &pre)
// 如果线性表L存在，获取线性表L中元素e的前驱，保存在pre中，返回OK；如果没有前驱，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem) {
        for (int i = 0; i < L.length; i++) {
            if (L.elem[i] == e) {
                if (!i) return ERROR;
                pre = L.elem[i - 1];
                return OK;
            }
        }
        return ERROR;
    }
    return INFEASIBLE;

    /********** End **********/
}
//9
status NextElem(SqList L,ElemType e,ElemType &next)
// 如果线性表L存在，获取线性表L元素e的后继，保存在next中，返回OK；如果没有后继，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem) {
        for (int i = 0; i < L.length; i++) {
            if (L.elem[i] == e) {
                if (i == L.length - 1) return ERROR;
                next = L.elem[i + 1];
                return OK;
            }
        }
        return ERROR;
    }
    return INFEASIBLE;

    /********** End **********/
}
//10
status ListInsert(SqList &L,int i,ElemType e)
// 如果线性表L存在，将元素e插入到线性表L的第i个元素之前，返回OK；当插入位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem) {
        i--;
        if (i < 0 || i > L.length) return ERROR;
        L.length++;
        L.elem = (ElemType*)realloc(L.elem, L.length * sizeof(ElemType));
        for (int j = L.length - 1; j >= i + 1; j--) {
            L.elem[j] = L.elem[j - 1];
        }
        L.elem[i] = e;
        return OK;
    }
    return INFEASIBLE;

    /********** End **********/
}
//11
status ListDelete(SqList &L,int i,ElemType &e)
// 如果线性表L存在，删除线性表L的第i个元素，并保存在e中，返回OK；当删除位置不正确时，返回ERROR；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem) {
        i--;
        if (i < 0 || i >= L.length) return ERROR;
        L.length--;
        e = L.elem[i];
        for (int j = i; j < L.length; j++) {
            L.elem[j] = L.elem[j + 1];
        }
        return OK;
    }
    return INFEASIBLE;

    /********** End **********/
}
//12
status ListTraverse(SqList L)
// 如果线性表L存在，依次显示线性表中的元素，每个元素间空一格，返回OK；如果线性表L不存在，返回INFEASIBLE。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    if (L.elem) {
        if(L.length==0) return ERROR;
        for (int i = 0; i < L.length - 1; i++) {
            printf("%d ", L.elem[i]);
        }
        if (L.length) printf("%d\n", L.elem[L.length - 1]);
        return OK;
    }
    return INFEASIBLE;

    /********** End **********/
}
//16
int MaxSubArray(SqList L)
{
    if(!L.elem)return INFEASIBLE;
    if(!L.length)return ERROR;
    int ans=-1e9;
    int l=-1,r=-1;
    for(int i=0;i<L.length;i++)
    {
        int cnt=0;
        for(int j=i;j<L.length;j++)
        {
            cnt+=L.elem[j];
            if(cnt>ans)
            {
                ans=cnt;
                l=i;
                r=j;
            }
        }
    }
    cout<<"The max sum of subarray is ";
    for(int i=l;i<r;i++)
    {
        cout<<L.elem[i]<<" + ";
    }
    cout<<L.elem[r];
    cout<<" = "<<ans<<endl;
    return OK;
}
//17
int SubArrayNum(SqList &L)
{
    if(!L.elem)return INFEASIBLE;
    if(!L.length)return ERROR;
    int ans=-1e9;
    for(int i=0;i<L.length;i++)
    {
        int cnt=0;
        for(int j=i;j<L.length;j++)
        {
            cnt+=L.elem[j];
            ans=max(ans,cnt);
        }
    }
    int num=0;
    for(int i=0;i<L.length;i++)
    {
        int cnt=0;
        for(int j=i;j<L.length;j++)
        {
            cnt+=L.elem[j];
            if(cnt==ans)
            {
                num++;
                for(int k=i;k<j;k++)
                {
                    cout<<L.elem[k]<<" + ";
                }
                cout<<L.elem[j]<<" = "<<ans<<endl;
            }
        }
    }
    cout<<"There are total " <<num<<" sum of subarray equal to "<<ans<<endl;
    return OK;
}
//18
int sortList(SqList &L)
{
    if(!L.elem)return ERROR;
    for(int i=0;i<L.length;i++)
    {
        bool swaped=0;
        for(int j=0;j<L.length-1-i;j++)
        {
            if(L.elem[j]>L.elem[j+1])
            {
                swap(L.elem[j],L.elem[j+1]);
                swaped=1;
            }
        }
        if(!swaped)return OK;
    }
    return OK;
}
//19
int SaveList(SqList &L,char filename[])
{
    if(!L.elem)return INFEASIBLE;
    FILE *fp=fopen(filename,"w");
    if(fp==NULL)return ERROR;
    for(int i=0;i<L.length;i++)
    {
        fprintf(fp,"%d ",L.elem[i]);
    }
    fclose(fp);
    return OK;
}
//20
int LoadList(SqList &L,char filename[])
{
    if(!L.elem)return INFEASIBLE;
    FILE *fp=fopen(filename,"r");
    if(!fp)return ERROR;
    int x;
    L.length=0;
    while(!feof(fp))
    {
        fscanf(fp,"%d ",&x);
        L.elem[L.length++]=x;
    }
    fclose(fp);
    return OK;
}
//22
int findList(SqList *list,string name,int len)
{
    int res=-1;
    for(int i=1;i<=len;i++)
    {
        if(list[i].name==name)
        {
            res=i;
            break;
        }
    }
    if(res==-1)return ERROR;
    return res;
}