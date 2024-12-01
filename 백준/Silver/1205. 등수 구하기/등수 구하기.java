import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, T, P;
    public static int[] score;

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        T = Integer.parseInt(input[1]);
        P = Integer.parseInt(input[2]);
        score = new int[N];
        String[] temp = new String[3];

        if(N != 0) temp = bf.readLine().split(" ");

        for(int i = 0; i<N; i++) {
            score[i] = Integer.parseInt(temp[i]);
        }

        int result = 1;
        int i = 0;
        for(; i<N; i++) {
            if(score[i] > T) result++;
            else if(score[i] == T) continue;
            else break;
        }

        if(i == P) result = -1;
        if(N == 0) result = 1;
        System.out.println(result);
    }
}
