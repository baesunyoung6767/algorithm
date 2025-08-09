import java.io.*;
import java.util.*;

public class Main {
    public static class info {
        int curY;
        int curX;
        int curPower;
        int curUmb;
        int cnt;

        public info(int curY, int curX, int curPower, int curUmb, int cnt) {
            this.curY = curY;
            this.curX = curX;
            this.curPower = curPower;
            this.curUmb = curUmb;
            this.cnt = cnt;
        }
    }
    
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, H, D;
    public static char[][] map;
    public static int startX, startY;
    public static int result;
    public static int[] x = {-1, 0, 1, 0};
    public static int[] y = {0, -1, 0, 1};
    public static int[][] visited;

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        H = Integer.parseInt(input[1]);
        D = Integer.parseInt(input[2]);
        map = new char[N + 1][N + 1];
        visited = new int[N + 1][N + 1];

        for(int i = 0; i<N; i++) {
            String mapData = bf.readLine();
            for(int j = 0; j<N; j++) {
                map[i][j] = mapData.charAt(j);
                if(map[i][j] == 'S') {
                    startY = i;
                    startX = j;
                }
            }  
        }

        result = 987654321;
        walk();
        if(result == 987654321) {
            System.out.println(-1);
        }else {
            System.out.println(result);
        }
    }

    public static void walk() {
       Queue<info> q = new LinkedList<>();
       visited[startY][startX] = H;
       q.add(new info(startY, startX, H, 0, 1));
       //System.out.println("call walk!!!");
       while(!q.isEmpty()) {
        //System.out.println("while first!!!");
        info curInfo = q.poll();

        for(int i = 0; i<4; i++) {
            int nextPower = curInfo.curPower;
            int nextUmb = curInfo.curUmb;
            int cnt = curInfo.cnt;
            int nextY = curInfo.curY + y[i];
            int nextX = curInfo.curX + x[i];

            if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= N) continue;
            //System.out.println(nextY + " " + nextX);
            if(map[nextY][nextX] == 'E') {
                result = Math.min(result, cnt);
                continue;
            }

            if(map[nextY][nextX] == 'U') {
                nextUmb = D;
            }
            if(nextUmb <= 0) {
                nextPower--;
            } else {
                nextUmb--;
            }

            //System.out.println("nextPower : " + nextPower);

            if(nextPower <= 0) continue;

            if(visited[nextY][nextX] < nextPower + nextUmb) {
                visited[nextY][nextX] = nextPower + nextUmb;
                q.add(new info(nextY, nextX, nextPower, nextUmb, cnt + 1));
            }   
        }
       }
    }
}
