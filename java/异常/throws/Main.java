/**
 * throws关键字用在函数，表示函数在被调用时可能抛出的异常
 * 亦可以抛出多个异常，用逗号隔开
*/
import java.io.*;

public class Main {
    public void readFile(String filePath) throws IOException {
        BufferedReader reader = new BufferedReader(new FileReader(filePath));
        String line = reader.readLine();
        while (line != null) {
            System.out.println(line);
            line = reader.readLine();
        }
        reader.close();
    }
}