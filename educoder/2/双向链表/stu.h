void  adjust(DuLinkList  L)
{
/**********Begin**********/
    DuLinkList head, tail;
    DuLinkList cur = L;
    head = tail = (DuLinkList)malloc(sizeof(struct Dnode)); // 头和尾关联
    cur = cur->next;
    while (cur != L) {
        DuLinkList p = (DuLinkList)malloc(sizeof(struct Dnode));
        p->data = cur->data;
        tail->next = p;
        p->prior = tail;
        tail = p;
        cur = cur->next;
        if (cur == L) {
            cur = cur->prior;
            break;
        }
        cur = cur->next;
    }
    cur = cur->prior;
    while (cur != L) {
        DuLinkList p = (DuLinkList)malloc(sizeof(struct Dnode));
        p->data = cur->data;
        tail->next = p;
        p->prior = tail;
        tail = p;
        cur = cur->prior;
        if (cur == L) break;
        cur = cur->prior;
    }
    head->prior = tail;
    tail->next = head;
    DuLinkList p = head;
    p = p->next;
    cur = cur->next;
    while (p != head) {
        cur->data = p->data;
        cur = cur->next;
        p = p->next;
    }
 /**********End**********/
}
