import java.io.*;

public class ExcepTest {
    public static void main(String[] args) {
        try {
            int[] a = new int[2];
            System.out.println(a[3]);
        } catch (ArrayIndexOutOfBoundsException e) {
            // System.out.println("Array out of bounds");
            e.printStackTrace(); // 打印报错信息
        }
    }
}