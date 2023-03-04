void  TriSqList(SqList  &A,SqList  B,SqList  C)
{
/**********Begin**********/
    bool inb[10005], inc[10005];
    for (int i = 0; i < B.length; i++) {
        inb[B.elem[i]] = 1;
    }
    for (int i = 0; i < C.length; i++) {
        inc[C.elem[i]] = 1;
    }
    for (int i = 0; i < A.length; i++) {
        if (inb[A.elem[i]] && inc[A.elem[i]]) {
            A.length--;
            for (int j = i; j < A.length; j++) {
                A.elem[j] = A.elem[j + 1];
            }
            i--;
        }
    }
    A.listsize = A.length;
 /**********End**********/
}