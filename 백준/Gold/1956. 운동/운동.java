import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int V, E;
    public static int[][] map;
    public static int result;

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");
        V = Integer.parseInt(input[0]);
        E = Integer.parseInt(input[1]);
        map = new int[V + 1][V + 1];

        for(int i = 1; i<=V; i++) {
            for(int j = 1; j<=V; j++) {
                if(i == j) map[i][j] = 0;
                else map[i][j] = 987654321;
            }
        }

        for(int i = 0; i<E; i++) {
            String[] data = bf.readLine().split(" ");
            int a = Integer.parseInt(data[0]);
            int b = Integer.parseInt(data[1]);
            int cost = Integer.parseInt(data[2]);

            map[a][b] = cost;
        }

        for(int i = 1; i<=V; i++) {
            for(int j = 1; j<=V; j++) {
                for(int k = 1; k<=V; k++) {
                    if(i == j) continue;

                    //if(map[i][j] > map[i][k] + map[k][j]) map[i][j] = map[i][k] + map[k][j];
                   map[i][j] = Math.min(map[i][j], map[i][k] + map[k][j]);
                }
            }
        }

        result = 987654321;

        for(int i = 1; i<=V; i++) {
            for(int j = 1; j<=V; j++) {
                if(i == j) continue;
                result = Math.min(result, map[i][j] + map[j][i]);
            }
        }

        result = (result == 987654321) ? -1 : result;
        System.out.println(result);
    }
}
