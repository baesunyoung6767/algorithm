import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, T, end;
    public static int[] time = new int[2001];
    public static int result = -1;
    public static int result_start, result_end;

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        T = Integer.parseInt(input[1]);

        for(int i = 0; i<N; i++) {
            int temp = Integer.parseInt(bf.readLine());

            for(int j = 0; j<temp; j++) {
                String[] time_data = bf.readLine().split(" ");
                int start_time = Integer.parseInt(time_data[0]);
                int end_time = Integer.parseInt(time_data[1]);

                end = Math.max(end, end_time);
                for(int t = start_time; t<end_time; t++) time[t] += 1;       
            }
        }

        for(int i = 0; i<=end; i++) {
            int hap = 0;
            for(int j = i; j< i + T; j++) {
                hap += time[j];
            }
            if(result < hap) {
                result = hap;
                result_start = i;
                result_end = i + T;
            }
        }

        System.out.println(result_start + " " + result_end);
    }
}