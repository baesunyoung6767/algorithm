import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, K;
    public static long[] A;
    public static long[] hap;
    public static Map<Long, Long> sumArr = new HashMap<>();

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        K = Integer.parseInt(input[1]);
        A = new long[N + 1];
        hap = new long[N + 1];

        String[] data = bf.readLine().split(" ");
        for(int i = 1; i<=N; i++) {
            A[i] = Long.parseLong(data[i - 1]);
            hap[i] = hap[i-1] + A[i];
            //System.out.println("hap[i] = " + hap[i]);
        }

        long result = 0L;
        sumArr.put(0L, 1L);
        for(int i = 1; i<=N; i++) {
            result += sumArr.getOrDefault(hap[i]-K, 0L);
            long cnt = sumArr.getOrDefault(hap[i], 0L) + 1;
            //System.out.println("result => " + result);
            //System.out.println("cnt => " + cnt);
            sumArr.put(hap[i], cnt);
        }

        System.out.println(result);
    }
}
