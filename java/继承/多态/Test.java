/**
 * 多态实例，父类引用指向子类
*/
public class Test {
    public static void main(String[] args) {
        show(new Cat());
        show(new Dog());
        Animal a = new Cat(); // 向上转型
        a.eat(); // 调用的是Cat的eat()
        Cat c = (Cat) a;
        c.work();
    }

    public static void show(Animal a) {
        a.eat();
        if (a instanceof Cat) {
            Cat c = (Cat) a;
            c.work();
        } else if (a instanceof Dog) {
            Dog c = (Dog) a;
            c.work();
        }
    }
}

abstract class Animal { // 抽象类
    abstract void eat();
}

class Cat extends Animal {
    public void eat() {
        System.out.println("吃鱼");
    }

    public void work() {
        System.out.println("抓老鼠");
    }
}

class Dog extends Animal {
    public void eat() {
        System.out.println("吃屎");
    }

    public void work() {
        System.out.println("看家");
    }
}