import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main {
    public static class city implements Comparable<city>{
        int num;
        int cost;

        public city(int num, int cost) {
            this.num = num;
            this.cost = cost;
        }

        @Override
        public int compareTo(city c) {
           return this.cost - c.cost;
        } 
    }

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int T;
    public static int n, m, t;
    public static int s, g, h;
    public static ArrayList<city>[] cityList;
    public static ArrayList<Integer> target;
    public static int[] visited;
    public static int[] dist;
    public static String tempDist;

    public static void main(String[] args) throws Exception{
        T = Integer.parseInt(bf.readLine());

        for(int r = 0; r<T; r++) {
            String[] input1 = bf.readLine().split(" ");
            n = Integer.parseInt(input1[0]);
            m = Integer.parseInt(input1[1]);
            t = Integer.parseInt(input1[2]);
            
            cityList = new ArrayList[n + 1];
            dist = new int[n + 1];
            target = new ArrayList<>();

            for(int i = 0; i<=n; i++) {
                cityList[i] = new ArrayList<>();
                dist[i] = Integer.MAX_VALUE;
            }

            String[] input2 = bf.readLine().split(" ");
            s = Integer.parseInt(input2[0]);
            g = Integer.parseInt(input2[1]);
            h = Integer.parseInt(input2[2]);

            for(int i = 0; i<m; i++) {
                String[] data = bf.readLine().split(" ");
                int a = Integer.parseInt(data[0]);
                int b = Integer.parseInt(data[1]);
                int cost = Integer.parseInt(data[2]);

                if((a == g && b == h) || (a == h) && (b == g)) {
                    cityList[a].add(new city(b, cost * 2 - 1));
                    cityList[b].add(new city(a, cost * 2 - 1));
                } else {
                    cityList[a].add(new city(b, cost * 2));
                    cityList[b].add(new city(a, cost * 2));
                }
            }

            for(int i = 0; i<t; i++) {
                int toNum = Integer.parseInt(bf.readLine());
                target.add(toNum);
            }

            Collections.sort(target);
            dist[s] = 0;
            visited = new int[n + 1];
            calcDist();

            for(int i = 0; i<t; i++) {
                if(dist[target.get(i)] != Integer.MAX_VALUE && dist[target.get(i)] % 2 == 1) {
                    System.out.print(target.get(i) + " ");
                }
            }
            System.out.println();
        }
    }

    public static void calcDist() {
        PriorityQueue<city> pq = new PriorityQueue<>((o1, o2) -> o1.cost - o2.cost);
        dist[s] = 0;
        pq.add(new city(s, 0));

        while(!pq.isEmpty()) {
            city cur = pq.poll();

            if(visited[cur.num] == 1) continue;

            visited[cur.num] = 1;

            for(int i = 0; i<cityList[cur.num].size(); i++) {
                city next = cityList[cur.num].get(i);
                int nextNum = next.num;
                int nextCost = next.cost;

                if(visited[nextNum] == 0 && dist[nextNum] > dist[cur.num] + nextCost) {
                    dist[nextNum] = dist[cur.num] + nextCost;
                    pq.add(new city(nextNum, dist[nextNum]));
                }
            }
        }
    }
}
