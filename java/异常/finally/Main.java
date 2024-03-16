/**
 * finally关键字，无论异常是否被捕获，finally里面的语句都会被执行
*/
public class Main {
    public static void main(String[] args) {
        int[] a = new int[2];
        try {
            System.out.println(a[3]);
        } catch (ArrayIndexOutOfBoundsException e) {
            e.printStackTrace();
        } finally {
            a[0] = 6;
            System.out.println("final statement has been excuted");
        }
    }
}