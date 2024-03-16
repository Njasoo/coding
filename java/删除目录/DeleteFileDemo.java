/**
 * 删除一个文件夹的方法，就把里面的文件全部删掉包括所有子目录的文件
 * 这个过程可以由DFS来实现
*/
import java.io.File;

public class DeleteFileDemo {
    public static void main(String[] args) {
        File folder = new File("tmp/user");
        deleteFolder(folder);
    }

    public static void deleteFolder(File folder) {
        File[] files = folder.listFiles();
        if (files != null) { // 这个有必要判断吗，答案是很有必要
            for (File f : files) {
                if (f.isDirectory()) {
                    deleteFolder(f);
                } else {
                    f.delete();
                }
            }
        }
        folder.delete();
    }
}