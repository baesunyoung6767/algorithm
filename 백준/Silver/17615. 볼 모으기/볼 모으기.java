import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N;
    public static char[] colors;
    public static int result;

    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(bf.readLine());
        
        String input = bf.readLine();
        colors = new char[input.length()];

        for(int i = 0; i<N; i++) {
            colors[i] = input.charAt(i);
        }

        result = Integer.MAX_VALUE;
        int len = colors.length;
        int chk = 0;
        int temp_result = 0;
        for(int i = 0; i<len; i++) {
            if(chk == 1 && colors[i] == 'R') temp_result++;
            if(colors[i] == 'B') chk = 1;
        }
        chk = 0;
        result = Math.min(result, temp_result);
        temp_result = 0;

        for(int i = 0; i<len; i++) {
            if(chk == 1 && colors[i] == 'B') temp_result++;
            if(colors[i] == 'R') chk = 1;
        }
        chk = 0;
        result = Math.min(result, temp_result);
        temp_result = 0;

        for(int i = len - 1; i>=0; i--) {
            if(chk == 1 && colors[i] == 'R') temp_result++;
            if(colors[i] == 'B') chk = 1;
        }
        chk = 0;
        result = Math.min(result, temp_result);
        temp_result = 0;

        for(int i = len - 1; i>=0; i--) {
            if(chk == 1 && colors[i] == 'B') temp_result++;
            if(colors[i] == 'R') chk = 1;
        }
        result = Math.min(result, temp_result);

        System.out.println(result);
    }
}
