import java.util.List;
import java.util.ArrayList;

class A {}
class B extends A {}
class C extends B {}
class D extends C {}
public class Test2_9{
    public static void main(String[] args) {
List<D> l9 = new ArrayList<> ();
List<C> l10 = new ArrayList<> ();
Test2_9.m (l9, l10);




    }
    public static <T> void m (List<? super T> list1, List<? extends T> list2) {}
}
