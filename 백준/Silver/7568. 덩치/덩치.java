import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.stream.Stream;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N;
    public static int[][] person;
    
    public static void main(String[] args) throws Exception{
        N = Integer.parseInt(bf.readLine());
        person = new int[N + 1][2];

        for(int i = 0; i<N; i++) {
            int[] input = Stream.of(bf.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            person[i][0] = input[0];
            person[i][1] = input[1];
        }

        for(int i = 0; i<N; i++) {
            int curW = person[i][0];
            int curH = person[i][1];
            
            int cnt = 0;

            for(int j = 0; j<N; j++) {
                int nextW = person[j][0];
                int nextH = person[j][1];
                
                if(curW == nextW && curH == nextH) continue;
                else if(curW < nextW && curH < nextH) cnt++;
            }

            System.out.print(cnt + 1);
            System.out.print(" ");
        }
    }
}
