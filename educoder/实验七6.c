#include<stdio.h>
#include<string.h>

struct node
{
    char id[105];
    char name[105];
    int english;
    int math;
    int physics;
    int cpp;
    int sum;
    double avg;
}stus[105];

void mysort(struct node*arr,int len)
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-1-i;j++)
        {
            if(arr[j].avg>arr[j+1].avg)
            {
                struct node temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
    int op,k=0;
    while(scanf("%d",&op)==1)
    {
        if(op==0)return 0;
        else if(op==1)
        {
            int n;
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                scanf("%s%s%d%d%d%d",stus[k+i].id,stus[k+i].name,&stus[k+i].english,&stus[k+i].math,&stus[k+i].physics,&stus[k+i].cpp);
                stus[k+i].sum=stus[k+i].english+stus[k+i].math+stus[k+i].physics+stus[k+i].cpp;
                stus[k+i].avg=stus[k+i].sum/4.0;
            }
            k+=n;
        }
        else if(op==2)
        {
            mysort(stus,k);
            for(int i=0;i<k;i++)
            {
                printf("%s %s ",stus[i].id,stus[i].name);
                printf("%d %d %d %d\n",stus[i].english,stus[i].math,stus[i].physics,stus[i].cpp);
            }
        }
        else if(op==3)
        {
            char id[105];
            int subject,score;
            scanf("%s%d%d",id,&subject,&score);
            for(int i=0;i<k;i++)
            {
                if(strcmp(stus[i].id,id)==0)
                {
                    // printf("strcmp is called!\n");
                    if(subject==1)stus[i].english=score;
                    else if(subject==2)stus[i].math=score;
                    else if(subject==3)stus[i].physics=score;
                    else if(subject==4)stus[i].cpp=score;
                    stus[i].sum=stus[i].english+stus[i].math+stus[i].physics+stus[i].cpp;
                    stus[i].avg=stus[i].sum/4.0;
                }
            }
        }
        else if(op==4)
        {
            mysort(stus,k);
            for(int i=0;i<k;i++)
            {
                printf("%s %s %.2lf\n",stus[i].id,stus[i].name,stus[i].avg);
            }
        }
        else if(op==5)
        {
            mysort(stus,k);
            for(int i=0;i<k;i++)
            {
                printf("%s %s ",stus[i].id,stus[i].name);
                printf("%d %.2lf\n",stus[i].sum,stus[i].avg);
            }            
        }
    }
    return 0;
}