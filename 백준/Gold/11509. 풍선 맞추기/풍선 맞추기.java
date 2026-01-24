import java.io.*;
import java.util.Arrays;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N;
    public static int[] height;
    public static int[] arrow;
    public static int result;

    public static void main(String[] args) throws Exception{
        N = Integer.parseInt(bf.readLine());
        height = new int[N + 1];
        arrow = new int[1000001];

        String[] input = bf.readLine().split(" ");
        for(int i = 0; i<N; i++) {
            height[i + 1] = Integer.parseInt(input[i]);
        }

       for(int i = 1; i<=N; i++) {
            if(arrow[height[i]] == 0) {
                result += 1;
            } else {
                arrow[height[i]] -= 1;
            }

            arrow[height[i] - 1] += 1;
       }

       System.out.println(result);
    }
}
