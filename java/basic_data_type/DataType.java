/**
 * some notes.
 * byte is like the char in c/c++. Its range is [-2^7, 2^7)
 * there is no long long in java. Its new name is long
 * the char in java is much stronger than in c/c++. Its range is [0, 2^16-1]
**/
public class DataType {
  public static void main(String[] args) { // can we don't have this parameter, it's annoying
    // byte
    System.out.println("Byte.SIZE = " + Byte.SIZE);
    System.out.println("Byte.MIN_VALUE = " + Byte.MIN_VALUE);
    System.out.println("Byte.MAX_VALUE = " + Byte.MAX_VALUE);
    System.out.println(); // don't pass parameter is also ok
    // short
    System.out.println("Short.SIZE = " + Short.SIZE);
    System.out.println("Short.MIN_VALUE = " + Short.MIN_VALUE);
    System.out.println("Short.MAX_VALUE = " + Short.MAX_VALUE);
    System.out.println();
    // int
    System.out.println("Integer.SIZE = " + Integer.SIZE);
    System.out.println("Integer.MIN_VALUE = " + Integer.MIN_VALUE);
    System.out.println("Integer.MAX_VALUE = " + Integer.MAX_VALUE);
    System.out.println();
    // long
    System.out.println("Long.SIZE = " + Long.SIZE);
    System.out.println("Long.MIN_VALUE = " + Long.MIN_VALUE);
    System.out.println("Long.MAX_VALUE = " + Long.MAX_VALUE);
    System.out.println();
    // don't want to type anymore
  }
}