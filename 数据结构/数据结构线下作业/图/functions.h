void visit(VertexType v)//������õĺ��� 
{
	printf(" %d %s",v.key,v.others);
}
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2])
//����ͼ 
{
    // ????????,??????
    /********** Begin *********/
    int n=0,m=0;
    while(V[n].key!=-1)n++;
    if(n==0)return ERROR;
    while(VR[m][0]!=-1)m++;
    if(n>20)return ERROR;

    G.vexnum=n;
    G.arcnum=m;
    G.kind=UDG;

    for(int i=0;i<n;i++)
    {
        G.vertices[i].data=V[i];
        G.vertices[i].firstarc=NULL;
    }

    for(int i=0;i<m;i++)
    {
        int u=VR[i][0];
        int v=VR[i][1];
        bool finded=0;
        for(int j=0;j<n;j++)
        {
            if(V[j].key==u)
            {
                u=j;
                finded=1;
                break;
            }
        }
        if(!finded)return ERROR;
        finded=0;
        for(int j=0;j<n;j++)
        {
            if(V[j].key==v)
            {
                v=j;
                finded=1;
                break;
            }
        }
        if(!finded)return ERROR;
        ArcNode *p1,*p2;
        p1=(ArcNode*)malloc(sizeof(ArcNode));
        p2=(ArcNode*)malloc(sizeof(ArcNode));
        p1->adjvex=v;
        p2->adjvex=u;
        p1->nextarc=G.vertices[u].firstarc;
        p2->nextarc=G.vertices[v].firstarc;
        G.vertices[u].firstarc=p1;
        G.vertices[v].firstarc=p2;
    }
    return OK;
    /********** End **********/
}
//2
status DestroyGraph(ALGraph &G)
/*����ͼ*/
{
    // ????????,??????
    /********** Begin *********/
    for(int i=0;i<G.vexnum;i++)
    {
        auto p=G.vertices[i].firstarc;
        while(p)
        {
            auto nex=p->nextarc;
            free(p);
            p=NULL;
            p=nex;
        }
    }
    G.vexnum=G.arcnum=0;
    return OK;

    /********** End **********/
}
//3
int LocateVex(ALGraph G,KeyType u)
//���Ҷ��� 
{
    // ????????,??????
    /********** Begin *********/
    int res=-1;
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==u)
        {
            res=i;
            break;
        }
    }
    return res;

    /********** End **********/
}
//4
status PutVex(ALGraph &G,KeyType u,VertexType value)
//??u??G?????,????????????value,??OK;
//?????????????,??ERROR
{
    // ????????,??????
    /********** Begin *********/

    int cnt=0,pos=-1;
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==u)
        {
            cnt++;
            if(pos==-1)pos=i;
        }
    }
    if(cnt!=1)return ERROR;
    G.vertices[pos].data=value;
    for(int i=0;i<G.vexnum;i++)
    {
        for(int j=i+1;j<G.vexnum;j++)
        {
            if(G.vertices[i].data.key==G.vertices[j].data.key)
            {
                return ERROR;
            }
        }
    }
    return OK;

    /********** End **********/
}
//5
int FirstAdjVex(ALGraph G,KeyType u)
//Ѱ�ҵ�һ�ڽӵ� 
{
    // ????????,??????
    /********** Begin *********/
    int n=G.vexnum;
    for(int i=0;i<n;i++)
    {
        if(G.vertices[i].data.key==u)
        {
            return G.vertices[i].firstarc->adjvex;
        }
    }
    return -1;

    /********** End **********/
}
//6
int NextAdjVex(ALGraph G,KeyType v,KeyType w)
//v��ӦG��һ������,w��Ӧv���ڽӽڵ�,��������Ƿ���v��(�����w)��һ���ڽӶ����λ��,���w�����һ���ڽӶ���,��w,v��Ӧ���㲻����,�򷵻�-1 
{
    // ????????,??????
    /********** Begin *********/
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==v)
        {
            auto p=G.vertices[i].firstarc;
            while(p)
            {
                if(G.vertices[p->adjvex].data.key==w)
                {
                    if(p->nextarc)return p->nextarc->adjvex;
                    else return -1;
                }
                p=p->nextarc;
            }
        }
    }
    return -1;

    /********** End **********/
}
//7
status InsertVex(ALGraph &G,VertexType v)
//���붥�� 
{
    // ????????,??????
    /********** Begin *********/
    if(G.vexnum+1>20)return ERROR;
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==v.key)
        {
            return ERROR;
        }
    }
    G.vexnum++;
    G.vertices[G.vexnum-1].data=v;
    return OK;
    /********** End **********/
}
//8
status DeleteVex(ALGraph &G,KeyType v)
//ɾ������ 
{
    // ????????,??????
    /********** Begin *********/
    if(G.vexnum-1==0)return ERROR;
    int vex=-1;
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==v)
        {
            vex=i;
            auto p=G.vertices[i].firstarc;
            int len=0;
            while(p)
            {
                len++;
                auto nex=p->nextarc;
                free(p);
                p=nullptr;
                p=nex;
            }
            G.vexnum--;
            G.arcnum-=len;
            for(int j=i;j<G.vexnum;j++)
            {
                G.vertices[j]=G.vertices[j+1];
            }
            break;
        }
    }
    if(vex==-1)return ERROR;
    if(G.vexnum==0)return ERROR;
    //ɾ������֮��,��������vex�Ľ���λ��Ҫ-1 
    for(int i=0;i<G.vexnum;i++)
    {
        auto p=G.vertices[i].firstarc;
        int pos=-1;
        int now=1;
        while(p)
        {
            if(p->adjvex==vex)
            {
                pos=now;
                break;
            }
            p=p->nextarc;
            now++;
        }
        if(pos==-1)continue;
        p=G.vertices[i].firstarc;
        if(pos==1)
        {
            G.vertices[i].firstarc=G.vertices[i].firstarc->nextarc;
            free(p);
            p=nullptr;
        }
        else
        {
            now=1;
            while(p)
            {
                if(now==pos-1)
                {
                    auto nex=p->nextarc;
                    p->nextarc=p->nextarc->nextarc;
                    free(nex);
                    nex=nullptr;
                    break;
                }
                p=p->nextarc;
                now++;
            }
        }
    }
    for(int i=0;i<G.vexnum;i++)
    {
        auto p=G.vertices[i].firstarc;
        while(p)
        {
            if(p->adjvex>vex)
            {
                p->adjvex--;
            }
            p=p->nextarc;
        }
    }
    return OK;

    /********** End **********/
}
//9
status InsertArc(ALGraph &G,KeyType v,KeyType w)
//���뻡 
{
    // ????????,??????
    /********** Begin *********/
    int posv=-1,posw=-1;
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==v)posv=i;
        else if(G.vertices[i].data.key==w)posw=i;
    }
    if(posv==-1 || posw==-1)return ERROR;

    //���һ��<v,w>����<w,v>�Ƿ��Ѿ����� 
    auto p=G.vertices[posv].firstarc;
    while(p)
    {
        if(p->adjvex==posw)return ERROR;
        p=p->nextarc;
    }
    //�Ҷ���֪�����⼯�ǲ��Ƕ�������ͼ,��ֻ�����߶����һ��ȷ����ȫ 
    p=G.vertices[posw].firstarc;
    while(p)
    {
        if(p->adjvex==posv)return ERROR;
        p=p->nextarc;
    }
    //�Ҷ���֪�����⼯�ǲ��Ƕ�������ͼ,��ֻ�����߶����һ��ȷ����ȫ 
    auto p1=(ArcNode*)malloc(sizeof(ArcNode));
    p1->adjvex=posw;//��Ҫ����key,Ҫ����λ�� 
    p1->nextarc=G.vertices[posv].firstarc;
    G.vertices[posv].firstarc=p1;
    auto p2=(ArcNode*)malloc(sizeof(ArcNode));
    p2->adjvex=posv;
    p2->nextarc=G.vertices[posw].firstarc;
    G.vertices[posw].firstarc=p2;
    G.arcnum++;
    return OK;

    /********** End **********/
}
//10
status DeleteArc(ALGraph &G,KeyType v,KeyType w)
//ɾ���� 
{
    // ????????,??????
    /********** Begin *********/
    int posv=-1,posw=-1;
    for(int i=0;i<G.vexnum;i++)
    {
        if(G.vertices[i].data.key==v)posv=i;
        if(G.vertices[i].data.key==w)posw=i;
    }
    if(posv==-1||posw==-1)return ERROR;

    //��黡<v,w>�Ƿ���� 
    auto p=G.vertices[posv].firstarc;
    bool flag=0;
    while(p)
    {
        if(p->adjvex==posw)
        {
            flag=1;
            break;
        }
        p=p->nextarc;
    }
    if(!flag)return ERROR;
    
    //���<w,v>�Ƿ���� 
    p=G.vertices[posw].firstarc;
    flag=0;
    while(p)
    {
        if(p->adjvex==posv)
        {
            flag=1;
            break;
        }
        p=p->nextarc;
    }
    if(!flag)return ERROR;

    ////ɾ��<v,w>
    //��w��λ�� 
    p=G.vertices[posv].firstarc;
    int pos=-1;
    int now=1;
    while(p)
    {
        if(p->adjvex==posw)
        {
            pos=now;
            break;
        }       
        now++;
        p=p->nextarc;
    }
    p=G.vertices[posv].firstarc;
    //���Ҫɾ�����ǵ�һ����� 
    if(pos==1)
    {
        G.vertices[posv].firstarc=G.vertices[posv].firstarc->nextarc;
        free(p);
        p=NULL;
    }
    else
    {
        now=1;
        while(p)
        {
            if(now==pos-1)
            {
                auto nex=p->nextarc;
                p->nextarc=p->nextarc->nextarc;
                free(nex);
                nex=NULL;
                break;
            }
            now++;
        }
    }

    ////ɾ��<w,v>
    //��v��λ�� 
    pos=-1;
    p=G.vertices[posw].firstarc;
    now=1;
    while(p)
    {
        if(p->adjvex==posv)
        {
            pos=now;
            break;
        }
        now++;
        p=p->nextarc;
    }
    //ɾ��v
    if(pos==1)
    {
        G.vertices[posw].firstarc=G.vertices[posw].firstarc->nextarc;
        free(p);
        p=NULL;
    }
    else
    {
        p=G.vertices[posw].firstarc;
        now=1;
        while(p)
        {
            if(now==pos-1)
            {
                auto nex=p->nextarc;
                p->nextarc=p->nextarc->nextarc;
                free(nex);
                nex=NULL;
                break;
            }
            p=p->nextarc;
            now++;
        }
    }
    G.arcnum--;
    return OK;

    /********** End **********/
}
//11
status DFSTraverse(ALGraph &G)
//����������� 
{
    // ????????,??????
    /********** Begin *********/
    if(G.vexnum==0)return ERROR;//��ͼ������ 
    int vis[105]={0};//��¼�Ƿ������ 
    int now=0;//��¼�������ڽ���λ�� 
    ArcNode *p;
    while(1)
    {
        p=G.vertices[now].firstarc;
        bool finded=0;//��¼һ����һ����û���ҵ���һ�����Ա����Ľ�� 
        vis[now]=1;//��ǵ�ǰ��� 
        visit(G.vertices[now].data);
        while(p)
        {
            if(vis[p->adjvex])
            {
                p=p->nextarc;
                continue;//�ǵü� 
            }
            now=p->adjvex;//�ı�Ϊ������Ҫ�����Ľ�� 
            finded=1;//˵�������ҵ�����һ�����Ա����Ľ�� 
            break;
        }
        if(!finded)//��Ϊδ������ͨͼ,���Լ�����������ͷ���˳���,������û�ж���δ��������,Ȼ��Ϳ��԰���һ����ͨ����ȫ���� 
        {
            bool flag=0;
            for(int i=0;i<G.vexnum;i++)
            {
                if(!vis[i])
                {
                    flag=1;
                    now=i;
                    break;
                }
            }
            if(!flag)break;
        }
    }
    return OK;

    /********** End **********/
}
//12
status BFSTraverse(ALGraph &G)
//����������� 
{
    // ????????,??????
    /********** Begin *********/
    int q[1005];
    int front=1,top=0;
    q[++top]=0;
    int vis[1005]={0};
    vis[0]=1;
    visit(G.vertices[0].data);
    while(front<=top)
    {
        int u=q[front];
        front++;
        auto p=G.vertices[u].firstarc;
        while(p)
        {
            if(vis[p->adjvex])
            {
                p=p->nextarc;
                continue;
            }
            vis[p->adjvex]=1;
            visit(G.vertices[p->adjvex].data);
            q[++top]=p->adjvex;
            p=p->nextarc;
        }
        if(front>top)//�ӿ�ʱ������ 
        {
            for(int i=0;i<G.vexnum;i++)
            {
                if(vis[i])continue;
                vis[i]=1;
                visit(G.vertices[i].data);
                q[++top]=i;
                break;//�ҵ�һ���������� 
            }
        }
    }

    /********** End **********/
}
//13
void VerticesSetLessThanK(ALGraph &G,int v,int k)//����С��k�Ķ��㼯�� 
{
	int que[105];
	int top=0,front=1;
	que[++top]=v;
	int vis[105]={0};
	int ans[105];
	memset(ans,-1,sizeof(ans));
	int res=1;
	vis[v]=1;
	ans[v]=0;
	printf("�ؼ���: %d,��%d�ľ���Ϊ: %d\n",G.vertices[v].data.key,G.vertices[v].data.key,ans[v]);
	while(front<=top)
	{
		int u=que[front];
		int d=ans[u];
		front++;
		for(auto p=G.vertices[u].firstarc;p;p=p->nextarc)
		{
			if(vis[p->adjvex])continue;
			vis[p->adjvex]=1;
			que[++top]=p->adjvex;
			ans[p->adjvex]=ans[u]+1;
			if(ans[p->adjvex]<k)
			{
				printf("�ؼ���: %d,��%d�ľ���Ϊ: %d\n",G.vertices[p->adjvex].data.key,G.vertices[v].data.key,ans[p->adjvex]); 
				res++;
			}

		}
	}
	printf("�ܹ���%d���������%d�ľ���С��%d\n",res,G.vertices[v].data.key,k); 
}
//14
void MaxPath(ALGraph &G,int now,int v,int step,int path[],int vis[],int &ans,int r_ans[])
{
	for(auto p=G.vertices[now].firstarc;p;p=p->nextarc)
	{
		if(vis[p->adjvex])continue;
		vis[p->adjvex]=1;
		path[step]=G.vertices[p->adjvex].data.key;
		if(p->adjvex==v)
		{
//			printf("path:\n");
//			for(int i=0;i<=step;i++)
//			{
//				printf("%d ",path[i]);
//			}
//			puts("");
			if(step<ans)
			{
				ans=step;
				for(int i=0;i<=step;i++)
				{
					r_ans[i]=path[i];
				}
			}
//			continue;
		}
		MaxPath(G,p->adjvex,v,step+1,path,vis,ans,r_ans);
		vis[p->adjvex]=0;
	}
}
//15
int ConnectedComponentsNums(ALGraph &G)
{
	if(G.vexnum==0)return 0;//��ͼ������ 
    int vis[105]={0};//��¼�Ƿ������ 
    int now=0;//��¼�������ڽ���λ�� 
    ArcNode *p;
    int res=0;
    while(1)
    {
        p=G.vertices[now].firstarc;
        bool finded=0;//��¼һ����һ����û���ҵ���һ�����Ա����Ľ�� 
        vis[now]=1;//��ǵ�ǰ��� 
//        visit(G.vertices[now].data);
        while(p)
        {
            if(vis[p->adjvex])
            {
                p=p->nextarc;
                continue;//�ǵü� 
            }
            now=p->adjvex;//�ı�Ϊ������Ҫ�����Ľ�� 
            finded=1;//˵�������ҵ�����һ�����Ա����Ľ�� 
            break;
        }
        if(!finded)//��Ϊδ������ͨͼ,���Լ�����������ͷ���˳���,������û�ж���δ��������,Ȼ��Ϳ��԰���һ����ͨ����ȫ���� 
        {
            bool flag=0;
            for(int i=0;i<G.vexnum;i++)
            {
                if(!vis[i])
                {
                    flag=1;
                    now=i;
                    break;
                }
            }
            if(!flag)break;
            res++;
        }
    }
    return res;
}
//16
status SaveGraph(ALGraph G, char FileName[])
//����ͼ 
{
    // ????????,??????
    /********** Begin 1 *********/
    FILE *fp=fopen(FileName,"w");
    int hash[25][25]={0};
    //�Ȱ�vertex������д��ȥ 
    for(int i=0;i<G.vexnum;i++)
    {
        fprintf(fp,"%d %s\n",G.vertices[i].data.key,G.vertices[i].data.others);
    }
    fprintf(fp,"-1 nil\n");
    int temp[25]={0};
    for(int i=0;i<G.vexnum;i++)
    {
        auto p=G.vertices[i].firstarc;
        int len=0;
        while(p)
        {
            temp[len++]=p->adjvex;
            p=p->nextarc;
        }
        for(int j=len-1;j>=0;j--)
        {
            fprintf(fp,"%d %d\n",i,temp[j]);
        }
    }
    fprintf(fp,"-1 -1\n");
    fclose(fp);
    return OK;

    /********** End 1 **********/
}
//17
status LoadGraph(ALGraph &G, char FileName[])
//����ͼ 
{
    // ????????,??????
    /********** Begin 2 *********/
    DestroyGraph(G);
    FILE *fp=fopen(FileName,"r");
    int key;
    char others[20];
    for(int i=0;;i++)
    {
        fscanf(fp,"%d %s\n",&key,others);
        if(key==-1)
        {
            G.vexnum=i;
            break;
        }
        G.vertices[i].data.key=key;
        strcpy(G.vertices[i].data.others,others);
    }
    for(int i=0;i<G.vexnum;i++)//�ǵ�,����Ҫ�Ĳ��� 
    {
        G.vertices[i].firstarc=NULL;
    }

    for(int i=0;;i++)
    {
        int u,v;
        fscanf(fp,"%d %d\n",&u,&v);
        if(u==-1)
        {
            G.arcnum=i/2;
            break;
        }
        auto p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=v;
        p->nextarc=G.vertices[u].firstarc;
        G.vertices[u].firstarc=p;
    }
    // printf("G.vexnum=%d\n",G.vexnum);
    // printf("G.arcnum=%d\n",G.arcnum);
    fclose(fp);
    return OK;

    /********** End 2 **********/
}
