import java.util.*;

class ComparableTuple<X extends Comparable<? super X>, Y extends Comparable<? super Y>>
       extends Tuple<X, Y>
       implements Comparable<ComparableTuple<X, Y>>
{
  public ComparableTuple(X x, Y y) {
    super(x, y);
  }


  public int compareTo(ComparableTuple<X, Y> other) {
    int d = this.x.compareTo(other.x);
    if (d == 0)
      return this.y.compareTo(other.y);
    return d;
  }
}

public class Test {
    public static void main(String[] args) {
        // ComparableTuple t1 = new Comparable=
    }
}
