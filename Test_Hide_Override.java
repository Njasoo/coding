public class Test_Hide_Override {
    public static void main(String... args){
        A o = new C();
        o.m1();         
        o.m2();         
        ((B)o).m1();        
        ((A)(B)o).m1();     
        ((A)(B)o).m2();     
    }
}

class A{
    public static void m1(){  System.out.println("A's m1"); }
    public void m2(){ System.out.println("A's m2"); }
}

class B extends A{
    public static void m1(){  System.out.println("B's m1"); }
    public void m2(){ System.out.println("B's m2"); }
}

class C extends B{
    public static void m1(){  System.out.println("C's m1"); }
    public void m2(){ System.out.println("C's m2"); }
}