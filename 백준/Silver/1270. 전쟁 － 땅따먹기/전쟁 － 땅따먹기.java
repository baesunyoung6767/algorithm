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

            for(int j = 1; j<=T; j++) {
                long num = Long.parseLong(input[j]);
                int data = m.getOrDefault(num, 0);
                m.put(num, data + 1);
            }

            List<Long> KeySet = new ArrayList<>(m.keySet());
            KeySet.sort((o1, o2) -> m.get(o2).compareTo(m.get(o1)));

            boolean still = false;
            int maxData = -1;
            long maxKey = -1;

            for(Long key : KeySet) {
                int curData = m.get(key);
                
                if(curData == maxData) {
                    still = true;
                    break;
                }

                if(curData > T / 2 && curData > maxData) {
                    maxData = curData;
                    maxKey = key;
                }
            }

            if(still || maxData == -1) {
                System.out.println("SYJKGW");
            } else {
                System.out.println(maxKey);
            }
        }
    }
}