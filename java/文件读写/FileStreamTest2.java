/**
 * 这个类展示了如何正确地避免乱码的文件读写操作
 * 文件close的顺序入栈的顺序类似入栈的顺序，先开后关
 * 
 * 将文件转换成流对象，然后使用输出流写入，输入流读入
*/
import java.io.*;

public class FileStreamTest2 {
    public static void main(String[] args) throws IOException {
        File f = new File("a.txt");
        FileOutputStream fop = new FileOutputStream(f);
        OutputStreamWriter writer = new OutputStreamWriter(fop, "UTF-8"); // 默认为系统默认编码，windows就是GBK
        writer.append("中文输入"); // 加入到缓冲区
        writer.append("\r\n"); // \r表示换到当前行的开头位置
        writer.append("English");
        writer.close();
        fop.close();
        FileInputStream fip = new FileInputStream(f);
        InputStreamReader reader = new InputStreamReader(fip, "UTF-8");
        StringBuffer sb = new StringBuffer();
        while (reader.ready()) { // 有读到东西的意思
            sb.append((char) reader.read());
        }
        System.out.println(sb.toString());
        reader.close();
        fip.close();
    }
}