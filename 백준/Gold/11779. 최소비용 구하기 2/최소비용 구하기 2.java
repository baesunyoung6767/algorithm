import java.io.*;
import java.util.*;

public class Main {
    public static class Node implements Comparable<Node>{
        int to;
        int cost;

        public Node(int to, int cost) {
            this.to = to;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node next) {
            return this.cost - next.cost;
        }
    }

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M;
    public static ArrayList<Node>[] city;
    public static boolean visited[];
    public static int route[];
    public static int dist[];

    public static void main(String[] args) throws Exception{
        N = Integer.parseInt(bf.readLine());
        M = Integer.parseInt(bf.readLine());

        city = new ArrayList[N + 1];
        visited = new boolean[N + 1];
        route = new int[N + 1];
        dist = new int[N + 1];

        for(int i = 1; i<=N; i++) {
            city[i] = new ArrayList<>();
            dist[i] = 987654321;
        }

        for(int i = 0; i<M; i++) {
            String[] input = bf.readLine().split(" ");
            int from = Integer.parseInt(input[0]);
            int to = Integer.parseInt(input[1]);
            int cost = Integer.parseInt(input[2]);

            Node temp = new Node(to, cost);
            city[from].add(temp);
        }

        String[] info = bf.readLine().split(" ");
        int from = Integer.parseInt(info[0]);
        int to = Integer.parseInt(info[1]);

        checkRoute(from);

        System.out.println(dist[to]);
        
        ArrayList<Integer> r = new ArrayList<>();
        int curCity = to;
        while(curCity != 0) {
            r.add(curCity);
            curCity = route[curCity];
        }

        System.out.println(r.size());
        for(int i = r.size() - 1; i>=0; i--) {
            System.out.print(r.get(i) + " ");
        }
    }

    public static void checkRoute(int start) {
        PriorityQueue<Node> pq = new PriorityQueue<>(); 
        pq.offer(new Node(start, 0));
        dist[start] = 0;

        while(!pq.isEmpty()) {
            Node cur = pq.poll();

            if(!visited[cur.to]) visited[cur.to] = true;
            else continue;

            for(int i = 0; i<city[cur.to].size(); i++) {
                Node next = city[cur.to].get(i);
                if(dist[next.to] > dist[cur.to] + next.cost) {
                    dist[next.to] = dist[cur.to] + next.cost;
                    pq.offer(new Node(next.to, dist[next.to]));
                    route[next.to] = cur.to;
                }
            }
        }
    }
}
