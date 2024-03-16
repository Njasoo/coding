import javax.swing.tree.TreePath;

/**
 * Runnable��ֻ����һ������run
 * Runnable ��һ���ӿ�
 * @override ������һ��ע�ͣ���Ϊ��ǩ�����ϱ�ǩ���������ͻ��鸸���Ƿ����������
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
        // ���������м����ʱ�򣬽���Ѵ�ӡ��������һ��
        thread1.start(); // �����߳����������run����
        thread2.start();
        thread3.start();
        // ���������д������޷�ʵ�ֲ��м����
        // printA.run();
        // printB.run();
        // print100.run();
    }
}

class PrintChar implements Runnable { // һ��������봴��Ϊһ��Runnable��ʵ��
    private char charToPrint;
    private int times;

    public PrintChar(char c, int t) {
        charToPrint = c;
        times = t;
    }

    @Override
    public void run() {
        // Ӧ�ð�ѭ������try�����棬����ʹ�̱߳��жϣ�ѭ��Ҳ���ܼ���ִ��
        try {
            for (int i = 0; i < times; i++) {
                System.out.print(charToPrint);
                // Thread.yield(); �߳���ͣ
                if (i >= 50) {
                    Thread.sleep(1); // �߳�����
                }
            }
        } catch(InterruptedException ie) {
            ie.printStackTrace();
        } // Thread.sleep���׳��쳣������дtry-catch statement
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