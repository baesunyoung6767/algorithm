import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class Main {
    public static class Node implements Comparable<Node>{
        int d;
        int cost;

        public Node(int d, int cost) {
            this.d = d;
            this.cost = cost;
        }

        public int compareTo(Node target) {
            return this.cost - target.cost;
        }
    }

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M;
    public static ArrayList<Node>[] road;
    public static int[] dist;
    public static boolean[] visited;

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        road = new ArrayList[N+1];
        for(int i = 1; i<=N; i++) {
            road[i] = new ArrayList<>();
        }
       
        for(int i = 0; i<M; i++) {
            String[] data = bf.readLine().split(" ");
            int a = Integer.parseInt(data[0]);
            int b = Integer.parseInt(data[1]);
            int cost = Integer.parseInt(data[2]);

            road[a].add(new Node(b, cost));
            road[b].add(new Node(a, cost));
        }

        dist = new int[N+1];
        visited = new boolean[N+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dijkstra();
        System.out.println(dist[N]);
    }

    public static void dijkstra() {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        dist[1] = 0;
        pq.offer(new Node(1, 0));
        
        while(!pq.isEmpty()) {
            Node cur = pq.poll();

            if(visited[cur.d]) continue;
            else visited[cur.d] = true;

            for(int i = 0; i<road[cur.d].size(); i++) {
                Node next = road[cur.d].get(i);

                if(dist[next.d] > dist[cur.d] + next.cost) {
                    dist[next.d] = dist[cur.d] + next.cost;
                    pq.offer(new Node(next.d, dist[next.d]));
                }
            }
        }
    }
}
