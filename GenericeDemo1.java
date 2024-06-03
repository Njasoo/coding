public class GenericeDemo1 {
    public static void main(String[] args) {
        // System.out.println(GenericeDemo1.add(1, 2));
        System.out.println(GenericeDemo1.<Integer>add(1, 2));
    }

    public static <T> T add(T value1, T value2) {
        if (value1 instanceof Integer) {
            return (Integer)value1 + value2;
        }
        return null;
    }
}