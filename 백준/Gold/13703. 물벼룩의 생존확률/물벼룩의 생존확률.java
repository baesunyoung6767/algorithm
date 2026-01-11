import java.io.*;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int K, N;
    public static int caseCnt, deadCnt;
    public static long[][] dp;

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");
        K = Integer.parseInt(input[0]);
        N = Integer.parseInt(input[1]);
        caseCnt = (int) Math.pow(2, N);
        dp = new long[63 + 1][63 * 2 + 1];
        
        jump(N, K);
        System.out.println(dp[N][K]);
    }

    public static long jump(int curN, int curK) {
        if(dp[curN][curK] != 0) return dp[curN][curK]; 

        if(curK == 0) return 0;
        else if(curN == 0) return 1;

        return dp[curN][curK] = jump(curN -1, curK - 1) + jump(curN - 1, curK + 1);
    } 
}
