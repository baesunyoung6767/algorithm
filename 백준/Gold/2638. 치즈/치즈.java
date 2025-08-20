import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static class node{
        int y;
        int x;

        public node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M;
    public static int[][] map;
    public static ArrayList<node> cheese;
    public static int cheeseCnt;
    public static int[] x = {1, 0, -1, 0};
    public static int[] y = {0, 1, 0, -1};
    public static int result = 0;

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");
        cheese = new ArrayList<>();
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        map = new int[N + 1][M + 1];

        for(int i = 0; i<N; i++) {
            String[] data = bf.readLine().split(" ");
            for(int j = 0; j<M; j++) {
                map[i][j] = Integer.parseInt(data[j]);
                if(map[i][j] == 1) {
                    cheeseCnt++;
                    cheese.add(new node(i, j));
                }
            }
        }

        while(cheeseCnt > 0) {
            result++;
            bfs();
            melting();
        }

        System.out.println(result);
    }

    public static void melting() {
        for(int i = 0; i<cheese.size(); i++) {
            node curCheese = cheese.get(i);
            int cy = curCheese.y;
            int cx = curCheese.x;
            int cnt = 0;

            for(int j = 0; j<4; j++) {
                int ny = cy + y[j];
                int nx = cx + x[j];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
                if(map[ny][nx] == 2) cnt++;
            }

            if(cnt >= 2) {
                map[cy][cx] = 0;
                cheese.remove(i);
                cheeseCnt--;
                i--;
            }
        }
    }

    public static void bfs() {
        Queue<node> q = new LinkedList<>();
        int[][] visited = new int[N + 1][M + 1];
        q.add(new node(0, 0));
        visited[0][0] = 1;
        map[0][0] = 2;

        while(!q.isEmpty()) {
            node cur = q.poll();
            int cy = cur.y;
            int cx = cur.x;

            for(int i = 0; i<4; i++) {
                int ny = cy + y[i];
                int nx = cx + x[i];

                if(ny < 0 || nx < 0 || nx >= M || ny >= N || visited[ny][nx] == 1 || map[ny][nx] == 1) continue;

                map[ny][nx] = 2;
                q.add(new node(ny, nx));
                visited[ny][nx] = 1;
            }
        }
    }
}
