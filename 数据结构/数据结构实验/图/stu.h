status CreateCraph(ALGraph &G,VertexType V[],KeyType VR[][2])
/*根据V和VR构造图T并返回OK，如果V和VR不正确，返回ERROR
如果有相同的关键字，返回ERROR。此题允许通过增加其它函数辅助实现本关任务*/
{
    // 请在这里补充代码，完成本关任务
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
        auto p1=(ArcNode*)malloc(sizeof(ArcNode));
        auto p2=(ArcNode*)malloc(sizeof(ArcNode));
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
