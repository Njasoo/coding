/**
 * some notes~
 * StringBuffer is just like String, the difference between is related to engineering.
 * is like the difference between array and vector maybe.
**/
public class Test {
  public static void main(String[] args) {
    StringBuffer sBuffer = new StringBuffer("url: ");
    sBuffer.append("jable.tv");
    System.out.println(sBuffer);
  }
}