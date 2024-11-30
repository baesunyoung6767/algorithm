import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static int N;
    public static char kind;
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static Set<String> s;
    public static int result;

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        kind = input[1].charAt(0);
        s = new HashSet<>();

        for(int i = 0; i<N; i++) {
            String name = bf.readLine();
            s.add(name);
        }

        if(kind == 'Y') {
            result = s.size() / 1;
        } else if(kind == 'F') {
            result = s.size() / 2;
        } else if(kind == 'O') {
            result = s.size() / 3;
        }

        System.out.println(result);
    }
}
