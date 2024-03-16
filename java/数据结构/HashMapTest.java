import java.util.HashMap;

public class HashMapTest {
    public static void main(String[] args) {
        HashMap<String, String> hp = new HashMap<>();
        hp.put("one", "Google");
        hp.put("two", "Runoob");
        hp.put("three", "Taobao");
        hp.put("four", "Zhihu");
        System.out.println(hp);
        System.out.println(hp.get("one"));
        hp.remove("one");
        System.out.println(hp);
        hp.clear();
        System.out.println(hp);
    }
}