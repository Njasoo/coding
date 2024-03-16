/**
 * 数字是二进制写入的，所以test文件是乱码的
 * InputStream是一个抽象类，FileInputStream是它的实现类
*/
import java.io.*;

public class FileStreamTest {
    public static void main(String[] args) {
        try {
            byte bWrite[] = { 11, 21, 3, 40, 5 };
            OutputStream os = new FileOutputStream("test.txt");
            for (int i = 0; i < bWrite.length; i++) {
                os.write(bWrite[i]);
            }
            os.close();
            InputStream is = new FileInputStream("test.txt");
            int size = is.available(); // 缓冲区大小
            for (int i = 0; i < size; i++) {
                System.out.print((char) is.read() + " ");
            }
            is.close();
        } catch (IOException e) {
            System.out.println("Exception");
        }
    }
}