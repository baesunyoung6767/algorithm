import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int T, N;
    public static int[] files;
    public static int[][] dp;

    public static void main(String[] args) throws Exception{
        T = Integer.parseInt(bf.readLine());

        for(int t = 0; t<T; t++) {
            N = Integer.parseInt(bf.readLine());
            dp = new int[N+1][N+1];
            files = new int[N+1];

            String[] input = bf.readLine().split(" ");
            files[1] = Integer.parseInt(input[0]);
            for(int i = 2; i<=N; i++) {
                files[i] = Integer.parseInt(input[i - 1]) + files[i-1];
            }

            for(int gap = 1; gap<N; gap++) {
                for(int start = 1; start+gap<=N; start++) {
                    int end = start + gap;
                    dp[start][end] = Integer.MAX_VALUE;

                    for(int mid = start; mid<end; mid++) {
                        dp[start][end] = Math.min(dp[start][end], dp[start][mid] + dp[mid+1][end] + (files[end]-files[start-1]));
                    }
                }
            }

            System.out.println(dp[1][N]);
        }
    }
}
