#include "def.h"
#include "functions.h"
const int num_op=19;//操作选项数量 
const int N=105;//多表最大容量
ALGraph g_list[N];//多表数组
int num_list=0;//当前多表数量
int now=-1;//当前位于的多表编号 
void run()
{
	system("cls");
	printf("-----------------------------------------------------------------\n");
	printf("\t1. 创建图\t\t\t2. 销毁图\n");
	printf("\t3. 查找顶点\t\t\t4. 顶点赋值\n");
	printf("\t5. 获得第一邻接点\t\t6.获得下一邻接点\n");
	printf("\t7. 插入顶点\t\t\t8. 删除顶点\n");
	printf("\t9. 插入弧\t\t\t10. 删除弧\n");
	printf("\t11. 深度优先搜索遍历\t\t12. 广度优先搜索遍历\n");
	printf("\t13. 距离小于k的顶点集合\t\t14. 顶点间最短路径和长度\n");
	printf("\t15. 图的联通分量\t\t16. 保存图到文件\n");
	printf("\t17. 从文件加载图\t\t18. 创建文件\n");
	printf("\t19. 多表切换\n");
	printf("-----------------------------------------------------------------\n");
	printf("输入数字[1~%d]来进行操作: ",num_op); 
	int op;
	scanf("%d",&op);
	if(op==1)//创建图 
	{
		char name[105];//多表名字 
		printf("输入名字: ");
		int pre=now;//先保存更新前的编号 
		now=num_list++;//更新编号 
		scanf("%s",name);
		for(int i=0;i<num_list;i++)
		{
			if(strcmp(g_list[i].name,"")==0)continue;
			if(strcmp(g_list[i].name,name)==0)
			{
				printf("名字重复\n");
				num_list--;
				now=pre;
				return; 
			}
		}
		printf("输入顶点数组(\"-1 nil\"作为结尾): ");
		VertexType V[25];//顶点数组 
		int key;//关键字 
		char others[20];//姓名属性 
		for(int i=0;;i++)
		{
			scanf("%d%s",&key,others);
			V[i].key=key;
			strcpy(V[i].others,others);
			if(key==-1)break;
		}
		printf("输入顶点关系集(\"-1 -1\"作为结尾): "); 
		KeyType VR[205][2];//顶点关系数组 
		for(int i=0;;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			VR[i][0]=u;
			VR[i][1]=v;
			if(u==-1)break;
		}
		int res=CreateCraph(g_list[now],V,VR);
		if(res)
		{
			printf("创建成功\n"); 
			strcpy(g_list[now].name,name);
		}
		else
		{
			printf("创建失败\n"); 
			now=pre;
			num_list--;
		}
	}
	else if(op==2)//销毁图 
	{
		int res=DestroyGraph(g_list[now]);
		if(res)
		{
			strcpy(g_list[now].name,"");
			printf("销毁成功\n");	
		} 
	}
	else if(op==3)//查找顶点 
	{
		printf("输入key: ");
		int key;//关键字 
		scanf("%d",&key); 
		int res=LocateVex(g_list[now],key); 
		if(res==-1)
		{
			printf("查找失败\n"); 
		}
		else 
		{
			printf("查找成功\n");
			printf("(%d,%s)的顶点位置序号为%d\n",key,g_list[now].vertices[res].data.others,res); 
		}
	}
	else if(op==4)//顶点赋值 
	{
		printf("输入key: ");
		int key;//关键字 
		scanf("%d",&key);
		printf("输入新的key: ");
		int r_key;//新的关键字 
		scanf("%d", &r_key);
		char others[20];//新的others属性 
		printf("输入新的others: "); 
		scanf("%s",others); 
		VertexType value;//新的value 
		value.key=r_key;
		strcpy(value.others,others);
		int res=PutVex(g_list[now],key,value);
		if(res)printf("修改成功\n");
		else printf("修改失败\n"); 
	}
	else if(op==5)//第一邻接点 
	{
		printf("输入key: ");
		int key;//关键字 
		scanf("%d",&key);
		int res=FirstAdjVex(g_list[now],key);
		if(res!=-1)
		{
			printf("查找成功\n");
			printf("%d的第一邻接点位序为%d\n",key,res);
		}
		else
		{
			printf("查找失败\n"); 
		}
	}
	else if(op==6)//下一邻接点 
	{
		printf("输入图的一个顶点的key: ");
		int v;//关键字 
		scanf("%d",&v);
		printf("输入顶点的一个邻接节点的key: ");
		int w;//邻接节点的关键字 
		scanf("%d",&w);
		int res=NextAdjVex(g_list[now],v,w);
		if(res==-1)
		{
			printf("查找失败\n"); 
		}
		else
		{
			printf("查找成功\n");
			printf("顶点%d相对于顶点%d的下一邻接点的位序为%d\n",v,w,res); 
		}
	}
	else if(op==7)//插入顶点 
	{
		printf("输入要插入的顶点的key: ");
		int key;//关键字 
		scanf("%d",&key);
		printf("输入要插入的顶点的others: ");
		char others[20];//others属性 
		scanf("%s",others);
		VertexType v; 
		v.key=key;
		strcpy(v.others,others);
		int res=InsertVex(g_list[now],v); 
		if(res)printf("插入成功\n");
		else printf("插入失败\n"); 
	}
	else if(op==8)//删除顶点 
	{
		printf("输入要删除的顶点的key: "); 
		int key;//关键字 
		scanf("%d",&key);
		int res=DeleteVex(g_list[now],key);
		if(res)printf("删除成功\n");
		else printf("删除失败\n"); 
	}
	else if(op==9)//插入弧 
	{
		printf("输入两个顶点的key: ");
		int v,w;//两个顶点的关键字 
		scanf("%d%d",&v,&w);
		int res=InsertArc(g_list[now],v,w);
		if(res)printf("插入成功\n");
		else printf("插入失败\n"); 
	}
	else if(op==10)//删除弧 
	{
		printf("输入两个顶点的key: "); 
		int v,w;//两个顶点的关键字 
		scanf("%d%d",&v,&w);
		int res=DeleteArc(g_list[now],v,w);
		if(res)printf("删除成功\n");
		else printf("删除失败\n"); 
	}
	else if(op==11)//深度优先搜索 
	{
		int res=DFSTraverse(g_list[now]);
		if(res)printf("\n遍历成功\n");
		else printf("\n空图无法遍历\n"); 
	}
	else if(op==12)//广度优先搜索 
	{
		int res=BFSTraverse(g_list[now]);
		if(res)printf("\n遍历成功\n");
		else printf("空图无法遍历"); 
	}
	else if(op==13)
	{
		printf("输入距离k: ");
		int k;//距离 
		scanf("%d",&k);
		printf("输入顶点关键字: ");
		int v;//顶点关键字 
		scanf("%d",&v);
		int vv=LocateVex(g_list[now],v);
		int ans[N];//保存距离小于k的结点数组 
		memset(ans,0x3f,sizeof(ans)); 
		VerticesSetLessThanK(g_list[now],vv,k);
	}
	else if(op==14)//两顶点间的最短路径和长度 
	{
		printf("输入两个顶点的key: ");
		int path[N];//保存过程中的路径 
		int vis[N];//标记访问过的结点 
		memset(vis,0,sizeof(vis));
		int r_ans[N];//保存最短路径的数组 
		int v,w;//两个结点的key 
		int ans=1e9;
		scanf("%d%d",&v,&w); 
		int nownode=LocateVex(g_list[now],v);
		int node=LocateVex(g_list[now],w);
		if(nownode==-1||node==-1)
		{
			printf("结点不存在\n");
			return; 
		}
		if(v==w)
		{
			printf("最短路径的长度为0\n");
			printf("路径为: \n");
			printf("%d\n",v);
			return;
		}
		vis[nownode]=1;
		path[0]=v;
		MaxPath(g_list[now],nownode,node,1,path,vis,ans,r_ans);
		if(ans==(int)1e9){
			printf("两顶点不连通\n");
			return; 
		}
		printf("最短路径的长度为%d\n",ans);
		printf("其中一条路径为: \n"); 
		for(int i=0;i<ans;i++)
		{
			printf("%d->",r_ans[i]);
		}
		printf("%d\n",r_ans[ans]);
	}
	else if(op==15)//图的联通分支数 
	{
		int res=ConnectedComponentsNums(g_list[now]);
		printf("图的联通分支数量为%d\n",res); 
	}
	else if(op==16)//保存图到文件 
	{
		printf("输入文件名: ");
		char filename[105];//文件名 
		scanf("%s",filename); 
		int res=SaveGraph(g_list[now],filename);
		if(res)printf("保存成功\n");
		else printf("保存失败\n"); 
	}
	else if(op==17)//从文件加载图 
	{
		printf("输入文件名: ");
		char filename[105];//文件名 
		scanf("%s",filename);
		int res=LoadGraph(g_list[now],filename);
		if(res)printf("加载成功\n");
		else printf("加载失败\n"); 
	}
	else if(op==18)//创建文件 
	{
		printf("输入文件名: "); 
		char filename[105];//文件名 
		scanf("%s",filename);
		char command[]="Type NUL>";
		strcat(command,filename);
		system(command);
		printf("创建成功\n");
	}
	else if(op==19)//切换多表 
	{
		printf("输入名字: ");
		char name[105];//文件名 
		scanf("%s",name);
		int flag=0;//标记是否找到了对应的多表 
		for(int i=0;i<num_list;i++)
		{
			if(strcmp(g_list[i].name,"")==0)continue;
			if(strcmp(g_list[i].name,name)==0)
			{
				now=i;
				flag=1;
				break;	
			}	
		} 
		if(!flag)
		{
			printf("切换失败\n"); 
		}
		else
		{
			printf("切换成功\n");
			printf("当前所在: %s\n",g_list[now].name); 
		}
	}
}
int main()
{
	while(1)
	{
		run();
		system("pause");
	}
	return 0;
}
