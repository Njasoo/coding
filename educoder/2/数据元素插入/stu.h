int insert(SqList &L,ElemType x)
{
/**********begin**********/
    int n = L.length;
    int l = 0, r = n - 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (L.elem[mid] <= x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    for (int i = n + 1; i > l; i--) {
        L.elem[i] = L.elem[i - 1];
    }
    L.length++;
    L.listsize = L.length;
    L.elem[l] = x;
    return l;
/**********end**********/
}
