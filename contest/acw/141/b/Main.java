import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans = (int) 1e9;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int cnt = a + (i - a % n + n) % n;
            ans = Math.min(ans, cnt);
        }
        System.out.println(ans % n + 1);
    }
}