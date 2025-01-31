import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M;
    public static int[][] map;

    public static void main(String[] args) throws Exception{
        N = Integer.parseInt(bf.readLine());
        M = Integer.parseInt(bf.readLine());
        map = new int[N + 1][N + 1];

        for(int i = 1; i<=N; i++) {
            for(int j = 1; j<=N; j++) {
                if(i == j) map[i][j] = 0;
                else map[i][j] = 987654321;
            }
        }

        int start, end, cost;
        for(int i = 0; i<M; i++) {
            String[] input = bf.readLine().split(" ");
            start = Integer.parseInt(input[0]);
            end = Integer.parseInt(input[1]);
            cost = Integer.parseInt(input[2]);

            if(map[start][end] > cost) map[start][end] = cost;
        }

        for(int k = 1; k<=N; k++) {
            for(int i = 1; i<=N; i++) {
                for(int j = 1; j<=N; j++) {
                    if(i == j) continue;
                    map[i][j] = Math.min(map[i][j], map[i][k] + map[k][j]);
                }
            }
        }

        for(int i = 1; i<=N; i++) {
            for(int j = 1; j<=N; j++) {
                if(map[i][j] == 987654321) System.out.print(0);
                else System.out.print(map[i][j]);

                if(j == N) System.out.print("\n");
                else System.out.print(" ");
            }
        }
    }
}
