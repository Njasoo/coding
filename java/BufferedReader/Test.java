import java.io.*;

public class Test {
  public static void main(String[] args) throws IOException { // have some problem while reading stream
    char c;
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    System.out.println("input q to exit.");
    while (true) {
      c = (char)br.read(); // read a single char
      if (c == 'q') break;
    }
  }
}