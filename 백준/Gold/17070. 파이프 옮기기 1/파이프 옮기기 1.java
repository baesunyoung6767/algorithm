

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    private static StringBuilder sb = new StringBuilder();
    private static int N;
    private static int[][] map;
    private static int[] x = {1, 0, 1}; // 가로 세로 대각선으로 이동
    private static int[] y = {0, 1, 1}; 
    private static int result = 0;

    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(in.readLine());
        map = new int[N][N];

        for(int i = 0; i<N; i++) {
            String[] tmp = in.readLine().split(" ");
            for(int j = 0; j<N; j++) {
                map[i][j] = Integer.parseInt(tmp[j]);
            }
        }

        movePipe(0, 1, 0);
        sb.append(result + "\n");
        System.out.println(sb);
    }
    private static void movePipe(int startY, int startX, int dir) { // 0 : 가로, 1 : 세로, 2 : 대각선
        if(startY == N-1 && startX == N-1) {
            result++;
            return;
        }

        for(int i = 0; i<3; i++) { // 가로, 세로, 대각선
            if((dir == 0 && i == 1) || (dir == 1 && i == 0)) continue;

            int ny = startY + y[i];
            int nx = startX + x[i];

            // 범위 안 벗어나는지 확인, 벽 체크
            if(ny >= N || nx >= N || map[ny][nx] == 1) continue;
            if(i == 2) {
                if(map[ny-1][nx] == 1 || map[ny][nx-1] == 1) continue;
            }
            movePipe(ny, nx, i);
        }
    }
}