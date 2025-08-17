import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static class node {
        int y;
        int x;

        public node(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, K, R;
    public static ArrayList<node>[][] road;
    public static int[][] cow;
    public static int[] x = {1, 0, -1, 0};
    public static int[] y = {0, 1, 0, -1};
    public static int result;

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);
        R = Integer.parseInt(input[2]);

        road = new ArrayList[N + 1][N + 1];
        cow = new int[N + 1][N + 1];

        for(int i = 0; i<=N; i++) {
            for(int j = 0; j<=N; j++) {
                road[i][j] = new ArrayList<>();
            }
        }

        for(int i = 0; i<R; i++) {
            String[] roadInfo = bf.readLine().split(" ");
            int r1 = Integer.parseInt(roadInfo[0]);
            int c1 = Integer.parseInt(roadInfo[1]);
            int r2 = Integer.parseInt(roadInfo[2]);
            int c2 = Integer.parseInt(roadInfo[3]);

            road[r1][c1].add(new node(r2, c2));
            road[r2][c2].add(new node(r1, c1));
        }

        for(int i = 0; i<K; i++) {
            String[] cowInfo = bf.readLine().split(" ");
            int r1 = Integer.parseInt(cowInfo[0]);
            int c1 = Integer.parseInt(cowInfo[1]);

            cow[r1][c1] = 1;
        }

        for(int i = 1; i<=N; i++) {
            for(int j = 1; j<=N; j++) {
                if(cow[i][j] == 1) {
                    bfs(i, j);
                }
            }
        }

        System.out.println(result / 2);
    }

    public static void bfs(int r, int c) {
        Queue<node> q = new LinkedList<>();
        int[][] visited = new int[N + 1][N + 1];

        q.add(new node(r, c));
        visited[r][c] = 1;

        while(!q.isEmpty()) {
            node cur = q.poll();
            int cy = cur.y;
            int cx = cur.x;

            for(int i = 0; i<4; i++) {
                int ny = cy + y[i];
                int nx = cx + x[i];

                if(ny <= 0 || nx <= 0 || ny > N || nx > N || visited[ny][nx] == 1) continue;

                boolean pos = true;
                for(int j = 0; j<road[cy][cx].size(); j++) {
                    node next = road[cy][cx].get(j);

                    if(next.y == ny && next.x == nx) {
                        pos = false;
                        break;
                    }
                }

                if(pos) {
                    visited[ny][nx] = 1;
                    q.add(new node(ny, nx));
                }
            }
        }

        for(int i = 1; i<=N; i++) {
            for(int j = 1; j<=N; j++) {
                if(visited[i][j] == 0 && cow[i][j] == 1) result++;
            }
        }
    }
}
