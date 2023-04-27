#include <string.h>
status SaveBiTree(BiTree T, char FileName[])
//将二叉树的结点数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    static FILE *fp = fopen(FileName, "w");
    if (!T) {
        fprintf(fp, "0 ");
        return OK;
    }
    static int idx = 0;
    int now = idx++;
    fprintf(fp, "%d %s ", T->data.key, T->data.others);
    SaveBiTree(T->lchild, FileName);
    SaveBiTree(T->rchild, FileName);
    if (now == 0) {
        fclose(fp);
    }
    return OK;
    /********** End 1 **********/
}
status LoadBiTree(BiTree &T,  char FileName[])
//读入文件FileName的结点数据，创建二叉树
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
    static FILE *fp = fopen(FileName, "r");
    int key;
    char others[20];
    int res = fscanf(fp, "%d", &key);
    if (!res) {
        fclose(fp);
        return OK;
    }
    if (!key) return OK;
    fscanf(fp, "%s", others);
    T = (BiTree)malloc(sizeof(BiTNode));
    T->lchild = nullptr;
    T->rchild = nullptr;
    T->data.key = key;
    strcpy(T->data.others, others);
    LoadBiTree(T->lchild, FileName);
    LoadBiTree(T->rchild, FileName);
    return OK;
    /********** End 2 **********/
}
