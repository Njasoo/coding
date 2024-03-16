/**
 * some notes.
 * static variable is shared by all the objects in the same class.
 * you can access it by class name.
 * and you can also access it by the object's name.
 * it's just like global variable, it alives until the program end.
**/
public class StaticVariable {
  public static int count;

  public static void main(String[] args) {
    StaticVariable obj = new StaticVariable();
    StaticVariable.count = 10;
    System.out.println("StaticVariable.count = " + StaticVariable.count);
    obj.count = 20;
    System.out.println("obj.count = " + obj.count);
  }
}