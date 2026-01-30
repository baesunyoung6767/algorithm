import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int R, C, T, SY, SX;
    public static char[][] farm;
    //public static int[][] visited;
    public static int[] x = {1, 0, -1, 0};
    public static int[] y = {0, -1, 0, 1};
    public static int result;
    
    public static void main(String[] args) throws Exception{
        String[] data = bf.readLine().split(" ");
        R = Integer.parseInt(data[0]); 
        C = Integer.parseInt(data[1]); 
        T = Integer.parseInt(data[2]);

        farm = new char[R + 1][C + 1];
        //visited = new int[R + 1][C + 1];

        for(int i = 0; i<R; i++) {
            String input = bf.readLine();
            for(int j = 0; j<C; j++) {
                farm[i][j] = input.charAt(j);
                if(farm[i][j] == 'G') {
                    SY = i;
                    SX = j;
                }
            }
        }

        //visited[SY][SX] = 1;
        farm[SY][SX] = '.';
        find(SY, SX, 0, 0);
        System.out.println(result);
    }

    public static void find(int cy, int cx, int time, int cnt) {
        if(time >= T) {
            result = Math.max(result, cnt);
            return;
        }

        for(int i = 0; i<4; i++) {
            int ny = cy + y[i];
            int nx = cx + x[i];

            if(ny < 0 || ny >R || nx < 0 || ny > C) continue;
            if(farm[ny][nx] == '#') continue;
            if(farm[ny][nx] == 'S') {
                farm[ny][nx] = '.';
                //visited[ny][nx] = 1;
                find(ny, nx, time + 1, cnt + 1);
                //visited[ny][nx] = 0;
                farm[ny][nx] = 'S';
            }
            if(farm[ny][nx] == '.') {
                //visited[ny][nx] = 1;
                find(ny, nx, time + 1, cnt);
                //visited[ny][nx] = 0;
            }
        }
    }
}
