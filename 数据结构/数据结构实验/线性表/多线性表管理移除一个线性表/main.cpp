#include "def.h"
#include "../step01/stu.h"
#include "../step02/stu.h"
#include "../step10/stu.h"
#include "../step12/stu.h"
#include "../step14/stu.h"
#include "stu.h"
int main() {
    LISTS Lists;
   int n,e;
   char name[30];
   Lists.length=0;
    scanf("%d", &n);
    while(n--)
   {
        scanf("%s",name);
        AddList(Lists,name);
      scanf("%d",&e);
      while (e)
      {
            ListInsert(Lists.elem[Lists.length-1].L,Lists.elem[Lists.length-1].L.length+1,e);
            scanf("%d",&e);
      }
   }
   scanf("%s",name);
   if (RemoveList(Lists,name)==OK)
       for(n=0;n<Lists.length;n++)
        {
            printf("%s ",Lists.elem[n].name);
            ListTraverse(Lists.elem[n].L);
            putchar('\n');
        }
   else printf("删除失败");
return 1;
}