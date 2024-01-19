public class StringTest {
  public static void main(String[] args) {
    String fs = String.format("Jason is %d years Old", 18);
    System.out.println(fs);
    fs += '.';
    System.out.println(fs);
  }
}