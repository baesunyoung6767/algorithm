import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class Main {
    public static class Node implements Comparable<Node>{
        int num;
        int time;

        public Node(int num, int time) {
            this.num = num;
            this.time = time;
        }

        @Override
        public int compareTo(Node o) {
           return this.time - o.time;
        }
    }

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int T;
    public static ArrayList<Node>[] list;
    public static int[] dist;
    public static int[] visited;
    
    public static void main(String[] args) throws Exception{
        T = Integer.parseInt(bf.readLine()); 

        for(int t = 0; t<T; t++) {
            String[] input = bf.readLine().split(" ");

            int N = Integer.parseInt(input[0]);
            int D = Integer.parseInt(input[1]);
            int C = Integer.parseInt(input[2]);
            
            list = new ArrayList[N + 1];
            dist = new int[N + 1];
            visited = new int[N + 1];

            for(int i = 1; i<=N; i++) {
                dist[i] = Integer.MAX_VALUE;
                list[i] = new ArrayList<>();
            }

            for(int i = 0; i<D; i++) {
                String[] data = bf.readLine().split(" ");

                int a = Integer.parseInt(data[0]);
                int b = Integer.parseInt(data[1]);
                int s = Integer.parseInt(data[2]);

                list[b].add(new Node(a, s));
            }

            dijkstra(C);

            int result = 0;
            int total = 0;

            for(int i = 1; i<=N; i++) {
                if(dist[i] != Integer.MAX_VALUE) {
                    result++;
                    total = Math.max(total, dist[i]);
                }
            }

            System.out.println(result + " " + total);
        }
    }

    public static void dijkstra(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>();
        dist[start] = 0;
        pq.offer(new Node(start, 0));

        while(!pq.isEmpty()) {
           int cur = pq.poll().num;

           if(visited[cur] == 0) {
            visited[cur] = 1;

            for(Node n : list[cur]) {
                if(dist[n.num] > dist[cur] + n.time) {
                    dist[n.num] = dist[cur] + n.time;
                    pq.add(new Node(n.num, dist[n.num]));
                }
            }
           }
        }
    }
}
