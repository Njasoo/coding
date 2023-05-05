#include "def.h"
#include "functions.h"

int num_list; // 当前多表的数量
int now = 1; // 当前线性表的编号
const int N = 105; // 多表的容量上限
SqList g_list[N]; // 多表
int num_op=21; // 菜单选项数

void run()
{
    system("cls");
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"\t1. Creat and Init List\t\t2. Destroy List"<<endl;
    cout<<"\t3. Clear List\t\t\t4. List Empty"<<endl;
    cout<<"\t5. List Length\t\t\t6. Get Element"<<endl;
    cout<<"\t7. Locate Element\t\t8. Prior Element"<<endl;
    cout<<"\t9. Next Element\t\t\t10. List Insert"<<endl;
    cout<<"\t11. Delete Element\t\t12. List Travese"<<endl; 
    cout<<"\t13. List Shift\t\t\t14. Consecutive Insert"<<endl; 
    cout<<"\t15. Show Information\t\t16. Max Subarray"<<endl;
    cout<<"\t17. SubArrayNum\t\t\t18. Sort List"<<endl;
    cout<<"\t19. Save List to File\t\t20. load List from File"<<endl;
    cout<<"\t21. Create File"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"Please input number [1~"<<num_op<<"] to operate the list: ";

    int op; // 输入的选项
    cin>>op;
    if(op<1 || op>num_op) // 判断输入是否非法
    {
        cout<<"Invalid input!"<<endl;
        cout<<"Please input again!"<<endl; 
        system("pause");
        return;
    }
    else //输入合法的情况
    {
        if(op==1)//创建并且初始化一个新的线性表
        {
            now=++num_list;//扩充线性表数组容量，并且将当前操作的链表切换到新创建的链表
            string name;//输入的链表名称
            cout<<"Input the name of the list: ";
            cin>>name;
            int res=InitList(g_list[now],g_list,name,num_list);//初始化函数返回的结果
            if(res==-1)//线性表未初始化
            {
                cout<<"Invalid operation,the list is uninitialized!\n";
                system("pause");
                return;
            }
            else if(!res)//函数返回error，说明姓名已经被用过
            {
                cout<<"The name has already been used!\n";
                system("pause");
                return;
            }
            else//初始化成功
            {
                cout<<"Initialization completed!\n";
                system("pause");
                return;
            }
            return;
        }
        if(op==2)//销毁线性表
        {
            if(DestroyList(g_list[now])==-1)//线性表未初始化
            {
                cout<<"Invalid operation!"<<endl;
                cout<<"Don't destroy an uninitialized list!"<<endl<<endl;
                system("pause");
                return;
            }
            else
            {
                cout<<"The list has been destroyed!"<<endl;
                system("pause");
            }
        }
        if(op==3)//清空线性表
        {
            if(ClearList(g_list[now])==-1)//线性表未初始化
            {
                cout<<"Invalid operation!"<<endl;
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else//清空成功
            {
                cout<<"The list is empty now!"<<endl;
                system("pause");
            }
        }
        if(op==4)//判断线性表是否为空
        {
            int res=ListEmpty(g_list[now]);//函数返回结果
            if(res==-1)//线性表未初始化
            {
                cout<<"Invalid operation!"<<endl;
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else//1空，0非空
            {
                if(res==1) cout<<"The list is empty."<<endl;
                if(res==0) cout<<"The list isn't empty."<<endl;
                system("pause");
            }
        }
        if(op==5)//求线性表长度
        {
            int res=ListLength(g_list[now]);//函数返回结果
            if(res==-1)
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else
            {
                cout<<"The length of the list is "<<g_list[now].length<<endl;
                system("pause");
            }
        }
        if(op==6)//获取第i个位置的元素
        {
            cout<<"Input the index of the element(start from 1): ";
            int index;//想要获取的元素的下标
            cin>>index;
            int elem;//用来存储第index个位置的元素
            int res=GetElem(g_list[now],index,elem);
            if(res==-1)//线性表未初始化
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else//线性表已初始化
            {
                if(res==ERROR)//下标越界
                {
                    cout<<"Index out of bounds!"<<endl;
                    system("pause");
                    return;
                }
                else//获取元素成功
                {
                    cout<<"the "<<index<<"-th element is "<<elem<<"."<<endl;
                    system("pause");
                    return;
                }
            }
        }
        if(op==7)//查找元素的位置
        {
            cout<<"Input the element: ";
            int elem;
            cin>>elem;
            int res=LocateElem(g_list[now],elem);
            if(res==-1)//线性表未初始化
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else
            {
                if(!res)//找不到对应元素
                {
                    cout<<"Element isn't in the list."<<endl;
                    system("pause");
                    return;
                }
                cout<<"The position of "<<elem<<" is "<<res<<"."<<endl;
                system("pause");
                return;
            }
        }
        if(op==8)//寻找元素前驱
        {
            cout<<"Input the element to find its prior: ";
            int elem;//待寻找的元素
            cin>>elem;
            int pre;//元素前驱
            int res=PriorElem(g_list[now],elem,pre);//函数返回结果
            if(res==-1)//线性表未初始化
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(!res)//找不到前驱，可能是找不到对应元素或者是第一个元素
            {
                cout<<"Can't find the prior!"<<endl;
                system("pause");
                return;
            }
            else//找到前驱
            {
                cout<<"The prior of "<<elem<<" is "<<" "<<pre<<"."<<endl;
                system("pause");
                return;
            }
        }
        if(op==9)//寻找后继
        {
            cout<<"Input the element to find its next element: ";
            int elem;//待寻找的元素
            cin>>elem;
            int nex;//用来存储后继
            int res=NextElem(g_list[now],elem,nex);//函数返回结果
            if(res==-1)//链表未初始化
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(!res)//找不到后继，可能是找不到对应元素，或者是最后一个元素
            {
                cout<<"Can't find the next element!"<<endl;
                system("pause");
                return;
            }
            else//找到后继
            {
                cout<<"The next element of "<<elem<<" is "<<nex<<"."<<endl;
                system("pause");
                return;
            }
        }
        if(op==10)//插入元素到对应位置
        {
            cout<<"Input the position that you want to insert at: ";
            int pos;//位置
            cin>>pos;
            cout<<"Input the element that you want to insert: ";
            int elem;//元素
            cin>>elem;
            int res=ListInsert(g_list[now],pos,elem);//函数返回结果
            if(res==-1)//线性表未初始化
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(res==0)//下标越界
            {
                cout<<"Invalid position!"<<endl;
                system("pause");
                return;
            }
            else//插入成功
            {
                cout<<"Insertion complete!"<<endl;
                system("pause");
                return;
            }
        }
        if(op==11)//删除对应位置的元素
        {
            cout<<"Input the position: "<<endl;
            int pos;//位置
            cin>>pos;
            int elem;//元素
            int res=ListDelete(g_list[now],pos,elem);//函数返回结果
            if(res==-1)//线性表未初始化
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(!res)//下标越界
            {
                cout<<"Invalid position!"<<endl;
                system("pause");
                return;
            }
            else//删除成功
            {
                cout<<"The "<<pos<<"-th element is "<<elem<<".";
                cout<<"It has been deleted!"<<endl;
                system("pause");
                return;
            }
        }
        if(op==12)//遍历线性表
        {
            int res=ListTraverse(g_list[now]);//函数返回结果
            if(res==-1)//线性表未初始化
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(!res)//线性表为空
            {
                cout<<"The list is empty!"<<endl;
            }
            cout<<"Traverse successfully!"<<endl;
            system("pause");
            return;
        }
        if(op==13)//多表切换
        {
            cout<<"Input the name of the list to switch the list: ";
            string name;//线性表的名字
            cin>>name;
            int res=ListShift(g_list,num_list,name,now);//函数返回结果
            if(!res)//找不到对应名字的线性表
            {
                cout<<"Can't find the list!\n";
                system("pause");
                return;
            }
            else//切换成功
            {
                cout<<"Shifted successfully!\n";
                system("pause");
                return;
            }
        }
        if(op==14)//连续插入元素
        {
            cout<<"Input the number of element that you are going to insert: ";
            int n;//需要输入的元素个数
            cin>>n;
            int res=ConsecutiveInsert(g_list[now],n);//函数返回结果
            if(res)//插入成功
            {
                cout<<"Insertion complete!\n";
                system("pause");
                return;
            }
            else//插入失败
            {
                cout<<"Insertion failed!\n";
                system("pause");
                return;
            }
        }
        if(op==15)//显示线性表的名字
        {
            cout<<"List name: "<<g_list[now].name<<endl;
            system("pause");
            return;
        }
        if(op==16)//最大连续子数组和
        {
            int res=MaxSubArray(g_list[now]);//函数返回结果
            if(res==-1)//线性表未初始化
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(!res)//线性表为空
            {
                cout<<"The list is empty!"<<endl;
                system("pause");
                return;
            }
            system("pause");
            return;
        }
        if(op==17)//和为k的子序列
        {
            printf("Input k: ");
            int k;
            cin>>k;
            int res=SubArrayNum(g_list[now],k);//函数返回结果
            if(res==-1)//线性表未初始化
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(res==0)//找不到和为k的子序列
            {
                cout<<"No subarray satisfy the condition!"<<endl;
                system("pause");
                return;
            }
            system("pause");
            return;
        }
        if(op==18)//线性表排序
        {
            int res=sortList(g_list[now]);//函数返回结果
            if(res==-1)//线性表未初始化
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else//排序成功
            {
                cout<<"The list has been sorted!"<<endl;
                system("pause");
                return;
            }
        }
        if(op==19)//存储线性表到文件当中
        {
            cout<<"Input the filename that you want to save the list to: ";
            char filename[105];//要存储的文件名
            cin>>filename;
            int res=SaveList(g_list[now],filename);//函数返回结果
            if(res==-1)//线性表未初始化
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(res==0)//找不到文件
            {
                cout<<"File doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else//保存成功
            {
                cout<<"Saved successfully!"<<endl;
                system("pause");
                return;
            }
        }
        if(op==20)//从文件加载线性表
        {
            cout<<"Input the filename: ";
            char filename[105];//文件名
            cin>>filename;
            int res=LoadList(g_list[now],filename);//函数返回结果
            if(res==-1)//线性表未初始化
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(!res)//文件为空
            {
                cout<<"File is empty!"<<endl;
                system("pause");
                return;
            }
            else//加载成功
            {
                cout<<"Successfully loaded!"<<endl;
                system("pause");
                return;
            }
        }
        if(op==21)//创建文件
        {
            cout<<"Input the filename: ";
            char filename[105];
            cin>>filename;
            char temp[] = "type NUL>";
            const char *command = strcat(temp,filename);
            system(command);
            cout<<"File created successfully!"<<endl;
            system("pause");
            return;
        }
    }
}

int main()
{
    while(1) run();
    
    system("pause");
    return 0;
}
