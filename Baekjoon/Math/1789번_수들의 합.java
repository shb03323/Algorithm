import java.util.*;

public class Main{
    public static int maxN(long x) {
        long sum = 0;
        int count = 0;

        while(sum <= x) {
            count++;
            sum += count;
        }

        return count - 1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long s = sc.nextLong();
        System.out.println(maxN(s));
    }
}
