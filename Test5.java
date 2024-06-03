public class Test5 {
    public static void main(String... args){
        C o1 = new D();  
        o1.m(1,1);             
        o1.m(1.0,1.0);         
        o1.m(1.0f, 1.0f);      
        ((D) o1).f();

        D o2 = new D();
        o2.m(1,1);         
        o2.m(1.0,1.0);     
        o2.m(1.0f, 1.0f);  
        o2.f();
    }
}

class C{
    public void m(int x, int y) {
        System.out.println("C's m(int,int)");
    }
    public void m(double x, double y) {
        System.out.println("C' m(double,double)");
    }
    public static void f() {
        System.out.println("fuck");
    }
}

class D extends C{
    public void m(float x, float y) {
        System.out.println("D's m(float,float)");
    }
    public void m(int x, int y)  {
        System.out.println("D's m(int,int)");
    }
    // public static void f() {
    //     System.out.println("hello");
    // }
}