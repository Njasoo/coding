#include "def.h"//����˳��Ҳ�н��� 
#include "functions.h"

const int N=105;//���������� 
const int num_op=21;//�ɲ���������� 
BiTree g_list[N];//��������ͷ�������
int num_list=0;//��ǰ�Ķ������ 
int now=0;//��ǰ�����Ķ����  

void init()
{
	for(int i=0;i<N;i++)g_list[i]=NULL;
}

void run()
{
	system("cls");
	printf("-----------------------------------------------------------------\n");
	printf("\t1. ����������\t\t\t2. ���ٶ�����\n");
	printf("\t3. ��ն�����\t\t\t4. �ж��ն�����\n");
	printf("\t5. ����������\t\t\t6.���ҽ��\n");
	printf("\t7. ��㸳ֵ\t\t\t8. ����ֵܽ��\n");
	printf("\t9. ������\t\t\t10. ɾ�����\n");
	printf("\t11. ǰ�����\t\t\t12. �������\n");
	printf("\t13. �������\t\t\t14. �������\n");
	printf("\t15. ���·����\t\t\t16. �����������\n");
	printf("\t17. ��ת������\t\t\t18. �����ļ�\n");
	printf("\t19. ������������ļ�\t\t20. ���ļ����ض�����\n");
	printf("\t21. ����л�\n"); 
	printf("-----------------------------------------------------------------\n");
	
	printf("��������[1~%d]�����в���: ",num_op); 
	int op;//�����ѡ�� 
	scanf("%d",&op);
	if(op==1)//���������� 
	{
		int pre=now;//�������ǰ�ı�� 
		now=num_list++;//���±�� 
		printf("��������: ");
		char name[105];//������������� 
		scanf("%s",name);
		printf("������սڵ��ǰ������(�սڵ���\"0 null\"��ʾ, ���������\"-1 -1\"��ʾ: ");
		TElemType definition[105];//ǰ����սڵ���������� 
		for(int i=0;;i++)
		{
			int key;//�ؼ��� 
			char others[20];
			scanf("%d%s",&key,others);
			definition[i].key=key;
			strcpy(definition[i].others,others);
			if(key==-1)break;
		}
		int res=CreateBiTree(g_list,num_list,g_list[now],definition,name);  
		if(res)printf("�����ɹ�\n");
		else
		{
			printf("����ʧ��\n");
			now=pre;//���ص����еĶ�� 
			num_list--;
		}
	}
	else if(op==2)//���ٶ����� 
	{
		if(root)root=NULL;//��Ҫfree��,ָ��վ���,����������ж��������Ƿ�Ϊ�յı��� 
		int res=DestroyBiTree(g_list[now]);
		if(res==-1)printf("��Ҫ�ظ����ٶ�����\n");
		else printf("���ٳɹ�\n"); 
	}
	else if(op==3)//��ն����� 
	{
		//ע�ⲻҪ���һ���յĶ�����,������û��д 
		int res=ClearBiTree(g_list[now]->lchild);
		if(res)printf("��ճɹ�\n"); 
	}
	else if(op==4)//�������п� 
	{
		int res=IsEmpty(g_list[now]->lchild);
		if(res)printf("������Ϊ��\n");
		else printf("��������Ϊ��\n"); 
	}
	else if(op==5)
	{
		int res=BiTreeDepth(g_list[now]->lchild);
		printf("�����������Ϊ%d\n",res);
	}
	else if(op==6)//���ҽ�� 
	{
		printf("����ؼ���: ");
		int key;//�ؼ��� 
		scanf("%d",&key);
		BiTNode* res=LocateNode(g_list[now]->lchild,key);
		if(res==NULL) 
		{
			printf("����ʧ��\n");	
		}
		else
		{
			printf("���ҳɹ�\n");
			printf("%d,%s\n",res->data.key,res->data.others); 
		}
	}
	else if(op==7)//��㸳ֵ 
	{
		printf("����ؼ���: ");
		int key;//�ؼ��� 
		scanf("%d",&key);
		printf("����Ҫ����key: ");
		int r_key;//�µĹؼ��� 
		scanf("%d",&r_key); 
		printf("����Ҫ����others: "); 
		char others[20];
		scanf("%s",others);
		TElemType value;
		value.key=r_key;
		strcpy(value.others,others);
		int res=Assign(g_list[now]->lchild,key,value);
		if(res)printf("��ֵ�ɹ�\n");
		else printf("��ֵʧ��\n"); 
	}
	else if(op==8)//��ȡ�ֵܽ�� 
	{
		printf("����ؼ���: ");
		int key;//�ؼ��� 
		scanf("%d",&key);
		BiTNode *res;
		res=GetSibling(g_list[now]->lchild,key); 
		if(res==NULL)
		{
			printf("��ȡʧ��\n"); 
		}
		else
		{
			printf("��ȡ�ɹ�\n");
			printf("�ֵܽ��Ϊ%d,%s\n",res->data.key,res->data.others); 
		}
	}
	else if(op==9)//������ 
	{
		printf("����Ҫ���뵽�Ľ��Ĺؼ���: ");
		int key;//�ؼ��� 
		scanf("%d",&key);
		printf("����Ҫ���뵽��߻����ұ�(�������0,�ұ�����1): ");
		int LR;//0Ϊ���,1Ϊ�ұ� 
		scanf("%d",&LR);
		printf("��������Ҫ����Ľ�������\n");
		printf("����key: ");
		int r_key;//Ҫ����Ľ��Ĺػ�ף�� 
		scanf("%d",&r_key);
		printf("����others: ");
		char others[20];
		scanf("%s",others);
		TElemType c;
		c.key=r_key;
		strcpy(c.others,others);
		int res=InsertNode(g_list[now]->lchild,key,LR,c);
		if(res)printf("����ɹ�\n");
		else printf("����ʧ��\n"); 
	}
	else if(op==10)//ɾ���ڵ� 
	{
		printf("����ؼ���: ");
		int key;//�ؼ��� 
		scanf("%d",&key); 
		int res=DeleteNode(g_list[now]->lchild,key);
		if(res)printf("ɾ���ɹ�\n");
		else printf("ɾ��ʧ��\n"); 
	}
	else if(op==11)//ǰ����� 
	{
		int res=PreOrderTraverse(g_list[now]->lchild);
		if(res)printf("\nǰ������ɹ�\n");
		else printf("\nǰ�����ʧ��\n"); 
	}
	else if(op==12)//������� 
	{
		int res=InOrderTraverse(g_list[now]->lchild);
		if(res)printf("\n��������ɹ�\n");
		else printf("\n�������ʧ��\n"); 
	}
	else if(op==13)//������� 
	{
		int res=PostOrderTraverse(g_list[now]->lchild);
		if(res)printf("\n��������ɹ�\n"); 
		else printf("\n��������ɹ�\n"); 
	}
	else if(op==14)//������� 
	{
		int res=LevelOrderTraverse(g_list[now]->lchild);
		if(res)printf("\n��������ɹ�\n");
		else printf("\n�������ʧ��\n"); 
	}
	else if(op==15)//���·���� 
	{
		int res=MaxPath(g_list[now]->lchild);
		printf("�Ӹ��ڵ㵽Ҷ�ӽ������·������Ϊ%d\n",res); 
	}
	else if(op==16)//����������� 
	{
		printf("������������key: ");
		int v,w;//�������Ĺؼ��� 
		scanf("%d%d",&v,&w);
		auto node1=LocateNode(g_list[now]->lchild,v);
		auto node2=LocateNode(g_list[now]->lchild,w);
//		printf("node1->data.key: %d node1->data.others: %s\n",node1->data.key,node1->data.others);
//		printf("node2->data.key: %d node2->data.others: %s\n",node2->data.key,node2->data.others);
		auto res=LCA(g_list[now]->lchild,node1,node2);
		if(res)
		{
			printf("���ҳɹ�\n");
			printf("���%d�ͽ��%d�������������Ϊ:\n",v,w);
			printf("key: %d,others: %s\n",res->data.key,res->data.others);	
		}
		else
		{
			printf("����ʧ��\n"); 
		}
	}
	else if(op==17)//��ת������ 
	{
		g_list[now]->lchild=invertTree(g_list[now]->lchild);
		printf("��������ת�ɹ�\n"); 
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
	else if(op==19)//������������ļ� 
	{
		printf("�����ļ���: ");
		char filename[105];//�ļ��� 
		scanf("%s",filename);
		int res=SaveBiTree(g_list[now]->lchild,filename);
		printf("����ɹ�\n"); 
	}
	else if(op==20)//���ļ����ض����� 
	{
		printf("�����ļ���: ");
		char filename[105];//�ļ��� 
		scanf("%s",filename);
		int res=LoadBiTree(g_list[now]->lchild,filename);
		printf("���سɹ�\n"); 
	}
	else if(op==21)//�л���� 
	{
		printf("��������: "); 
		char name[105];//������� 
		scanf("%s",name);
		int res=ListSwitch(g_list,num_list,name,now);
		if(res)
		{
			printf("�л��ɹ�\n");
			printf("��ǰ����: %s\n",g_list[now]->name); 
		} 
		else
		{
			printf("�л�ʧ��\n"); 
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
