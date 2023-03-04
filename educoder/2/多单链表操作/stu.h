void TriLinkList(LinkList  A,LinkList  B,LinkList  C)
{
/**********Begin**********/
    LinkList cur = A;
    cur = cur->next;
    int inb[10005] = {0}, inc[10005] = {0};
    while (B != NULL) {
        inb[B->data] = 1;
        B = B->next;
    }
    while (C != NULL) {
        inc[C->data] = 1;
        C = C->next;
    }
    // 思路：取代下一个结点
    // 把下一个结点的值复制到当前结点，然后将下一个结点删除
    while (cur) {
        if (inb[cur->data] && inc[cur->data]) {
            LinkList nex = cur->next;
            cur->data = nex->data;
            cur->next = nex->next;
            free(nex);
            continue;
        }
        cur = cur->next;
    }
 /**********End**********/
}