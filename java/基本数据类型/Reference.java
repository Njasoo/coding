/**
 * some notes.
 * int is passed by value, class is passed by reference.
 * so if we want to swap two value, we can group the variables into a class, then swap the attributes. Which is pretty annoying
**/
public class Reference {
  private int a, b;

  public Reference(int a, int b) {
    this.a = a;
    this.b = b;
  }
  public static void swap(Reference obj) {
    int tmp = obj.a;
    obj.a = obj.b;
    obj.b = tmp;
  }
  public static void main(String[] args) {
    int a = 10, b = 20;
    Reference obj = new Reference(a, b);
    System.out.printf("before swap: obj.a = %d, obj.b = %d\n", obj.a, obj.b);
    swap(obj);
    System.out.printf("after swap: obj.a = %d, obj.b = %d\n", obj.a, obj.b);
  }
}