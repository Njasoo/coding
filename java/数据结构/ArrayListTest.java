/**
 * 泛型数据类型只能为引用数据类型(类)
 * 如果要存储基本数据类型，那么要使用它们的包装类
 * 排序函数用Collections头文件里面的sort(), 这个sort是对整个数组排序，我觉得应该有参数吧
 * 但不想去试了
*/
import java.util.ArrayList; 
import java.util.Collections;

public class ArrayListTest {
    public static void main(String[] args) {
        ArrayList<String> sites = new ArrayList<>(); // 后面的数据类型可以忽略
        // 添加元素
        sites.add("Jason");
        sites.add("Tommy");
        sites.add("Kuman");
        // 访问元素
        System.out.println(sites.get(1));
        // 修改元素
        sites.set(2, "KMH");
        System.out.println(sites.get(2));
        System.out.println(sites.size());
        // for each 语法遍历数组
        for (String s : sites) {
            System.out.println(s);
        }
        Collections.sort(sites);
        for (String s : sites) {
            System.out.println(s);
        }
    }
}