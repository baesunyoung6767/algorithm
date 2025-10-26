import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N;
    public static long[][] input;

    public static void main(String[] args) throws Exception{
        N = Integer.parseInt(bf.readLine());
        input = new long[N][2];

        for(int i = 0; i<N; i++) {
            String[] data = bf.readLine().split(" ");
            long a = Long.parseLong(data[0]);
            long b = Long.parseLong(data[1]);

            input[i][0] = a;
            input[i][1] = b;
        }

        Arrays.sort(input, new Comparator<long[]>() {
            @Override
            public int compare(long[] o1, long[] o2) {
                if(o1[0] != o2[0]) return Long.compare(o1[0], o2[0]);
                else return Long.compare(o1[1], o2[1]);
            }
        });

        long beforeA = input[0][0];
        long beforeB = input[0][1];

        long totalLen = 0;

        for(int i = 1; i<N; i++) {
            if(beforeB > input[i][0]) {
                if(beforeB < input[i][1]) beforeB = input[i][1];
            } else {
                totalLen += beforeB - beforeA;
                beforeA = input[i][0];
                beforeB = input[i][1];
            }
        }

        totalLen += beforeB - beforeA;

        System.out.println(totalLen);
    }
}
