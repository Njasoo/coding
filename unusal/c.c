/********************************Begin********************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct list
{
    char ch[5];
    struct list* next;
};
const char ch1[]="+\0",ch2[]="-\0",ch3[]="*\0",ch4[]="/\0";
int isCal(char *x)
{
    printf("\nisCal: %c\n", *x);
    if((*x=='+')||(*x=='-')||(*x=='*')||(*x=='/')) return 1;
    else return 0;
}
int pro(char *x,char *y,char ch)
{
    int n1=atoi(x),n2=atoi(y);
    {
        if(ch=='+') return n1+n2;
        else if(ch=='-') return n1-n2;
        else if(ch=='*') return n1*n2;
        else return n1/n2;
    }
}
int main()
{
    char temp[5],cal;
    int result;
    struct list *head=NULL,*tail=NULL,*p,*q;
    while(1)//创建链表
    {
        scanf("%s",temp);
        p=(struct list*)malloc(sizeof(struct list));
        strcpy(p->ch,temp);
        if(head==NULL) head=p;
        else tail->next=p;
        tail=p;
        if(getchar()==EOF) break;
    }
    if(tail!=NULL) tail->next=NULL;
    while(1)
    {
        
        p=head;
        if(p->next==NULL) 
        {
            printf("here0 ");//检查点0
            printf("%s",p->ch);
            return 0;
        }
        
        if(isCal(p->next->next->ch)==1);
        {   
            printf("here1 %s",p->next->next->ch);//检查点1
            q=(struct list*)malloc(sizeof(struct list));//头部处理
            cal=*(p->next->next->ch);
            result=pro(p->ch,p->next->ch,cal);
            sprintf(q->ch,"%d",result);
            q->next=p->next->next->next;
            head=q;
            continue;
        }
        printf("here2 ");//检查点2
        while(!isCal(p->next->next->next->ch)) p=p->next;
        cal=*(p->next->next->next->ch);
        result=pro(p->next->ch,p->next->next->ch,cal);//此处应有函数定义
        q=(struct list*)malloc(sizeof(struct list));
        sprintf(q->ch,"%d",result);
        q->next=p->next->next->next->next;
        p->next=q;
         printf("%c",cal);
        
    }
    for(p=head;p;p=p->next) printf("%s ",p->ch);
    return 0;
}







/********************************End********************************/
