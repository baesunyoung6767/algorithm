import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main{
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int T;
    public static int N;
    public static int[] parent;
    public static int[] cost;

    public static void main(String[] args) throws Exception{
        T = Integer.parseInt(bf.readLine());
        
        for(int t = 0; t<T; t++) {
            N = Integer.parseInt(bf.readLine());
            parent = new int[200001];
            cost = new int[200001];
            Map<String, Integer> m = new HashMap<>();

            for(int i = 0; i<200001; i++) {
                parent[i] = i;
                cost[i] = 1;
            }

            int idx = 0;
            for(int i = 0 ; i<N; i++) {
                String[] input = bf.readLine().split(" ");
                String a = input[0];
                String b = input[1];

                if(!m.containsKey(a)) {
                    m.put(a, idx++);
                }

                if(!m.containsKey(b)) {
                    m.put(b, idx++);
                }

                int output = union(m.get(a), m.get(b));
                System.out.println(output);
            }
        }
    }

    public static int find(int p) {
        if(p == parent[p]) return p;
        return find(parent[p]);
    }

    public static int union(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if(pa != pb) {
            parent[pb] = pa;
            cost[pa] += cost[pb];
        }

        return cost[pa];
    }
}
