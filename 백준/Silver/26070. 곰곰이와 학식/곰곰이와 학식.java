import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static long a, b, c;
    public static long x, y, z;
    public static long result;

        public static void main(String[] args) throws Exception{
            String[] gomgoms = bf.readLine().split(" ");
            String[] tickets = bf.readLine().split(" ");
            
            a = Long.parseLong(gomgoms[0]);
            b = Long.parseLong(gomgoms[1]);
            c = Long.parseLong(gomgoms[2]);
            x = Long.parseLong(tickets[0]);
            y = Long.parseLong(tickets[1]);
            z = Long.parseLong(tickets[2]);

            for(int i = 0; i<3; i++) {
            long chicken = Math.min(a, x);
              result += chicken;
              a -= chicken;
              x -= chicken;

              long pizza = Math.min(b,y);
              result += pizza;
              b -= pizza;
              y -= pizza;

              long burger = Math.min(c, z);
              result += burger;
              c -= burger;
              z -= burger;
            
              long ty = x / 3;
              long tz = y / 3;
              long tx = z / 3;

              y = ty;
              z = tz;
              x = tx;
            }

            System.out.println(result);
    }   
}
