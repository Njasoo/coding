#include "def.h"//引用顺序也有讲究 
#include "functions.h"

const int N=105;//多表最大容量 
const int num_op=21;//可操作项的数量 
BiTree g_list[N];//多表二叉树头结点数组
int num_list=0;//当前的多表数量 
int now=0;//当前所处的多表编号  

void init()
{
	for(int i=0;i<N;i++)g_list[i]=NULL;
}

void run()
{
	system("cls");
	printf("-----------------------------------------------------------------\n");
	printf("\t1. 创建二叉树\t\t\t2. 销毁二叉树\n");
	printf("\t3. 清空二叉树\t\t\t4. 判定空二叉树\n");
	printf("\t5. 求二叉树深度\t\t\t6.查找结点\n");
	printf("\t7. 结点赋值\t\t\t8. 获得兄弟结点\n");
	printf("\t9. 插入结点\t\t\t10. 删除结点\n");
	printf("\t11. 前序遍历\t\t\t12. 中序遍历\n");
	printf("\t13. 后序遍历\t\t\t14. 按层遍历\n");
	printf("\t15. 最大路径和\t\t\t16. 最近公共祖先\n");
	printf("\t17. 翻转二叉树\t\t\t18. 创建文件\n");
	printf("\t19. 保存二叉树到文件\t\t20. 从文件加载二叉树\n");
	printf("\t21. 多表切换\n"); 
	printf("-----------------------------------------------------------------\n");
	
	printf("输入数字[1~%d]来进行操作: ",num_op); 
	int op;//输入的选项 
	scanf("%d",&op);
	if(op==1)//创建二叉树 
	{
		int pre=now;//保存更新前的编号 
		now=num_list++;//更新标号 
		printf("输入名字: ");
		char name[105];//二叉树多表名称 
		scanf("%s",name);
		printf("输入带空节点的前序序列(空节点用\"0 null\"表示, 输入结束用\"-1 -1\"表示: ");
		TElemType definition[105];//前序带空节点的序列数组 
		for(int i=0;;i++)
		{
			int key;//关键字 
			char others[20];
			scanf("%d%s",&key,others);
			definition[i].key=key;
			strcpy(definition[i].others,others);
			if(key==-1)break;
		}
		int res=CreateBiTree(g_list,num_list,g_list[now],definition,name);  
		if(res)printf("创建成功\n");
		else
		{
			printf("创建失败\n");
			now=pre;//返回到可行的多表 
			num_list--;
		}
	}
	else if(op==2)//销毁二叉树 
	{
		if(root)root=NULL;//不要free它,指向空就行,这个是用来判定二叉树是否为空的变量 
		int res=DestroyBiTree(g_list[now]);
		if(res==-1)printf("不要重复销毁二叉树\n");
		else printf("销毁成功\n"); 
	}
	else if(op==3)//清空二叉树 
	{
		//注意不要清空一个空的二叉树,但是我没有写 
		int res=ClearBiTree(g_list[now]->lchild);
		if(res)printf("清空成功\n"); 
	}
	else if(op==4)//二叉树判空 
	{
		int res=IsEmpty(g_list[now]->lchild);
		if(res)printf("二叉树为空\n");
		else printf("二叉树不为空\n"); 
	}
	else if(op==5)
	{
		int res=BiTreeDepth(g_list[now]->lchild);
		printf("二叉树的深度为%d\n",res);
	}
	else if(op==6)//查找结点 
	{
		printf("输入关键字: ");
		int key;//关键字 
		scanf("%d",&key);
		BiTNode* res=LocateNode(g_list[now]->lchild,key);
		if(res==NULL) 
		{
			printf("查找失败\n");	
		}
		else
		{
			printf("查找成功\n");
			printf("%d,%s\n",res->data.key,res->data.others); 
		}
	}
	else if(op==7)//结点赋值 
	{
		printf("输入关键字: ");
		int key;//关键字 
		scanf("%d",&key);
		printf("输入要赋的key: ");
		int r_key;//新的关键字 
		scanf("%d",&r_key); 
		printf("输入要赋的others: "); 
		char others[20];
		scanf("%s",others);
		TElemType value;
		value.key=r_key;
		strcpy(value.others,others);
		int res=Assign(g_list[now]->lchild,key,value);
		if(res)printf("赋值成功\n");
		else printf("赋值失败\n"); 
	}
	else if(op==8)//获取兄弟结点 
	{
		printf("输入关键字: ");
		int key;//关键字 
		scanf("%d",&key);
		BiTNode *res;
		res=GetSibling(g_list[now]->lchild,key); 
		if(res==NULL)
		{
			printf("获取失败\n"); 
		}
		else
		{
			printf("获取成功\n");
			printf("兄弟结点为%d,%s\n",res->data.key,res->data.others); 
		}
	}
	else if(op==9)//插入结点 
	{
		printf("输入要插入到的结点的关键字: ");
		int key;//关键字 
		scanf("%d",&key);
		printf("输入要插入到左边还是右边(左边输入0,右边输入1): ");
		int LR;//0为左边,1为右边 
		scanf("%d",&LR);
		printf("下面输入要插入的结点的资料\n");
		printf("输入key: ");
		int r_key;//要插入的结点的关机祝你 
		scanf("%d",&r_key);
		printf("输入others: ");
		char others[20];
		scanf("%s",others);
		TElemType c;
		c.key=r_key;
		strcpy(c.others,others);
		int res=InsertNode(g_list[now]->lchild,key,LR,c);
		if(res)printf("插入成功\n");
		else printf("插入失败\n"); 
	}
	else if(op==10)//删除节点 
	{
		printf("输入关键字: ");
		int key;//关键字 
		scanf("%d",&key); 
		int res=DeleteNode(g_list[now]->lchild,key);
		if(res)printf("删除成功\n");
		else printf("删除失败\n"); 
	}
	else if(op==11)//前序遍历 
	{
		int res=PreOrderTraverse(g_list[now]->lchild);
		if(res)printf("\n前序遍历成功\n");
		else printf("\n前序遍历失败\n"); 
	}
	else if(op==12)//中序遍历 
	{
		int res=InOrderTraverse(g_list[now]->lchild);
		if(res)printf("\n中序遍历成功\n");
		else printf("\n中序遍历失败\n"); 
	}
	else if(op==13)//后序遍历 
	{
		int res=PostOrderTraverse(g_list[now]->lchild);
		if(res)printf("\n后序遍历成功\n"); 
		else printf("\n后序遍历成功\n"); 
	}
	else if(op==14)//按层遍历 
	{
		int res=LevelOrderTraverse(g_list[now]->lchild);
		if(res)printf("\n按层遍历成功\n");
		else printf("\n按层遍历失败\n"); 
	}
	else if(op==15)//最大路径和 
	{
		int res=MaxPath(g_list[now]->lchild);
		printf("从根节点到叶子结点的最大路径长度为%d\n",res); 
	}
	else if(op==16)//最近公共祖先 
	{
		printf("输入两个结点的key: ");
		int v,w;//两个结点的关键字 
		scanf("%d%d",&v,&w);
		auto node1=LocateNode(g_list[now]->lchild,v);
		auto node2=LocateNode(g_list[now]->lchild,w);
//		printf("node1->data.key: %d node1->data.others: %s\n",node1->data.key,node1->data.others);
//		printf("node2->data.key: %d node2->data.others: %s\n",node2->data.key,node2->data.others);
		auto res=LCA(g_list[now]->lchild,node1,node2);
		if(res)
		{
			printf("查找成功\n");
			printf("结点%d和结点%d的最近公共祖先为:\n",v,w);
			printf("key: %d,others: %s\n",res->data.key,res->data.others);	
		}
		else
		{
			printf("查找失败\n"); 
		}
	}
	else if(op==17)//翻转二叉树 
	{
		g_list[now]->lchild=invertTree(g_list[now]->lchild);
		printf("二叉树翻转成功\n"); 
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
	else if(op==19)//保存二叉树到文件 
	{
		printf("输入文件名: ");
		char filename[105];//文件名 
		scanf("%s",filename);
		int res=SaveBiTree(g_list[now]->lchild,filename);
		printf("保存成功\n"); 
	}
	else if(op==20)//从文件加载二叉树 
	{
		printf("输入文件名: ");
		char filename[105];//文件名 
		scanf("%s",filename);
		int res=LoadBiTree(g_list[now]->lchild,filename);
		printf("加载成功\n"); 
	}
	else if(op==21)//切换多表 
	{
		printf("输入名字: "); 
		char name[105];//多表名字 
		scanf("%s",name);
		int res=ListSwitch(g_list,num_list,name,now);
		if(res)
		{
			printf("切换成功\n");
			printf("当前所在: %s\n",g_list[now]->name); 
		} 
		else
		{
			printf("切换失败\n"); 
		}
	}
}

int main()
{
	init();
	while(1)
	{
		run();
		system("pause");
	}
    return 0;
}
