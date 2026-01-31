import java.io.*;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static class Node {
        int x;
        int y;

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M;
    public static int[][] map;
    public static int[][] copyMap;
    public static ArrayList<Node> virus = new ArrayList<>();
    public static int virusCnt;
    //public static int nonvirusCnt;
    public static int[] virusArray;
    public static int[] x = {1, 0, -1, 0};
    public static int[] y = {0, 1, 0, -1};
    public static int result;

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        map = new int[N][N];
        copyMap = new int[N][N];
        virusArray = new int[11];
        result = 987654321;

        for(int i = 0; i<N; i++) {
            String[] data = bf.readLine().split(" ");
            for(int j = 0; j<N; j++) {
                map[i][j] = data[j].charAt(0) - '0';
                if(map[i][j] == 2) {
                    virus.add(new Node(j, i));
                    virusCnt++;
                }
                //if(map[i][j] == 0) nonvirusCnt++;
            }
        }

        //nonvirusCnt = nonvirusCnt + (virusCnt - M);

        find(0, 0);
        if(result == 987654321) result = -1;
        System.out.println(result);
    }

    public static void moveVirus(int startY, int startX) {
        Queue<Node> q = new LinkedList<>();
        int[][] visited = new int[N][N];
        q.add(new Node(startX, startY));
        visited[startY][startX] = 1;

        while(!q.isEmpty()) {
            Node cur = q.poll();

            for(int i = 0; i<4; i++) {
                int ny = cur.y + y[i];
                int nx = cur.x + x[i];

                if(ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
                if(visited[ny][nx] == 1 || copyMap[ny][nx] == 999 || (copyMap[ny][nx] != -1 && copyMap[ny][nx] <= copyMap[cur.y][cur.x] + 1)) continue;
                copyMap[ny][nx] = copyMap[cur.y][cur.x] + 1;
                q.add(new Node(nx, ny));
                visited[ny][nx] = 1;
            }
        }
    }

    public static void startVirus() {
        //int tempNonvirusCnt = nonvirusCnt;

        for(int i = 0; i<N; i++) {
            for(int j = 0; j<N; j++) {
                copyMap[i][j] = map[i][j];
                if(copyMap[i][j] == 0 || copyMap[i][j] == 2) copyMap[i][j] = -1;
                if(copyMap[i][j] == 1) copyMap[i][j] = 999;
            }
        }

        for(int i = 0; i<virusCnt; i++) {
            if(virusArray[i] == 1) {
                Node cur = virus.get(i);
                copyMap[cur.y][cur.x] = 0;
                moveVirus(cur.y, cur.x);
            }
        }

        /*for(int i = 0; i<virusCnt; i++) {
            if(virusArray[i] == 1) {
                Node cur = virus.get(i);
                moveVirus(cur.y, cur.x);
            }
        }*/
        
        int maxValue = 0;
        int isPos = 1;
        for(int i = 0; i<N; i++) {
            for(int j = 0; j<N; j++) {
                if(copyMap[i][j] == -1) {
                    isPos = 0;
                    break;
                } 
                if(copyMap[i][j] == 999) copyMap[i][j] = -1;
                maxValue = Math.max(maxValue, copyMap[i][j]);
            }
            if(isPos == 0) break;
        }

        if(isPos == 1) result = Math.min(result, maxValue);
    }

    public static void find(int cnt, int now) {
        if(cnt == M) {
            startVirus();
            return;
        }

        for(int i = now; i<virusCnt; i++) {
            virusArray[i] = 1;
            find(cnt + 1, i + 1);
            virusArray[i] = 0;
        }
    }
}
