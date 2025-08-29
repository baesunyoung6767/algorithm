import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static char ttt[][];
    public static int xcnt = 0;
    public static int ocnt = 0;
    public static void main(String[] args) throws Exception{
        while(true) {
            String input = bf.readLine();

            if("end".equals(input)) break;

            xcnt = 0;
            ocnt = 0;
            ttt = new char[3][3];

            for(int i = 0; i<3; i++) {
                for(int j = 0; j<3; j++) {
                    ttt[i][j] = input.charAt(i*3 + j);
                    if(ttt[i][j] == 'X') xcnt++;
                    if(ttt[i][j] == 'O') ocnt++;
                }
            }
            
            if((ocnt + xcnt) == 9 && xcnt == (ocnt + 1)) {
                if(isEnd('X') && isEnd('O')) {
                    System.out.println("invalid");
                } else if(isEnd('O')) {
                    System.out.println("invalid");
                } else {
                    System.out.println("valid");
                }
            } else {
                if(isEnd('X') && isEnd('O')) {
                    System.out.println("invalid");
                } else if(isEnd('X') && ocnt + 1 == xcnt) {
                    System.out.println("valid");
                } else if(isEnd('O') && ocnt == xcnt) {
                    System.out.println("valid");
                }  else {
                    System.out.println("invalid");
                }
            }
        }
    }

    public static boolean isEnd(char shape) {
  
        for(int i = 0; i<3; i++) {
            int cnt = 0;
            for(int j = 0; j<3; j++) {
                if(ttt[i][j] == shape) cnt++;
            }
            if(cnt == 3) {
                return true;
            }
        }

        for(int i = 0; i<3; i++) {
            int cnt = 0;
            for(int j = 0; j<3; j++) {
                if(ttt[j][i] == shape) cnt++;
            }
            if(cnt == 3) {
                return true;
            }
        }

        if((ttt[0][0] == shape) && (ttt[1][1] == shape) && (ttt[2][2] == shape)) return true;
        if((ttt[2][0] == shape) && (ttt[1][1] == shape) && (ttt[0][2] == shape)) return true;

        return false;
    }
}