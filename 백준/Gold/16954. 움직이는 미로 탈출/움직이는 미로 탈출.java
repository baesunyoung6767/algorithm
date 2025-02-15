import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static char[][] map;
    public static int startY, startX, endY, endX;
    public static int[] x = {0, 0, 0, 1, -1, 1, 1, -1, -1};
    public static int[] y = {1, -1, 0, 0, 0, 1, -1, -1, 1};

    public static class Node {
        int curX;
        int curY;

        public Node(int curX, int curY) {
            this.curX = curX;
            this.curY = curY;
        }
    }

    public static void main(String[] args) throws Exception{
        map = new char[8][8];

        for(int i = 0; i<8; i++) {
            String input = bf.readLine();
            for(int j = 0; j<8; j++) {
                map[i][j] = input.charAt(j);
            }
        }

        startY = 7;
        startX = 0;
        endY = 0;
        endX = 7;

        moveMap();
    }

    public static void moveMap() {
        Queue<Node> q = new ArrayDeque<>();
        q.offer(new Node(startX, startY));

        while(!q.isEmpty()) {
            int size = q.size();
            int[][] visited = new int[8][8];
            
            while(size > 0) {
                Node current = q.poll();
                int cx = current.curX;
                int cy = current.curY;
                
                if(cx == endX && cy == endY) {
                    System.out.println(1);
                    return;
                }

                if(map[cy][cx] == '.') {
                    for(int i = 0; i<9; i++) {
                        int ny = cy + y[i];
                        int nx = cx + x[i];
                        
                        if(ny < 0 || nx < 0 || ny >= 8 || nx >= 8 || map[ny][nx] == '#' || visited[ny][nx] == 1) continue;

                        q.offer(new Node(nx, ny));
                        visited[ny][nx] = 1;
                    }
                }
                
                size--;
            }
            moveWall();
        }

        System.out.println(0);
        return;
    }

    public static void moveWall() {
        for(int i = 7; i>0; i--) {
            for(int j = 0; j<8; j++) {
                map[i][j] = map[i-1][j];
            }
        }

        for(int i = 0; i<8; i++) {
            map[0][i] = '.';
        }
    }
}
