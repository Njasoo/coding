class DSU{
    private ArrayList<Integer> f=new ArrayList<>();
    private int n;

    public DSU(int n){
        this.n=n;
        this.f.add(0);
        for(int i=1;i<=n;i++){
            this.f.add(i);
        }
    }

    public int find(int x){
        if(x==this.f.get(x)){
            return x;
        }
        int res=this.find(this.f.get(x));
        this.f.set(x,res);
        return res;
    }

    public void merge(int x,int y){
        x=this.find(x);
        y=this.find(y);
        if(x==y) return;
        this.f.set(y,x);
    }

    public boolean same(int x,int y){
        x=this.find(x);
        y=this.find(y);
        return (x==y);
    }
};