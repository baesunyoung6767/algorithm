import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static int N;
    public static int result;
    public static int[][] map;
    public static int[][] dp;
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws Exception{
        N = Integer.parseInt(bf.readLine());
        map = new int[N + 1][3];
        dp = new int[N + 1][3];
        result = Integer.MAX_VALUE;

        for(int i = 1; i<=N; i++) {
            String[] input = bf.readLine().split(" ");
            for(int j = 0; j<3; j++) {
                map[i][j] = Integer.parseInt(input[j]);
            }
        }

        for(int c = 0; c<3; c++) {
            for(int i = 0; i<3; i++) {
                if(i == c) dp[1][i] = map[1][i];
                else dp[1][i] = 987654321;
            }

            for(int i = 2; i<=N; i++) {
                dp[i][0] = Math.min(dp[i - 1][1] + map[i][0], dp[i-1][2] + map[i][0]);
                dp[i][1] = Math.min(dp[i - 1][0] + map[i][1], dp[i-1][2] + map[i][1]);
                dp[i][2] = Math.min(dp[i - 1][0] + map[i][2], dp[i-1][1] + map[i][2]);
            }

            for(int i = 0; i<3; i++) {
                if(i != c) result = Math.min(result, dp[N][i]);
            }
        }
        System.out.println(result);
    }
}
