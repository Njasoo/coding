status DFSTraverse(ALGraph &G,void (*visit)(VertexType))
//对图G进行深度优先搜索遍历，依次对图中的每一个顶点使用函数visit访问一次，且仅访问一次
{
    // 请在这里补充代码，完成本关任务
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
        if(!finded)//因为未必是连通图，所以继续遍历整个头结点顺序表，看看有没有顶点未被遍历过，然后就可以把下一个连通块遍历完全
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