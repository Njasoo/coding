int p = -1, len;

void build(BiTree &T, TElemType definition[]) {
    p++;
    if (p > len) return;
    if (definition[p].key == 0 || definition[p].key == -1) return;
    T->data = definition[p];
    build(T->lchild, definition);
    build(T->rchild, definition);
}

BiTree root;

void pre(BiTree &T) {
    if (T) {
        printf("%d ", T->data.key);
    } else {
        return;
    }
    pre(T->lchild);
    pre(T->rchild);
}

status CreateBiTree(BiTree &T,TElemType definition[])
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    len = sizeof(definition) / sizeof(definition[0]);
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data.key = 114514;
    sprintf(root->data.others, "%s", definition[0]);
    build(root, definition);
    T = root;
    return OK;

    /********** End **********/
}
