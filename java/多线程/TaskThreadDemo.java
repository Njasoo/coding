import javax.swing.tree.TreePath;

/**
 * Runnable类只包含一个方法run
 * Runnable 是一个接口
 * @override 类似于一个注释，称为标签，加上标签，编译器就会检查父类是否有这个方法
*/

public class TaskThreadDemo {
    public static void main(String[] args) {
        // create task
        Runnable printA = new PrintChar('a', 100);
        Runnable printB = new PrintChar('b', 100);
        Runnable print100 = new PrintNum(100);
        // create thread
        Thread thread1 = new Thread(printA);
        Thread thread2 = new Thread(printB);
        Thread thread3 = new Thread(print100);
        // start threads
        // 看不到并行计算的时候，建议把打印个数调多一点
        thread1.start(); // 调用线程里面任务的run方法
        thread2.start();
        thread3.start();
        // 下面这三行代码是无法实现并行计算的
        // printA.run();
        // printB.run();
        // print100.run();
    }
}

class PrintChar implements Runnable { // 一个任务必须创建为一个Runnable的实例
    private char charToPrint;
    private int times;

    public PrintChar(char c, int t) {
        charToPrint = c;
        times = t;
    }

    @Override
    public void run() {
        // 应该把循环放在try块里面，否则即使线程被中断，循环也可能继续执行
        try {
            for (int i = 0; i < times; i++) {
                System.out.print(charToPrint);
                // Thread.yield(); 线程暂停
                if (i >= 50) {
                    Thread.sleep(1); // 线程休眠
                }
            }
        } catch(InterruptedException ie) {
            ie.printStackTrace();
        } // Thread.sleep会抛出异常，必须写try-catch statement
    }
}

class PrintNum implements Runnable {
    private int lastNum;

    public PrintNum(int n) {
        lastNum = n;
    }

    @Override
    public void run() {
        Thread thread4 = new Thread(new PrintChar('c', 40));
        thread4.start();
        try {
            for (int i = 1; i <= lastNum; i++) {
                System.out.print(" " + i);
                if (i == 50) thread4.join();
            }
        } catch(InterruptedException ie) {
            ie.printStackTrace();;
        }
    }
}