public class Main {
    public static void main(String[] args) {
        int num = 0;
        checkNumber(num);
    }

    public static void checkNumber(int num) {
        if (num <= 0) {
            throw new IllegalArgumentException("Number must be positive!");
        }
    }
}