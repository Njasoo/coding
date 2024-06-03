import java.util.*;

public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int a = sc.nextInt(), b = sc.nextInt();
        if (a == b) {
            System.out.println("infinity");
            return;
        }       
        a -= b;
        Set<Integer> s = new HashSet<>();
        for (int i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                if (i > b) s.add(i);
                if (a / i > b) s.add(a / i);
            }
        }
        System.out.println(s.size());
    }
}