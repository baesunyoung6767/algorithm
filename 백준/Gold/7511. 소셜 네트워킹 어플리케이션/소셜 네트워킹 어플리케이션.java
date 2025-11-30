import java.io.*;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int T;
    public static int parent[];

    public static void main(String[] args) throws Exception{
        T = Integer.parseInt(bf.readLine());

        for(int t = 1; t<=T; t++) {
            int friend_num = Integer.parseInt(bf.readLine());
            int circle_num = Integer.parseInt(bf.readLine());

            parent = new int[friend_num];
            setParent(friend_num);

            for(int i = 0; i<circle_num; i++) {
                String[] input = bf.readLine().split(" ");
                int a = Integer.parseInt(input[0]);
                int b = Integer.parseInt(input[1]);

                union(a, b);
            }

            int result_num = Integer.parseInt(bf.readLine());
            System.out.println("Scenario " + t + ":");

            for(int i = 0; i<result_num; i++) {
                String[] input = bf.readLine().split(" ");
                int a = Integer.parseInt(input[0]);
                int b = Integer.parseInt(input[1]);

                int pa = find(a);
                int pb = find(b);

                if(parent[pa] == parent[pb]) {
                    System.out.println("1");
                } else {
                    System.out.println("0");
                }
            }
            System.out.println();
        }
    }

    public static void setParent(int end) {
        for(int i = 0; i<end; i++) {
            parent[i] = i;
        }
    }

    public static int find(int n) {
        if(parent[n] == n) return parent[n];
        return find(parent[n]);
    }

    public static void union(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if(pa < pb) {
            int temp = pa;
            pa = pb;
            pb = temp;
        }

        parent[pa] = pb;
    }
}
