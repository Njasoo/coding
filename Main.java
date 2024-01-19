import java.util.Scanner;
import java.util.Arrays;

public class Main{
    static Scanner sc=new Scanner(System.in);
    public static void main(String[] args){
        int n=sc.nextInt();
        for(int i=1;i<=n;i++){
            a[i]=sc.nextInt();
        }
        Arrays.sort(a,1,1+n);
    }
}