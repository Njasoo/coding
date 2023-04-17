#include "def.h"
#include "functions.h"

int num_list,now;
const int N=105;
SqList g_list[N];

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
    cout<<"-----------------------------------------------------------------"<<endl;
    cout<<"Please input number [1~14] to operate the list: ";
    int op;
    cin>>op;
    if(op<1 || op>14)
    {
        cout<<"Invalid input!"<<endl;
        cout<<"Please input again!"<<endl; 
        Sleep(1000); 
    }
    else
    {
        if(op==1)
        {
            flag1:
            if(InitList(g_list[now])==-1)
            {
                cout<<"Initialization failed!"<<endl;
                cout<<"Don't initialize the list repeatly!"<<endl<<endl;
                system("pause");
                return;
            }
            cout<<"Input the name of the list: "<<endl;
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
                cout<<"The name has been used!"<<endl<<endl; 
                goto flag1;
            }
            else
            {
                num_list++;
                InitList(g_list[now]);
                g_list[now].name=name;
                cout<<"\"" <<name<<"\"has been initialized successfully!"<<endl<<endl; 
                system("pause");
            }
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
            cout<<"Input the index of the element: ";
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
                    cout<<"the" <<index<<"-th element is"<<elem<<"."<<endl;
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
            
        }
        if(op==9)
        {
            
        }
        if(op==10)
        {
            
        }
        if(op==11)
        {
            
        }
        if(op==12)
        {
            
        }
        if(op==13)
        {
            
        }
    }
}

int main()
{
    while(1) run();
    
    system("pause");
    return 0;
}
