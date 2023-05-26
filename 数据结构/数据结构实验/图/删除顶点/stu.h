status DeleteVex(ALGraph &G,KeyType v)
//在图G中删除关键字v对应的顶点以及相关的弧，成功返回OK,否则返回ERROR
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
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
    return OK;

    /********** End **********/
}