import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static int N;
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int[] init;
    public static int[] firstInit;
    public static int[] target;
    public static int result;
    public static int firstResult;
    public static void main(String[] args) throws Exception {
        N = Integer.parseInt(bf.readLine());
        
        init = new int[N];
        firstInit = new int[N];
        target = new int[N];

        String inputInit = bf.readLine();
        String inputTarget = bf.readLine();
        for(int i = 0; i<N; i++) {
            init[i] = inputInit.charAt(i) - '0';
            firstInit[i] = init[i];
            target[i] = inputTarget.charAt(i) - '0';
        }

        firstInit[0] = 1 - firstInit[0];
        firstInit[1] = 1 - firstInit[1];

        result = 0;
        firstResult = 1;

        for(int i = 1; i<N; i++) {
            if(init[i - 1] != target[i - 1]) {
                init[i - 1] = 1 - init[i - 1];
                init[i] = 1 - init[i];

                if(i != N - 1) {
                    init[i + 1] = 1 - init[i + 1];
                }
                result++;
            }

            if(firstInit[i - 1] != target[i - 1]) {
                firstInit[i - 1] = 1 - firstInit[i - 1];
                firstInit[i] = 1 - firstInit[i];

                if(i != N - 1) {
                    firstInit[i + 1] = 1 - firstInit[i + 1];
                }
                firstResult++;
            }
        }

        for(int i = 0; i<N; i++) {
            if(init[i] != target[i] && result != Integer.MAX_VALUE) {
                result = Integer.MAX_VALUE;
            }

            if(firstInit[i] != target[i] && firstResult != Integer.MAX_VALUE) {
                firstResult = Integer.MAX_VALUE;
            }
        }

        int output = Math.min(result, firstResult);
        if(output == Integer.MAX_VALUE) {
            System.out.println(-1);
        } else {
            System.out.println(output);
        }
    }

}
