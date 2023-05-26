//1
int hs[105];//用来检查关键字是否重复的数组 
int p=-1;//模拟输入输出流,static只能用一次,下次就没用了 
bool check(BiTree &T) {
    if (!T) return 1;
    if (hs[T->data.key]) return 0;
    hs[T->data.key] = 1;
    auto L = check(T->lchild);
    auto R = check(T->rchild);
    return (L && R);
}
void build(BiTree &T,TElemType definition[])
{
    p++;
    if(definition[p].key!=-1)
    {
        if(definition[p].key==0)return;
        T=(BiTree)malloc(sizeof(BiTNode));
        T->data=definition[p];
        T->lchild=NULL;
        T->rchild=NULL;
        build(T->lchild,definition);
        build(T->rchild,definition);
    }
}
status CreateBiTree(BiTree g_list[],int &num_list,BiTree &T,TElemType definition[],char name[])
/*根据带空枝的二叉树先根遍历序列definition构造一棵二叉树，将根节点指针赋值给T并返回OK，
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
    //首先是检查名字是否有重复
	p=-1;
	for(int i=0;i<num_list;i++)
	{
		if(!g_list[i])continue;//本来是不用判空的,但后面有销毁二叉树的操作 
		if(strcmp(name,g_list[i]->name)==0)return ERROR; 
	}
	//这里就不考虑前序序列输入错误的情况了,太麻烦了 
	T=(BiTree)malloc(sizeof(BiTNode));//我又忘记开辟内存了 
	T->lchild=NULL;
	T->rchild=NULL;
    build(T->lchild,definition);//我把真正的根节点放在了头结点的左儿子 
    
    if(!T)return OK;//说明创建了一个空树 
    
    memset(hs,0,sizeof(hs));
    int res=check(T->lchild);
    if(!res)
    {
    	//关键字重复了的话,这个就不要注册了,先把它还原到NULL的状态 
    	free(T); 
    	T=NULL;
    	return ERROR;
	}
    
    //下面是注册成功的处理了 
    strcpy(T->name,name);
    num_list++;
	return OK; 
    /********** End **********/
}
//2
BiTree root=NULL;
status DestroyBiTree(BiTree &T)
{
	if(!root)root=T;
	if(!root)return -1;
	if(!T)return OK;
	DestroyBiTree(T->lchild);
	DestroyBiTree(T->rchild);
	free(T);
	T=NULL;
	return OK;
	
}
//3
status ClearBiTree(BiTree &T)
//将二叉树设置为空,并删除所有结点,释放结点空间 
{
    /********** Begin *********/
    if (!T) return OK;
    ClearBiTree(T->rchild);
    ClearBiTree(T->lchild);
    free(T);
    T=NULL;
    return OK;

    /********** End **********/
}
//4
int IsEmpty(BiTree T)
//判断二叉树是否为空 
{
	if(!T)return 1;
	return 0;
}
//5
int BiTreeDepth(BiTree T)
//求二叉树的深度 
{
    // ????????,??????
    /********** Begin *********/
    if (T == NULL) return 0;
    int len_l = BiTreeDepth(T->lchild);
    int len_r = BiTreeDepth(T->rchild);
    if (len_l > len_r) return len_l + 1;
    return len_r + 1;
    
    /********** End **********/
}
//6
BiTNode* LocateNode(BiTree T,KeyType e)
//查找结点 
{
    // ????????,??????
    /********** Begin *********/

    if (!T) return NULL;

    if (T->data.key == e) {
        return T;
    }
	BiTNode *L,*R;
    L = LocateNode(T->lchild, e);
    R = LocateNode(T->rchild, e);

    if (L) return L;
    else return R;

    /********** End **********/
}
//7
int find_key(BiTree &T, int &key) {
    if (!T) return 0;

    if (T->data.key == key) {
        return 1;
    }
    
    int L = find_key(T->lchild, key);
    int R = find_key(T->rchild, key);

    return (L || R);
}

status Assign(BiTree &T,KeyType e,TElemType value)
//结点赋值 
{
    // ????????,??????
    /********** Begin *********/

    if (!T) return ERROR;

    if (find_key(T, value.key) && value.key != e) {
        return ERROR;
    }

    if (T->data.key == e) {
        T->data = value;
        return OK;
    }
	
    int L = Assign(T->lchild, e, value);
    int R = Assign(T->rchild, e, value);

    return (L || R);

    /********** End **********/
}
//8
BiTNode* GetSibling(BiTree T,KeyType e)
//获取兄弟结点 
{
    // ????????,??????
    /********** Begin *********/

    if (!T) return NULL;

    if (T->lchild) {
        if (T->lchild->data.key == e) {
            return T->rchild;
        }
    }

    if (T->rchild) {
        if (T->rchild->data.key == e) {
            return T->lchild;
        }
    }

	BiTNode *L,*R;
    L = GetSibling(T->lchild, e);
    R = GetSibling(T->rchild, e);

    if (L) return L;
    if (R) return R;

    return NULL;

    /********** End **********/
}
//9
bool insert(BiTree &T, KeyType e, int LR, TElemType c) {
    if (!T) return 0;
    if (LR == -1) {
    	BiTree new_node;
        new_node = (BiTree)malloc(sizeof(BiTNode));
        new_node->data = c;
        new_node->lchild=NULL;
        new_node->rchild=NULL;
        new_node->rchild = T;
        T = new_node;
        return 1;
    }
    if (T->data.key == e) {
    	BiTree new_node;
        new_node = (BiTree)malloc(sizeof(BiTNode));
        new_node->lchild=NULL;
        new_node->rchild=NULL;
        new_node->data = c;
        if (LR == 0) { // 左子树 
            new_node->rchild = T->lchild;
            T->lchild = new_node;
            return 1;
        } else if (LR == 1) { // 右子树 
            new_node->rchild = T->rchild;
            T->rchild = new_node;
            return 1;
        }
    }
    bool L = insert(T->lchild, e, LR, c);
    bool R = insert(T->rchild, e, LR, c);
    return (L || R);
}

//int hs[1000];
//bool check(BiTree &T) {
//    if (!T) return 1;
//    if (hs[T->data.key]) return 0;
//    hs[T->data.key] = 1;
//    auto L = check(T->lchild);
//    auto R = check(T->rchild);
//    return (L && R);
//}
status InsertNode(BiTree &T,KeyType e,int LR,TElemType c)
//插入结点 
{
    // ????????,??????
    /********** Begin *********/
    if (!insert(T, e, LR, c)) return 0;
    memset(hs,0,sizeof(hs)); 
    if (check(T)) return OK;
    return ERROR;
    /********** End **********/
}
//10
void insertAtRight(BiTree &T,BiTree Node)
{
    if(T->rchild==NULL)
    {
        T->rchild=Node;
        return;
    }
    insertAtRight(T->rchild,Node);
}
status DeleteNode(BiTree &T,KeyType e)
//删除结点 
{
    // ????????,??????
    /********** Begin *********/
    if(!T)return ERROR;
    if(T->data.key==e)
    {
        if(T->lchild)
        {
            if(T->rchild)
            {
                insertAtRight(T->lchild,T->rchild);
            }
            BiTNode *le;
            le=T->lchild;
            free(T);
            T=NULL;
            T=(BiTree)malloc(sizeof(BiTNode));
            T=le;
            return OK;
        }
        if(T->rchild)
        {
        	BiTNode *ri;
            ri=T->rchild;
            free(T);
            T=NULL;
            T=(BiTree)malloc(sizeof(BiTNode));
            T=ri;
            return OK;
        }
        free(T);
        T=NULL;
        return OK;
    }
    int L=DeleteNode(T->lchild,e);
    int R=DeleteNode(T->rchild,e);
    return (L||R);
    /********** End **********/
}
//11
void visit(BiTree T)//前序中序后序遍历都会用到这个 
{
	printf("%d,%s ",T->data.key,T->data.others);
}
status PreOrderTraverse(BiTree T)
//先序遍历二叉树T 
{
    // ????????,??????
    /********** Begin *********/
    if (T) visit(T);
    if (!T) return OK;
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
    return OK;

    /********** End **********/
}
//12
status InOrderTraverse(BiTree T)
//中序遍历二叉树 
{
    // ????????,??????
    /********** Begin *********/
    if(!T)return OK;
    if (T->lchild) InOrderTraverse(T->lchild);
    if (T) visit(T);
    if (T->rchild) InOrderTraverse(T->rchild);
    return OK;

    /********** End **********/
}
//13
status PostOrderTraverse(BiTree T)
//后序遍历二叉树 
{
    // ????????,??????
    /********** Begin *********/
	if(!T)return OK;
    if (T->lchild) PostOrderTraverse(T->lchild);
    if (T->rchild) PostOrderTraverse(T->rchild);
    if (T) visit(T);
    return OK;

    /********** End **********/
}
//14
BiTree que[105];//模拟队列 

status LevelOrderTraverse(BiTree T)
//按层遍历二叉树 
{
    // ????????,??????
    /********** Begin *********/
    if(!T)return OK;
    memset(que,0,sizeof(que));
    int front=1,size=0;
    que[++size]=T;
    while(front<=size)
    {
    	BiTree u;
        u=que[front];
        visit(u);
        front++; 
        if(u->lchild)
        {
            que[++size]=u->lchild;
        }
        if(u->rchild)
        {
            que[++size]=u->rchild;
        }
    }
    return OK;

    /********** End **********/
}
//15
int MaxPath(BiTree T)
{
	if(!T)return 0;
	if(MaxPath(T->lchild)>=MaxPath(T->rchild))return T->data.key+MaxPath(T->lchild);
	return T->data.key+MaxPath(T->rchild);
}
//16
BiTree LCA(BiTree &T,BiTree u,BiTree v)
{
	if(T==u||T==v||!T)return T;
	BiTree le=LCA(T->lchild,u,v);
	BiTree ri=LCA(T->rchild,u,v);
	if(le&&ri)return T;
	else if(le)return le;
	else return ri;
}
//17
BiTree invertTree(BiTree T)
{
	if(!T)return NULL;
	T->lchild=invertTree(T->lchild);
	T->rchild=invertTree(T->rchild);
	BiTree temp;
	temp=T->lchild;
	T->lchild=T->rchild;
	T->rchild=temp;
	return T;
}
//19
status SaveBiTree(BiTree T, char FileName[])
//保存二叉树 
{
    /********** Begin 1 *********/
    FILE *fp=fopen(FileName,"w");
    BiTree stk[105];
    int top=0;
    BiTree p;
    p=T;
    while(p)
    {
        fprintf(fp,"%d %s ",p->data.key,p->data.others);
        stk[++top]=p;
        p=p->lchild;
    }
    fprintf(fp,"0 null ");
    while(top)
    {
        BiTree ri;
        ri=stk[top]->rchild;
        top--;
        while(ri)
        {
            fprintf(fp,"%d %s ",ri->data.key,ri->data.others);
            stk[++top]=ri;
            ri=ri->lchild;
        }
        fprintf(fp,"0 null ");
    }
    fprintf(fp,"-1 -1");
    fclose(fp);
    return OK;
    /********** End 1 **********/
}
//20
status LoadBiTree(BiTree &T,  char FileName[])
//加载二叉树 
{
    // ????????,??????
    /********** Begin 2 *********/
    FILE *fp=fopen(FileName,"r");
    p=-1;
    int key;
    char others[20];
    TElemType definition[105];
    free(T);
    T=NULL;
    for(int i=0;;i++)
    {
        fscanf(fp,"%d%s",&key,others);
        definition[i].key=key;
        strcpy(definition[i].others,others);
        if(key==-1)break;
    }
    build(T,definition);
    fclose(fp);
    return OK;
    /********** End 2 **********/
}
//21
status ListSwitch(BiTree g_list[],int num_list,char name[],int &now)
{
	for(int i=0;i<num_list;i++)
	{
		if(!g_list[i])continue;
		if(strcmp(g_list[i]->name,name)==0)
		{
			now=i;
			return OK;
		}
	}
	return ERROR;
}
