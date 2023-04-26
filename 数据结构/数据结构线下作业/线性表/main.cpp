#include "def.h"
#include "functions.h"

int num_list,now=1;
const int N=105;
SqList g_list[N];
int num_op=21;

void run()
{
    system("cls");
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"\t1. Init List\t\t\t2. Destroy List"<<endl;
    cout<<"\t3. Clear List\t\t\t4. List Empty"<<endl;
    cout<<"\t5. List Length\t\t\t6. Get Element"<<endl;
    cout<<"\t7. Locate Element\t\t8. Prior Element"<<endl;
    cout<<"\t9. Next Element\t\t\t10. List Insert"<<endl;
    cout<<"\t11. Delete Element\t\t12. List Travese"<<endl; 
    cout<<"\t13. List Shift\t\t\t14. Create New List"<<endl; 
    cout<<"\t15. Show All List\t\t16. Max Subarray"<<endl;
    cout<<"\t17. SubArrayNum\t\t\t18. Sort List"<<endl;
    cout<<"\t19. Save List to File\t\t20. load List from File"<<endl;
    cout<<"\t21. Create File"<<endl;
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"Please input number [1~"<<num_op<<"] to operate the list: ";
    int op;
    cin>>op;
    if(op<1 || op>num_op)
    {
        cout<<"Invalid input!"<<endl;
        cout<<"Please input again!"<<endl; 
        system("pause");
        return;
    }
    else
    {
        if(op==1)
        {
            if(num_list==0)
            {
                cout<<"There is no list!"<<endl;
                system("pause");
                return;
            }
            int res=InitList(g_list[now]);
            if(res==-1)
            {
                cout<<"The list has already been initialized!"<<endl;
                system("pause");
                return;
            }
            cout<<"Input the name of the list: ";
            string name;
            cin>>name;
            bool used=0;
            for(int i=0;i<num_list;i++)
            {
                if(g_list[i].name==name)
                {
                    used=1;
                    break;
                }
            }
            if(used)
            {
                cout<<"The name has been used!"<<endl;
                system("pause");
                return;
            }
            g_list[now].name=name;
            cout<<"List initialized successfully!"<<endl;
            cout<<"List name: "<<g_list[now].name<<endl;
            cout<<"id: "<<now<<endl;
            system("pause");
            return;
        }
        if(op==2)
        {
            if(DestroyList(g_list[now])==-1)
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
        if(op==3)
        {
            if(ClearList(g_list[now])==-1)
            {
                cout<<"Invalid operation!"<<endl;
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else
            {
                cout<<"The list is empty now!"<<endl;
                system("pause");
            }
        }
        if(op==4)
        {
            int res=ListEmpty(g_list[now]);//避免重复调用函数
            if(res==-1)
            {
                cout<<"Invalid operation!"<<endl;
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else
            {
                if(res==1) cout<<"The list is empty."<<endl;
                if(res==0) cout<<"The list isn't empty."<<endl;
                system("pause");
            }
        }
        if(op==5)
        {
            int res=ListLength(g_list[now]);
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
        if(op==6)
        {
            cout<<"Input the index of the element(start from 1): ";
            int index;
            cin>>index;
            int elem;   
            int res=GetElem(g_list[now],index,elem);
            if(res==-1)
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else
            {
                if(res==ERROR)
                {
                    cout<<"Index out of bounds!"<<endl;
                    system("pause");
                    return;
                }
                else
                {
                    cout<<"the "<<index<<"-th element is "<<elem<<"."<<endl;
                    system("pause");
                    return;
                }
            }
        }
        if(op==7)
        {
            cout<<"Input the element: ";
            int elem;
            cin>>elem;
            int res=LocateElem(g_list[now],elem);
            if(res==-1)
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else
            {
                if(!res)
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
        if(op==8)
        {
            cout<<"Input the element to find its prior: ";
            int elem;
            cin>>elem;
            int pre;
            int res=PriorElem(g_list[now],elem,pre);
            if(res==-1)
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(!res)
            {
                cout<<"Can't find the prior!"<<endl;
                system("pause");
                return;
            }
            else
            {
                cout<<"The prior of "<<elem<<" is "<<" "<<pre<<"."<<endl;
                system("pause");
                return;
            }
        }
        if(op==9)
        {
            cout<<"Input the element to find its next element: ";
            int elem;
            cin>>elem;
            int nex;
            int res=NextElem(g_list[now],elem,nex);
            if(res==-1)
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(!res)
            {
                cout<<"Can't find the next element!"<<endl;
                system("pause");
                return;
            }
            else
            {
                cout<<"The prior of "<<elem<<" is "<<nex<<"."<<endl;
                system("pause");
                return;
            }
        }
        if(op==10)
        {
            cout<<"Input the position that you want to insert at: ";
            int pos;
            cin>>pos;
            cout<<"Input the element that you want to insert: ";
            int elem;
            cin>>elem;
            int res=ListInsert(g_list[now],pos,elem);
            if(res==-1)
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(res==0)
            {
                cout<<"Invalid position!"<<endl;
                system("pause");
                return;
            }
            else
            {
                cout<<"Insertion complete!"<<endl;
                system("pause");
                return;
            }
        }
        if(op==11)
        {
            cout<<"Input the position: "<<endl;
            int pos;
            cin>>pos;
            int elem;
            int res=ListDelete(g_list[now],pos,elem);
            if(res==-1)
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(!res)
            {
                cout<<"Invalid position!"<<endl;
                system("pause");
                return;
            }
            else
            {
                cout<<"The "<<pos<<"-th element is "<<elem<<".";
                cout<<"It has been deleted!"<<endl;
                system("pause");
                return;
            }
        }
        if(op==12)
        {
            int res=ListTraverse(g_list[now]);
            if(res==-1)
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(!res)
            {
                cout<<"The list is empty!"<<endl;
            }
            cout<<"Traverse successfully!"<<endl;
            system("pause");
            return;
        }
        if(op==13)
        {
            cout<<"Input the id to switch the list: ";
            int id;
            cin>>id;
            if(id<=0 || id>num_list)
            {
                cout<<"id out of range!"<<endl;
                system("pause");
                return;
            }
            else
            {
                now=id;
                cout<<"List switched successfully!"<<endl;
                if(g_list[now].name=="") cout<<"[no name yet]"<<endl;
                else cout<<"List name: "<<g_list[now].name<<endl;
                system("pause");
                return;
            }
        }
        if(op==14)
        {
            num_list++;
            cout<<"A new list has been created!"<<endl;
            system("pause");
            return;
        }
        if(op==15)
        {
            if(num_list==0)
            {
                cout<<"There is no list!"<<endl;
                system("pause");
                return;
            }
            for(int i=1;i<=num_list;i++)
            {
                if(g_list[i].name=="")
                {
                    cout<<"id: "<<i<<" "<<"name: "<<"[no name yet]"<<endl;
                }
                else
                {
                    cout<<"id: "<<i<<" "<<"name: "<<g_list[i].name<<endl;
                }
            }
            system("pause");
        }
        if(op==16)
        {
            int res=MaxSubArray(g_list[now]);
            if(res==-1)
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(!res)
            {
                cout<<"The list is empty!"<<endl;
                system("pause");
                return;
            }
            system("pause");
            return;
        }
        if(op==17)
        {
            int res=SubArrayNum(g_list[now]);
            if(res==-1)
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(res==0)
            {
                cout<<"The list is empty!"<<endl;
                system("pause");
                return;
            }
            system("pause");
            return;
        }
        if(op==18)
        {
            int res=sortList(g_list[now]);
            if(res==-1)
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else
            {
                cout<<"The list has been sorted!"<<endl;
                system("pause");
                return;
            }
        }
        if(op==19)
        {
            cout<<"Input the filename that you want to save the list to: ";
            char filename[105];
            cin>>filename;
            int res=SaveList(g_list[now],filename);
            if(res==-1)
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(res==0)
            {
                cout<<"File doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else
            {
                cout<<"Saved successfully!"<<endl;
                system("pause");
                return;
            }
        }
        if(op==20)
        {
            cout<<"Input the filename: ";
            char filename[105];
            cin>>filename;
            int res=LoadList(g_list[now],filename);
            if(res==-1)
            {
                cout<<"The list doesn't exist!"<<endl;
                system("pause");
                return;
            }
            else if(!res)
            {
                cout<<"File is empty!"<<endl;
                system("pause");
                return;
            }
            else
            {
                cout<<"Successfully loaded!"<<endl;
                system("pause");
                return;
            }
        }
        if(op==21)
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
