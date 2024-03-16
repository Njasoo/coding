/**
 * read()：功能同getchar()
 * IOException：读写异常
*/
import java.io.*;

public class BRRead {
    public static void main(String[] args) throws IOException {
        char c;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("输入字符，按下q键退出");
        do {
            c = (char) br.read();
            System.out.println(c);
        } while (c != 'q');
    }
}