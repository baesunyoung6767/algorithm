import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, L;
    public static int road[];
    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        L = Integer.parseInt(input[1]);
        road = new int[N * 2];

        for(int i = 0; i<N*2; i+=2) {
            String[] data = bf.readLine().split(" ");
            int s = Integer.parseInt(data[0]);
            int e = Integer.parseInt(data[1]);

            road[i] = s;
            road[i + 1] = e;
        }

        Arrays.sort(road);

        int lastIdx = 0;
        int result = 0;

        for(int i = 0; i<2*N; i+=2) {
            int start = road[i];
            int end = road[i + 1];

            if(start <= lastIdx) {
                start = lastIdx + 1;
            }
            
            int len = end - start;
            int cnt = len/L;
            int res = len%L;

            if(res > 0) {
                cnt++;
                lastIdx = road[i + 1] - 1 + (L - res);
            }

            result += cnt;
        }

        System.out.println(result);
    }
}
