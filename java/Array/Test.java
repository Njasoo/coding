/**
 * dataType[] newArray: this is the first choice
 * dataType newArray[]: is also ok
**/
public class Test {
  public static void main(String[] args) {
    int size = 10;
    int[] new_int_array = new int[size];
    int sum = 0;
    for (int i = 0; i < size; i++) {
      new_int_array[i] = i;
      sum += i;
    }
    System.out.println(sum);
  }
}