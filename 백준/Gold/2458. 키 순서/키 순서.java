import java.io.*;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M;
    public static boolean[][] map;
    public static int[] chk;

    public static void main(String args[]) throws Exception{
        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        map = new boolean[N + 1][N + 1];
        chk = new int[N + 1];

        for(int i = 0; i<M; i++) {
            String[] studentResult = bf.readLine().split(" ");
            int a = Integer.parseInt(studentResult[0]);
            int b = Integer.parseInt(studentResult[1]);
            map[a][b] = true;
        }

        for(int k = 1; k<=N; k++) {
            for(int i = 1; i<=N; i++) {
                for(int j = 1; j<=N; j++) {
                   if(map[i][k] && map[k][j]) map[i][j] = true;
                }
            }
        }

        for(int i = 1; i<=N; i++) {
            for(int j = 1; j<=N; j++) {
                if(map[i][j] || map[j][i]) chk[i]++;
            }
        }

        int result = 0;
        for(int i = 1; i<=N; i++) {
            if(chk[i] == N-1) result++;
        }

        System.out.println(result);
    }
}
