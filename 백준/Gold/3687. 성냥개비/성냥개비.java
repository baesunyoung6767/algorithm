
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static public BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    static public int T;
    static public long[] dp;
    static public int[] matches = {1, 7, 4, 2, 0, 8};

    static public void main(String[] args) throws Exception{
        T = Integer.parseInt(bf.readLine());

        dp = new long[101];
        Arrays.fill(dp, Long.MAX_VALUE);
        dp[2] = 1;
        dp[3] = 7;
        dp[4] = 4;
        dp[5] = 2;
        dp[6] = 6;
        dp[7] = 8;
        dp[8] = 10;

        for(int i = 9; i<101; i++) {
            for(int j = 2; j<=7; j++) {
                String temp = String.valueOf(dp[i - j]) + String.valueOf(matches[j - 2]);
                dp[i] = Math.min(dp[i], Long.parseLong(temp));
            }
        }

        for(int i = 1; i<=T; i++) {
            int cnt = Integer.parseInt(bf.readLine());
            String maxValue = "";
            System.out.print(dp[cnt] + " ");

            if(cnt % 2 == 0) {
                for(int k = 0; k<cnt/2; k++) {
                    maxValue += "1";
                }
            } else {
                maxValue += "7";
                for(int k = 0; k<cnt/2-1; k++) {
                    maxValue += "1";
                }
            }

            System.out.println(maxValue);
        }
    }
}
