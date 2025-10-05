import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Queue;

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
    public static int N, P, K;
    public static int result = -1;
    public static ArrayList<Node> line[];
    public static int start, end;

    public static void main(String[] args) throws Exception{
       String[] input = bf.readLine().split(" ");
       N = Integer.parseInt(input[0]);
       P = Integer.parseInt(input[1]);
       K = Integer.parseInt(input[2]);

       line = new ArrayList[N + 1];
       for(int i = 0; i<=N; i++) {
        line[i] = new ArrayList<>();
       }

       for(int i = 0; i<P; i++) {
        String[] lineInfo = bf.readLine().split(" ");
        int a = Integer.parseInt(lineInfo[0]);
        int b = Integer.parseInt(lineInfo[1]);
        int cost = Integer.parseInt(lineInfo[2]);
        
        line[a].add(new Node(b, cost));
        line[b].add(new Node(a, cost));

        end = Math.max(end, cost);
       }

       /*for(int i = 1; i<=N; i++) {
        for(int j = 0; j<line[i].size(); j++) {
            Node target = line[i].get(j);
            System.out.println(i + " " + target.to + " : " + target.cost);
        }
       }*/

       while(start <= end) {
        int mid = (start + end) / 2;

        if(bfs(mid)) {
            result = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
       }

       System.out.println(result);
    }

    public static boolean bfs(int target) {
        int[] dp;
        dp = new int[N + 1];
        
        for(int i = 0; i<=N; i++) {
            dp[i] = 987654321;
        }

        PriorityQueue<Node> q = new PriorityQueue<>();
        q.add(new Node(1, 0));

        while(!q.isEmpty()) {
            Node cur = q.poll();

            int now = cur.to;
            int nowCost = cur.cost;

            if(dp[now] < nowCost) continue;

            for(int i = 0; i<line[now].size(); i++) {
                Node nextObj = line[now].get(i);
                int next = nextObj.to;
                int nextCost = nowCost;

                if(nextObj.cost > target) nextCost += 1;

                if(nextCost < dp[next]) {
                    dp[next] = nextCost;
                    q.add(new Node(next, nextCost));
                }
            }
        }
        
        return dp[N] <= K;
    }
}
