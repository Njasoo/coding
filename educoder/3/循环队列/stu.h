//在下面的begin和end间填写相应代码
void iniQueue(QUEUE &Q)
//该函数实现初始化Q
{
/***************begin***************/
    Q.length=0;
    Q.front=0;

/*************** end ***************/
}
int enQueue(QUEUE &Q,ElemType e)
//将元素e入队Q。成功入栈返回1，否则返回0
{
/***************begin***************/
    if(Q.length==MAXLENGTH) return 0;
    Q.length++;
    Q.elem[(Q.front+Q.length-1)%MAXLENGTH]=e;
    return 1;

/*************** end ***************/
}
int deQueue(QUEUE &Q, ElemType &e)
//将Q队首元素出队，赋值给e。成功出队返回1，否则返回0
{
/***************begin***************/
    if(Q.length==0) return 0;
    Q.length--;
    e=Q.elem[Q.front++];
    Q.front%=MAXLENGTH;
    return e;

/*************** end ***************/
}
