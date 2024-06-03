public class Test2 {
    public static void main(String[] args){
        int[] a = {1};
        String[] s = {"Hello"};
        int i = a[0];
        m(s,a,i);
        for(String v:s){
            System.out.println(v);
        }
        for(int v:a){
            System.out.println(v);
        }
        System.out.println(i);
    }
    public static void m(String[] a1, int[] a2, int i){
        for(int j =0; j < a1.length;j++){
            a1[j] = "Java";
        }
        for(int j =0; j < a2.length;j++){
            a2[j]++;
        }
        i++;
    }
}