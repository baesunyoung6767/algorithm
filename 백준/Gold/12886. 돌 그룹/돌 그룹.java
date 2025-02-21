import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static class Stone {
        int a, b, c;

        public Stone(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
    }

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int A, B, C;

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");

        A =  Integer.parseInt(input[0]);
        B =  Integer.parseInt(input[1]);
        C =  Integer.parseInt(input[2]);
        
        if(move_stone(A, B, C)) System.out.print(1);
        else System.out.println(0);
    }

    public static boolean move_stone(int a, int b, int c) {
        if((a + b + c) % 3 != 0) return false;

        Queue<Stone> q = new LinkedList<>();
        boolean[][] selected = new boolean[1501][1501];

        q.add(new Stone(a, b, c));

        while(!q.isEmpty()) {
            Stone s = q.poll();

            a = s.a;
            b =  s.b;
            c = s.c;

            if(a == b && b == c && a == c) return true;

            if(a != b) {
                int na = a > b ? a - b : a + a;
                int nb = a > b ? b + b : b - a;

                if(!selected[na][nb]) {
                    q.offer(new Stone(na, nb, c));
                    selected[na][nb] = true;
                }
            }

            if(b != c) {
                int nb = b > c ? b - c : b + b;
                int nc = b > c ? c + c : c - b;

                if(!selected[nb][nc]) {
                    q.offer(new Stone(a, nb, nc));
                    selected[nb][nc] = true;
                }
            }

            if(a != c) {
                int na = a > c ? a - c : a + a;
                int nc = a > c ? c + c : c - a;

                if(!selected[na][nc]) {
                    q.offer(new Stone(na, b, nc));
                    selected[na][nc] = true;
                }
            }
        }
        return false;
    }
}