import java.util.HashSet;

public class HashSetTest {
    public static void main(String[] args) {
        HashSet<String> hs = new HashSet<>();
        hs.add("Jason");
        hs.add("Tommy");
        System.out.println(hs.contains("Jason"));
        hs.remove("Jason");
        System.out.println(hs.contains("Jason"));
        hs.clear();
        System.out.println(hs);
    }
}