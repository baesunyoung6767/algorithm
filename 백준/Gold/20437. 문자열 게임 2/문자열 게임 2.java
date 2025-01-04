import java.io.*;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int T;
    public static int[] alpha;
    
    public static void main(String[] args) throws Exception{
        T = Integer.parseInt(bf.readLine());

        for(int t = 1; t<=T; t++) {
            alpha = new int[26];
            String target = bf.readLine();
            int K = Integer.parseInt(bf.readLine());

            if(K == 1) {
                System.out.println("1 1");
                continue;
            }

            for(int i = 0; i<target.length(); i++) alpha[target.charAt(i)-'a']++;

            int max_len = Integer.MIN_VALUE;
            int min_len = Integer.MAX_VALUE;

            for(int i = 0; i<target.length(); i++) {
                char temp = target.charAt(i);
                if(alpha[temp - 'a'] < K) continue;

                int cnt = 1;
                for(int j = i + 1; j<target.length(); j++) {
                    char cur = target.charAt(j);
                    if(temp == cur) cnt++;
                    
                    if(cnt == K) {
                        max_len = Math.max(max_len, j-i+1);
                        min_len = Math.min(min_len, j-i+1);
                        break;
                    }
                }
            }

            if(min_len != Integer.MAX_VALUE) System.out.println(min_len + " " + max_len);
            else System.out.println("-1");
        }
    }
}
