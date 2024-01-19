/**
 * some notes:
 * there can only be one class with the keyword public before it.
 * "this" is not a pointer in java, "this" is an object.
 * we use new to create a object, and java will help us to delete it, so we don't have to care about it.
**/
public class Puppy {
  String name; // the only attribute, if we don't use public before an variable, then the default is private(I think). the main() can access name, but I think it's bucause main() is inside the class

  public Puppy(String name) { // this is a constructor
//    this->name = name;
    this.name = name; // there is no pointers in java
    System.out.println("my name is " + name);
  }
  // so the main() is a function to test the class?
  public static void main(String[] args) { // main() in a class, which is very strange to me
    Puppy my_puppy = new Puppy("Jason"); // we use new to create a new object, but don't worry, java will cancel it automatically
    System.out.println("my_puppy.name = " + my_puppy.name);
  }
}