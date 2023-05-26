#include<string.h>
status SaveGraph(ALGraph G, char FileName[])
//将图的数据写入到文件FileName中
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 1 *********/
    FILE *fp=fopen(FileName,"w");
    int hash[25][25]={0};
    //先把vertex的资料写进去
    for(int i=0;i<G.vexnum;i++)
    {
        fprintf(fp,"%d %s\n",G.vertices[i].data.key,G.vertices[i].data.others);
    }
    fprintf(fp,"-1 nil\n");
    for(int i=0;i<G.vexnum;i++)
    {
        auto p=G.vertices[i].firstarc;
        while(p)
        {
            int tempi=i;
            int tempj=p->adjvex;
            if(tempi>tempj)
            {
                int temp=tempi;
                tempi=tempj;
                tempj=temp;
            }
            if(hash[tempi][tempj])
            {
                p=p->nextarc;
                continue;
            }
            hash[tempi][tempj]=1;
            fprintf(fp,"%d %d\n",tempi,tempj);
            p=p->nextarc;
        }
    }
    fprintf(fp,"-1 -1\n");
    fclose(fp);
    return OK;

    /********** End 1 **********/
}
status LoadGraph(ALGraph &G, char FileName[])
//读入文件FileName的图数据，创建图的邻接表
{
    // 请在这里补充代码，完成本关任务
    /********** Begin 2 *********/
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
    for(int i=0;i<G.vexnum;i++)//记得，很重要的步骤
    {
        G.vertices[i].firstarc=NULL;
    }

    for(int i=0;;i++)
    {
        int u,v;
        fscanf(fp,"%d %d\n",&u,&v);
        if(u==-1)
        {
            G.arcnum=i;
            break;
        }
        auto p1=(ArcNode*)malloc(sizeof(ArcNode));
        p1->adjvex=v;
        p1->nextarc=G.vertices[u].firstarc;
        G.vertices[u].firstarc=p1;

        auto p2=(ArcNode*)malloc(sizeof(ArcNode));
        p2->adjvex=u;
        p2->nextarc=G.vertices[v].firstarc;
        G.vertices[v].firstarc=p2;
    }
    // printf("G.vexnum=%d\n",G.vexnum);
    // printf("G.arcnum=%d\n",G.arcnum);
    fclose(fp);
    return OK;

    /********** End 2 **********/
}
