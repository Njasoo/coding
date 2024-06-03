public class Test2_16 {
    public void m1() throws RuntimeException{
        throw new RuntimeException();
    }
    

    public void m2(){
        m1();
    }
}