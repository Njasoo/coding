int hp[N];
struct Heap{
    int size;

    Heap(){
        size=0;
    }

    void push(int x){
        hp[++size]=x;
        int now=size;
        while(now!=1 && hp[now]<hp[now/2]){
            swap(hp[now],hp[now/2]);
            now/=2;
        }
    }

    int pop(){
        int res=hp[1];
        hp[1]=hp[size];
        size--;
        int now=1;
        while(now*2<=size){
            if(now*2+1>size){
                if(hp[now]<=hp[now*2])break;
                swap(hp[now],hp[now*2]);
                now=now*2;
            }else{
                if(hp[now]<=hp[now*2] && hp[now]<=hp[now*2+1])break;
                if(hp[now*2]<hp[now*2+1]){
                    swap(hp[now],hp[now*2]);
                    now=now*2;
                }else{
                    swap(hp[now],hp[now*2+1]);
                    now=now*2+1;
                }
            }
        }
        return res;
    }

    bool empty(){
        return size==0;
    }
};