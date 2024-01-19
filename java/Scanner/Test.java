/**
 * some notes~
 * for using Scanner, we have to import the header
**/
import java.util.Scanner;

public class Test {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in); // get data from cmd
    if (scan.hasNext()) {
      String str = scan.next(); // the return datatype is string
      System.out.println(str);
    }
  }
}