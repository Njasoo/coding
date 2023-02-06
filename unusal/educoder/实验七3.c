#include <stdio.h>
#include <stdlib.h>

struct s_list{
    int data;
    struct s_list *next;
};

struct s_list* create_list(struct s_list *headp,int *p);
struct s_list* reverse_list(struct s_list *headp);

int main(void){
    struct s_list *head=NULL,*p;
    int s[105],k=0;
    while(scanf("%d",&s[k])==1)k++;
    head=create_list(head,s);
    p=reverse_list(head);
    while (p){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
    return 0;  
}

struct s_list* create_list(struct s_list *headp,int *p){
    struct s_list *loc_head=NULL,*tail;
    if(p[0])
    {
        loc_head=(struct s_list *)malloc(sizeof(struct s_list));
        loc_head->data=*p++;
        tail=loc_head;
        while (*p)
        {
            tail->next=(struct s_list *)malloc(sizeof(struct s_list));
            tail=tail->next;
            tail->data=*p++;
        }
        tail->next=NULL;
        
    }
    return loc_head;
}

struct s_list* reverse_list(struct s_list *headp)
{
    struct s_list *pre=NULL,*nex;
    while(headp)
    {
        nex=headp->next;
        headp->next=pre;
        pre=headp;
        headp=nex;
    }
    return pre;
}
