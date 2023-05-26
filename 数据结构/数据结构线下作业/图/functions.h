void visit(VertexType v)//多次利用的函数 
{
	printf(" %d %s",v.key,v.others);
}
status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2])
//构造图 
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
/*销毁图*/
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
//查找顶点 
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
//寻找第一邻接点 
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
//v对应G的一个顶点,w对应v的邻接节点,操作结果是返回v的(相对于w)下一个邻接顶点的位序,如果w是最后一个邻接顶点,或w,v对应顶点不存在,则返回-1 
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
//插入顶点 
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
//删除顶点 
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
    //删除顶点之后,其他大于vex的结点的位序都要-1 
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
//插入弧 
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

    //检查一下<v,w>或者<w,v>是否已经存在 
    auto p=G.vertices[posv].firstarc;
    while(p)
    {
        if(p->adjvex==posw)return ERROR;
        p=p->nextarc;
    }
    //我都不知道评测集是不是都是无向图,我只能两边都检查一下确保安全 
    p=G.vertices[posw].firstarc;
    while(p)
    {
        if(p->adjvex==posv)return ERROR;
        p=p->nextarc;
    }
    //我都不知道评测集是不是都是无向图,我只能两边都检查一下确保安全 
    auto p1=(ArcNode*)malloc(sizeof(ArcNode));
    p1->adjvex=posw;//不要插入key,要插入位序 
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
//删除弧 
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

    //检查弧<v,w>是否存在 
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
    
    //检查<w,v>是否存在 
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

    ////删除<v,w>
    //找w的位置 
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
    //如果要删除的是第一个结点 
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

    ////删除<w,v>
    //找v的位置 
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
    //删除v
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
//深度优先搜索 
{
    // ????????,??????
    /********** Begin *********/
    if(G.vexnum==0)return ERROR;//空图不遍历 
    int vis[105]={0};//记录是否遍历过 
    int now=0;//记录现在所在结点的位序 
    ArcNode *p;
    while(1)
    {
        p=G.vertices[now].firstarc;
        bool finded=0;//记录一下这一轮有没有找到下一个可以遍历的结点 
        vis[now]=1;//标记当前结点 
        visit(G.vertices[now].data);
        while(p)
        {
            if(vis[p->adjvex])
            {
                p=p->nextarc;
                continue;//记得加 
            }
            now=p->adjvex;//改变为接下来要遍历的结点 
            finded=1;//说明现在找到了下一个可以遍历的结点 
            break;
        }
        if(!finded)//因为未必是连通图,所以继续遍历整个头结点顺序表,看看有没有顶点未被遍历过,然后就可以把下一个连通块完全遍历 
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
//广度优先搜索 
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
        if(front>top)//队空时继续找 
        {
            for(int i=0;i<G.vexnum;i++)
            {
                if(vis[i])continue;
                vis[i]=1;
                visit(G.vertices[i].data);
                q[++top]=i;
                break;//找到一个继续就行 
            }
        }
    }

    /********** End **********/
}
//13
void VerticesSetLessThanK(ALGraph &G,int v,int k)//距离小于k的顶点集合 
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
	printf("关键字: %d,离%d的距离为: %d\n",G.vertices[v].data.key,G.vertices[v].data.key,ans[v]);
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
				printf("关键字: %d,离%d的距离为: %d\n",G.vertices[p->adjvex].data.key,G.vertices[v].data.key,ans[p->adjvex]); 
				res++;
			}

		}
	}
	printf("总共有%d个顶点距离%d的距离小于%d\n",res,G.vertices[v].data.key,k); 
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
	if(G.vexnum==0)return 0;//空图不遍历 
    int vis[105]={0};//记录是否遍历过 
    int now=0;//记录现在所在结点的位序 
    ArcNode *p;
    int res=0;
    while(1)
    {
        p=G.vertices[now].firstarc;
        bool finded=0;//记录一下这一轮有没有找到下一个可以遍历的结点 
        vis[now]=1;//标记当前结点 
//        visit(G.vertices[now].data);
        while(p)
        {
            if(vis[p->adjvex])
            {
                p=p->nextarc;
                continue;//记得加 
            }
            now=p->adjvex;//改变为接下来要遍历的结点 
            finded=1;//说明现在找到了下一个可以遍历的结点 
            break;
        }
        if(!finded)//因为未必是连通图,所以继续遍历整个头结点顺序表,看看有没有顶点未被遍历过,然后就可以把下一个连通块完全遍历 
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
//保存图 
{
    // ????????,??????
    /********** Begin 1 *********/
    FILE *fp=fopen(FileName,"w");
    int hash[25][25]={0};
    //先把vertex的资料写进去 
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
//加载图 
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
    for(int i=0;i<G.vexnum;i++)//记得,很重要的步骤 
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
