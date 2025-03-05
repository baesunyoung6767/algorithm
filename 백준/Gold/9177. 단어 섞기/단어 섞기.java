import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int T;
    public static String a, b, c;
    public static boolean[][] visited;
    public static void main(String[] args) throws Exception{
        T = Integer.parseInt(bf.readLine());

        for(int i = 1; i<=T; i++) {
            String input = bf.readLine().trim();
            String[] parts = input.split(" ");
            a = parts[0];
            b = parts[1];
            c = parts[2];

            visited = new boolean[201][201];

            checkStr(0,0);
            System.out.print("Data set " + i + ": ");
            if(visited[a.length()][b.length()]) System.out.println("yes");
            else System.out.println("no");
        }
    }

    public static void checkStr(int idx1, int idx2) {
        if(visited[idx1][idx2]) return;
        visited[idx1][idx2] = true;
        if(idx1 < a.length() && a.charAt(idx1) == c.charAt(idx1 + idx2)) checkStr(idx1 + 1, idx2);
        if(idx2 < b.length() && b.charAt(idx2) == c.charAt(idx1 + idx2)) checkStr(idx1, idx2 + 1);
    }
}
