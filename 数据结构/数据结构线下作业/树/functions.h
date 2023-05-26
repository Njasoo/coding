//1
int hs[105];//�������ؼ����Ƿ��ظ������� 
int p=-1;//ģ�����������,staticֻ����һ��,�´ξ�û���� 
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
/*���ݴ���֦�Ķ������ȸ���������definition����һ�ö������������ڵ�ָ�븳ֵ��T������OK��
�������ͬ�Ĺؼ��֣�����ERROR����������ͨ������������������ʵ�ֱ�������*/
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    //�����Ǽ�������Ƿ����ظ�
	p=-1;
	for(int i=0;i<num_list;i++)
	{
		if(!g_list[i])continue;//�����ǲ����пյ�,�����������ٶ������Ĳ��� 
		if(strcmp(name,g_list[i]->name)==0)return ERROR; 
	}
	//����Ͳ�����ǰ�������������������,̫�鷳�� 
	T=(BiTree)malloc(sizeof(BiTNode));//�������ǿ����ڴ��� 
	T->lchild=NULL;
	T->rchild=NULL;
    build(T->lchild,definition);//�Ұ������ĸ��ڵ������ͷ��������� 
    
    if(!T)return OK;//˵��������һ������ 
    
    memset(hs,0,sizeof(hs));
    int res=check(T->lchild);
    if(!res)
    {
    	//�ؼ����ظ��˵Ļ�,����Ͳ�Ҫע����,�Ȱ�����ԭ��NULL��״̬ 
    	free(T); 
    	T=NULL;
    	return ERROR;
	}
    
    //������ע��ɹ��Ĵ����� 
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
//������������Ϊ��,��ɾ�����н��,�ͷŽ��ռ� 
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
//�ж϶������Ƿ�Ϊ�� 
{
	if(!T)return 1;
	return 0;
}
//5
int BiTreeDepth(BiTree T)
//������������ 
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
//���ҽ�� 
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
//��㸳ֵ 
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
//��ȡ�ֵܽ�� 
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
        if (LR == 0) { // ������ 
            new_node->rchild = T->lchild;
            T->lchild = new_node;
            return 1;
        } else if (LR == 1) { // ������ 
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
//������ 
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
//ɾ����� 
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
void visit(BiTree T)//ǰ�����������������õ���� 
{
	printf("%d,%s ",T->data.key,T->data.others);
}
status PreOrderTraverse(BiTree T)
//�������������T 
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
//������������� 
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
//������������� 
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
BiTree que[105];//ģ����� 

status LevelOrderTraverse(BiTree T)
//������������� 
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
//��������� 
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
//���ض����� 
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
