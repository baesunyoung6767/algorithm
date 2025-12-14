import java.io.*;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static String S, P;

    public static void main(String[] args) throws Exception{
        S = bf.readLine();
        P = bf.readLine();

        int cnt = P.length();
        int startIdx = 0;
        int result = 0;
        while(cnt > 0) {
            int maxLen = -1;
            int equalCnt = 0;
            int i = startIdx;
            for(int j = 0; j<S.length(); j++) {
                if(i > P.length() - 1) break;
                if(P.charAt(i) == S.charAt(j)) {
                    equalCnt++;
                    i++;
                } else {
                    maxLen = Math.max(maxLen, equalCnt);
                    i = startIdx;
                    equalCnt = 0;
                }
            }
            maxLen = Math.max(maxLen, equalCnt);
            startIdx += maxLen;
            cnt -= maxLen;
            result++;
        }

        System.out.println(result);
    }
}
