import java.io.*;
import java.util.*;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N;
    public static int[] point;
    public static int[][] R;
    public static int me;
    public static int result;
    public static boolean[] isDead;

    public static void main(String[] args) throws Exception{
        N = Integer.parseInt(bf.readLine());
        R = new int[N + 1][N + 1];
        isDead = new boolean[N + 1];
        point = new int[N + 1];

        String[] temp = bf.readLine().split(" ");
        for(int i = 0; i<N; i++) {
           point[i] = Integer.parseInt(temp[i]);
        }

        for(int i = 0; i<N; i++) {
            String[] input = bf.readLine().split(" ");
            for(int j = 0; j<N; j++) {
                R[i][j] = Integer.parseInt(input[j]);
            }
        }

        me = Integer.parseInt(bf.readLine());

        result = -987654321;
        playGame(N, 0);
        System.out.println(result);
    }

    public static void playGame(int depth, int count) {
        if(isDead[me] || depth == 1) {
            result = Math.max(result, count);
            return;
        }

        if(depth % 2 == 0) {
            for(int i = 0; i<N; i++) {
                if(isDead[i]) continue;

                isDead[i] = true;
                for(int j = 0; j<N; j++) {
                    if(!isDead[j]) point[j] += R[i][j];
                }

                playGame(depth - 1, count + 1);

                for(int j = 0; j<N; j++) {
                    if(!isDead[j]) point[j] -= R[i][j];
                }
                isDead[i] = false;
            }
        }
        else {
            int targetIdx = -1;
            int maxPoint = -1;

            for(int i = 0; i<N; i++) {
                if(!isDead[i] && maxPoint < point[i]) {
                    targetIdx = i;
                    maxPoint = point[i];
                }
            }

            isDead[targetIdx] = true;
            playGame(depth - 1, count);
            isDead[targetIdx] = false;
        }
    }
}
