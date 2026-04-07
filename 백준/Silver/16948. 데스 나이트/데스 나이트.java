import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static class Node {
        int x;
        int y;
        int dist;

        public Node(int y, int x, int dist) {
            this.y = y;
            this.x = x;
            this.dist = dist;
        }
    }

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N;
    public static int[][] map;
    public static int startX, startY, endX, endY;
    public static int[] y = {-2, -2, 0, 0, 2, 2};
    public static int[] x = {-1, 1, -2, 2, -1, 1};
    public static int result = 987654321;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(bf.readLine());
        String[] input = bf.readLine().split(" ");
        map = new int[N + 1][N + 1];

        startY = Integer.parseInt(input[0]);
        startX = Integer.parseInt(input[1]);
        endY = Integer.parseInt(input[2]);
        endX = Integer.parseInt(input[3]);

        bfs();
        if(result == 987654321) result = -1;
        System.out.println(result);
    }

    public static void bfs() {
        Queue<Node> q = new LinkedList<>();
        q.add(new Node(startY, startX, 0));
        int[][] visited = new int[N + 1][N + 1];
        visited[startY][startX] = 1;

        while(!q.isEmpty()) {
            Node cur = q.poll();

            if(cur.y == endY && cur.x == endX) {
                result = Math.min(result, cur.dist);
                continue;
            }
            
            for(int i = 0; i<6; i++) {
                int ny = cur.y + y[i];
                int nx = cur.x + x[i];

                if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx] == 1) continue;

                visited[ny][nx] = 1;
                q.add(new Node(ny, nx, cur.dist + 1));
            }
        }
    }
}
