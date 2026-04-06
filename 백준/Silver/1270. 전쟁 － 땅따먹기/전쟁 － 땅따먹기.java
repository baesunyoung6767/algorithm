import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N;

    public static void main(String[] args) throws Exception{
        N = Integer.parseInt(bf.readLine());

        for(int i = 0; i<N; i++) {
            String[] input = bf.readLine().split(" ");
            int T = Integer.parseInt(input[0]);
            Map<Long, Integer> m = new HashMap<>();
            int maxNum = -1;
            long maxIdx = -1;

            for(int j = 1; j<=T; j++) {
                long num = Long.parseLong(input[j]);
                int data = m.getOrDefault(num, 0);
                m.put(num, data + 1);

                if(m.get(num) > maxNum) {
                    maxNum = m.get(num);
                    maxIdx = num;
                }
            }

            if(maxNum > T / 2) {
                System.out.println(maxIdx);
            } else {
                System.out.println("SYJKGW");
            }
        }
    }
}