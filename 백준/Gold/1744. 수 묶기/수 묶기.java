import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N;
    public static Integer[] negative;
    public static Integer[] positive;
    public static Integer[] justNum;

    public static void main(String[] args) throws Exception{
        N = Integer.parseInt(bf.readLine());
        negative = new Integer[N + 1];
        positive = new Integer[N + 1];
        justNum = new Integer[N + 1];

        int neg = 0;
        int pos = 0;
        int one = 0;

        for(int i = 0; i<N; i++) {
            int num = Integer.parseInt(bf.readLine());
            //System.out.println("num >> " + num);
            if(num <= 0) negative[neg++] = num;
            else if(num == 1) justNum[one++] = num;
            else if(num > 0) positive[pos++] = num; 
        }

        Arrays.sort(negative, 0, neg);
        Arrays.sort(positive, 0, pos, Collections.reverseOrder());

        int negSum = 0;
        for(int i = 0; i<neg; i++) {
            if(i + 1 == neg) negSum += negative[i];
            else {
                negSum += (negative[i] * negative[i + 1]);
                i++;
            }
        }

        //System.out.println(negSum);

        int posSum = 0;
        for(int i = 0; i<pos; i++) {
            if(i + 1 == pos) posSum += positive[i];
            else {
                //System.out.println("positive >> " + positive[i]);
                posSum += (positive[i] * positive[i + 1]);
                i++;
            }
            //System.err.println(posSum);
        }

        //System.out.println("posSum >> " + posSum);

        int result = negSum + posSum;

        for(int i = 0; i<one; i++) {
            result += justNum[i];
        }

        System.out.println(result);
    }
}
