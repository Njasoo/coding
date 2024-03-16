/**
 * private属性和方法无法被访问，也无法被继承
*/
public class Penguin extends Animal {
    public Penguin(String name, int id) {
        super(name, id); // 调用父类的构造函数
    }

    public static void main(String[] args) {
        Penguin pg = new Penguin("Jason", 18);
        pg.introduction();
    }
}