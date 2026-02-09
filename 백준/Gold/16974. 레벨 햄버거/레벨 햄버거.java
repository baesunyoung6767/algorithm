import java.io.BufferedReader;
import java.io.InputStreamReader;

// B / (L-1) / P / (L-1) / B
public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N;
    public static long X;
    public static long buggers[];
    public static long patties[];

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        X = Long.parseLong(input[1]);

        buggers = new long[N + 1];
        patties = new long[N + 1];

        buggers[0] = 1;
        patties[0] = 1;

        for(int i = 1; i<=N; i++) {
            buggers[i] = buggers[i - 1] * 2 + 3;
            patties[i] = patties[i - 1] * 2 + 1;
        }

        long ans = dp(N, X);
        System.out.println(ans);
    }

    public static long dp(int n, long x) {
        if(n == 0) {
            if(x == 0) {
                return 0;
            }
            else {
                return 1;
            }
        }

        if(x == 1) {
            return 0;
        }
        else if(x == buggers[n - 1] + 2) {
            return patties[n - 1] + 1;
        }
        else if(x <= buggers[n - 1] + 1) {
            return dp(n - 1, x - 1);
        }
        else if(x <= buggers[n - 1] * 2 + 3) {
            return patties[n - 1] + 1 + dp(n - 1, x - buggers[n-1] - 2);
        } else {
            return patties[n - 1] * 2 + 1;
        }
    }
}
