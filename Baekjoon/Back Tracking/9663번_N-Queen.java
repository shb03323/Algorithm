import java.util.*;

public class Main {
    Scanner sc = new Scanner(System.in);
    public static int n;
    public static int[] row;
    public static int answer;

    public static boolean check(int x) {
        for(int i = 0; i < x; i++) {
            if(row[i] == row[x] || Math.abs(row[x] - row[i]) == x - i) {
                return false;
            }
        }

        return true;
    }

    public static void dfs(int x) {
        if(x == n) {
            answer += 1;
        }
        else {
            for(int i = 0; i < n; i++) {
                row[x] = i;
                if(check(x)){
                    dfs(x + 1);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        row = new int[n];

        for(int i = 0; i < n; i++){
            row[i] = 0;
        }

        dfs(0);
        System.out.println(answer);
    }
}
