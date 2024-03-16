/**
 * 子类的无参构造会自动调用父类的无参构造，含参构造需要手动调用父类的构造函数
 * 定义了两个非公共类，一个java文件当中可以包含任意数量的非公共类，但是公共类只能有一个
 * 非公共类的访问范围为同一个java文件内
*/
class SuperClass {
    private int n;

    public SuperClass() {
        System.out.println("父类无参构造");
    }
    public SuperClass(int n) {
        this.n = n;
        System.out.println("父类含参构造");
    }
}

class SubClass extends SuperClass {
    public SubClass() {
        System.out.println("子类无参构造");
    }
    public SubClass(int n) {
        super(n);
        System.out.println("子类含参构造");
    }
}

public class SuperSubClassTest {
    public static void main(String[] args) {
        SubClass s1 = new SubClass();
        SubClass s2 = new SubClass(114514);
    }
}