#include "def.h"
#include "functions.h"
const int num_op=19;//����ѡ������ 
const int N=105;//����������
ALGraph g_list[N];//�������
int num_list=0;//��ǰ�������
int now=-1;//��ǰλ�ڵĶ���� 
void run()
{
	system("cls");
	printf("-----------------------------------------------------------------\n");
	printf("\t1. ����ͼ\t\t\t2. ����ͼ\n");
	printf("\t3. ���Ҷ���\t\t\t4. ���㸳ֵ\n");
	printf("\t5. ��õ�һ�ڽӵ�\t\t6.�����һ�ڽӵ�\n");
	printf("\t7. ���붥��\t\t\t8. ɾ������\n");
	printf("\t9. ���뻡\t\t\t10. ɾ����\n");
	printf("\t11. ���������������\t\t12. ���������������\n");
	printf("\t13. ����С��k�Ķ��㼯��\t\t14. ��������·���ͳ���\n");
	printf("\t15. ͼ����ͨ����\t\t16. ����ͼ���ļ�\n");
	printf("\t17. ���ļ�����ͼ\t\t18. �����ļ�\n");
	printf("\t19. ����л�\n");
	printf("-----------------------------------------------------------------\n");
	printf("��������[1~%d]�����в���: ",num_op); 
	int op;
	scanf("%d",&op);
	if(op==1)//����ͼ 
	{
		char name[105];//������� 
		printf("��������: ");
		int pre=now;//�ȱ������ǰ�ı�� 
		now=num_list++;//���±�� 
		scanf("%s",name);
		for(int i=0;i<num_list;i++)
		{
			if(strcmp(g_list[i].name,"")==0)continue;
			if(strcmp(g_list[i].name,name)==0)
			{
				printf("�����ظ�\n");
				num_list--;
				now=pre;
				return; 
			}
		}
		printf("���붥������(\"-1 nil\"��Ϊ��β): ");
		VertexType V[25];//�������� 
		int key;//�ؼ��� 
		char others[20];//�������� 
		for(int i=0;;i++)
		{
			scanf("%d%s",&key,others);
			V[i].key=key;
			strcpy(V[i].others,others);
			if(key==-1)break;
		}
		printf("���붥���ϵ��(\"-1 -1\"��Ϊ��β): "); 
		KeyType VR[205][2];//�����ϵ���� 
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
			printf("�����ɹ�\n"); 
			strcpy(g_list[now].name,name);
		}
		else
		{
			printf("����ʧ��\n"); 
			now=pre;
			num_list--;
		}
	}
	else if(op==2)//����ͼ 
	{
		int res=DestroyGraph(g_list[now]);
		if(res)
		{
			strcpy(g_list[now].name,"");
			printf("���ٳɹ�\n");	
		} 
	}
	else if(op==3)//���Ҷ��� 
	{
		printf("����key: ");
		int key;//�ؼ��� 
		scanf("%d",&key); 
		int res=LocateVex(g_list[now],key); 
		if(res==-1)
		{
			printf("����ʧ��\n"); 
		}
		else 
		{
			printf("���ҳɹ�\n");
			printf("(%d,%s)�Ķ���λ�����Ϊ%d\n",key,g_list[now].vertices[res].data.others,res); 
		}
	}
	else if(op==4)//���㸳ֵ 
	{
		printf("����key: ");
		int key;//�ؼ��� 
		scanf("%d",&key);
		printf("�����µ�key: ");
		int r_key;//�µĹؼ��� 
		scanf("%d", &r_key);
		char others[20];//�µ�others���� 
		printf("�����µ�others: "); 
		scanf("%s",others); 
		VertexType value;//�µ�value 
		value.key=r_key;
		strcpy(value.others,others);
		int res=PutVex(g_list[now],key,value);
		if(res)printf("�޸ĳɹ�\n");
		else printf("�޸�ʧ��\n"); 
	}
	else if(op==5)//��һ�ڽӵ� 
	{
		printf("����key: ");
		int key;//�ؼ��� 
		scanf("%d",&key);
		int res=FirstAdjVex(g_list[now],key);
		if(res!=-1)
		{
			printf("���ҳɹ�\n");
			printf("%d�ĵ�һ�ڽӵ�λ��Ϊ%d\n",key,res);
		}
		else
		{
			printf("����ʧ��\n"); 
		}
	}
	else if(op==6)//��һ�ڽӵ� 
	{
		printf("����ͼ��һ�������key: ");
		int v;//�ؼ��� 
		scanf("%d",&v);
		printf("���붥���һ���ڽӽڵ��key: ");
		int w;//�ڽӽڵ�Ĺؼ��� 
		scanf("%d",&w);
		int res=NextAdjVex(g_list[now],v,w);
		if(res==-1)
		{
			printf("����ʧ��\n"); 
		}
		else
		{
			printf("���ҳɹ�\n");
			printf("����%d����ڶ���%d����һ�ڽӵ��λ��Ϊ%d\n",v,w,res); 
		}
	}
	else if(op==7)//���붥�� 
	{
		printf("����Ҫ����Ķ����key: ");
		int key;//�ؼ��� 
		scanf("%d",&key);
		printf("����Ҫ����Ķ����others: ");
		char others[20];//others���� 
		scanf("%s",others);
		VertexType v; 
		v.key=key;
		strcpy(v.others,others);
		int res=InsertVex(g_list[now],v); 
		if(res)printf("����ɹ�\n");
		else printf("����ʧ��\n"); 
	}
	else if(op==8)//ɾ������ 
	{
		printf("����Ҫɾ���Ķ����key: "); 
		int key;//�ؼ��� 
		scanf("%d",&key);
		int res=DeleteVex(g_list[now],key);
		if(res)printf("ɾ���ɹ�\n");
		else printf("ɾ��ʧ��\n"); 
	}
	else if(op==9)//���뻡 
	{
		printf("�������������key: ");
		int v,w;//��������Ĺؼ��� 
		scanf("%d%d",&v,&w);
		int res=InsertArc(g_list[now],v,w);
		if(res)printf("����ɹ�\n");
		else printf("����ʧ��\n"); 
	}
	else if(op==10)//ɾ���� 
	{
		printf("�������������key: "); 
		int v,w;//��������Ĺؼ��� 
		scanf("%d%d",&v,&w);
		int res=DeleteArc(g_list[now],v,w);
		if(res)printf("ɾ���ɹ�\n");
		else printf("ɾ��ʧ��\n"); 
	}
	else if(op==11)//����������� 
	{
		int res=DFSTraverse(g_list[now]);
		if(res)printf("\n�����ɹ�\n");
		else printf("\n��ͼ�޷�����\n"); 
	}
	else if(op==12)//����������� 
	{
		int res=BFSTraverse(g_list[now]);
		if(res)printf("\n�����ɹ�\n");
		else printf("��ͼ�޷�����"); 
	}
	else if(op==13)
	{
		printf("�������k: ");
		int k;//���� 
		scanf("%d",&k);
		printf("���붥��ؼ���: ");
		int v;//����ؼ��� 
		scanf("%d",&v);
		int vv=LocateVex(g_list[now],v);
		int ans[N];//�������С��k�Ľ������ 
		memset(ans,0x3f,sizeof(ans)); 
		VerticesSetLessThanK(g_list[now],vv,k);
	}
	else if(op==14)//�����������·���ͳ��� 
	{
		printf("�������������key: ");
		int path[N];//��������е�·�� 
		int vis[N];//��Ƿ��ʹ��Ľ�� 
		memset(vis,0,sizeof(vis));
		int r_ans[N];//�������·�������� 
		int v,w;//��������key 
		int ans=1e9;
		scanf("%d%d",&v,&w); 
		int nownode=LocateVex(g_list[now],v);
		int node=LocateVex(g_list[now],w);
		if(nownode==-1||node==-1)
		{
			printf("��㲻����\n");
			return; 
		}
		if(v==w)
		{
			printf("���·���ĳ���Ϊ0\n");
			printf("·��Ϊ: \n");
			printf("%d\n",v);
			return;
		}
		vis[nownode]=1;
		path[0]=v;
		MaxPath(g_list[now],nownode,node,1,path,vis,ans,r_ans);
		if(ans==(int)1e9){
			printf("�����㲻��ͨ\n");
			return; 
		}
		printf("���·���ĳ���Ϊ%d\n",ans);
		printf("����һ��·��Ϊ: \n"); 
		for(int i=0;i<ans;i++)
		{
			printf("%d->",r_ans[i]);
		}
		printf("%d\n",r_ans[ans]);
	}
	else if(op==15)//ͼ����ͨ��֧�� 
	{
		int res=ConnectedComponentsNums(g_list[now]);
		printf("ͼ����ͨ��֧����Ϊ%d\n",res); 
	}
	else if(op==16)//����ͼ���ļ� 
	{
		printf("�����ļ���: ");
		char filename[105];//�ļ��� 
		scanf("%s",filename); 
		int res=SaveGraph(g_list[now],filename);
		if(res)printf("����ɹ�\n");
		else printf("����ʧ��\n"); 
	}
	else if(op==17)//���ļ�����ͼ 
	{
		printf("�����ļ���: ");
		char filename[105];//�ļ��� 
		scanf("%s",filename);
		int res=LoadGraph(g_list[now],filename);
		if(res)printf("���سɹ�\n");
		else printf("����ʧ��\n"); 
	}
	else if(op==18)//�����ļ� 
	{
		printf("�����ļ���: "); 
		char filename[105];//�ļ��� 
		scanf("%s",filename);
		char command[]="Type NUL>";
		strcat(command,filename);
		system(command);
		printf("�����ɹ�\n");
	}
	else if(op==19)//�л���� 
	{
		printf("��������: ");
		char name[105];//�ļ��� 
		scanf("%s",name);
		int flag=0;//����Ƿ��ҵ��˶�Ӧ�Ķ�� 
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
			printf("�л�ʧ��\n"); 
		}
		else
		{
			printf("�л��ɹ�\n");
			printf("��ǰ����: %s\n",g_list[now].name); 
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
