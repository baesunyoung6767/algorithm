import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    public static class Node implements Comparable<Node> {
        int x,y;
        int cost;
        int dir;
        public Node(int x, int y, int cost,int dir){
            this.x = x;
            this.y = y;
            this.cost = cost;
            this.dir = dir;
        }

        @Override
        public int compareTo(Node other) {
            return this.cost - other.cost;
        }
    }
    static int W;
    static int H;
    static char[][] map;
    static int[][] deltas = {{-1,0},{0,1},{1,0},{0,-1}};
    static Node start,end;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        W = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        map = new char[H][W];
        boolean flag = false;
        for(int i=0; i<H; i++)
        {
            map[i] = br.readLine().toCharArray();
            for(int j=0; j<W; j++)
            {
                if(map[i][j]=='C')
                {
                    if(flag)
                        end = new Node(i,j,-1,-5);
                    else{
                        start = new Node(i,j,-1,-5);
                        flag = true;
                    }
                }
            }
        }
        int result = bfs();
        System.out.println(result);
    }

    public static int bfs()
    {
        int min = Integer.MAX_VALUE;
        PriorityQueue<Node> queue = new PriorityQueue<>();
        int[][][] visited = new int[4][H][W];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < H; j++) {
                Arrays.fill(visited[i][j], Integer.MAX_VALUE);
            }
        }
        queue.offer(start);
        while(!queue.isEmpty())
        {
            Node temp = queue.poll();
            if(temp.x == end.x && temp.y == end.y)
            {
                min = Math.min(min,temp.cost);
                continue;
            }
            for(int dir=0; dir<4; dir++)
            {
                int nx = temp.x + deltas[dir][0];
                int ny = temp.y + deltas[dir][1];
                int next = (temp.dir==dir)?temp.cost:temp.cost+1;
                if(nx < 0 || H <= nx || ny < 0 || W <= ny || map[nx][ny]=='*'||Math.abs(temp.dir-dir)==2)
                    continue;
                if(visited[dir][nx][ny] > next) {
                    queue.offer(new Node(nx, ny, next, dir));
                    visited[dir][nx][ny] = next;
                }
            }
        }
        return min;
    }

}