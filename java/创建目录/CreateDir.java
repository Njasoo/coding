/**
 * mkdirs(): 绝对路径，并且可以新创建多级目录
 * mkdir(): 相对路径，只能新创建一级目录，开头不能有斜杠
*/
import java.io.File;

public class CreateDir {
    public static void main(String[] args) {
        // String dirname = "/tmp/user/java/bin";
        String dirname = "test";
        File d = new File(dirname);
        // d.mkdirs();
        d.mkdir();
    }
}