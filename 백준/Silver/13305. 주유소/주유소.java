import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    
    public static int N;
    public static long result, target; 
    public static long[] road; 
    public static long[] price; 

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(bf.readLine());
        
        road = new long[N + 1];
        price = new long[N + 1];

        String[] road_data = bf.readLine().split(" ");
        String[] price_data = bf.readLine().split(" ");


        for(int i = 0; i<N-1; i++) road[i] = Integer.parseInt(road_data[i]);
        for(int i = 0; i<N; i++) price[i] = Integer.parseInt(price_data[i]);
        
        target = Integer.MAX_VALUE;
        result = 0;

        for(int i = 0; i<N-1; i++) {
            if(target > price[i]) target = price[i];
            result += target * road[i]; 
        }

        System.out.println(result);
    }
}
