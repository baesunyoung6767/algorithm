import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    public static class pos {
        int x;
        int y;

        public pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }

    public static BufferedReader bf = new BufferedReader(new InputStreamReader((System.in)));
    public static int N;
    public static char[][] map;
    public static ArrayList<pos> teacherPos;
    public static int[] x = {0, 1, 0, -1};
    public static int[] y = {1, 0, -1, 0};
    public static boolean result;

    public static void main(String[] args) throws Exception{
        N = Integer.parseInt(bf.readLine());
        map = new char[N + 1][N + 1];
        teacherPos = new ArrayList<>();

        for(int i = 0; i<N; i++) {
            String[] input = bf.readLine().split(" ");
            for(int j = 0; j<N; j++) {
                map[i][j] = input[j].charAt(0);
                if(map[i][j] == 'T') {
                    teacherPos.add(new pos(i, j));
                }
            }
        }

        putObj(0);

        if(result) System.out.println("YES");
        else System.out.println("NO");
    }

    public static void putObj(int cnt) {
        if(cnt == 3) {
            boolean isPos = checkStu();
            if(isPos) {
                result = true;
            }
            return;
        }

        for(int i = 0; i<N; i++) {
            for(int j = 0; j<N; j++) {
                if(map[i][j] == 'X') {
                    map[i][j] = 'O';
                    putObj(cnt + 1);
                    map[i][j] = 'X';
                }
            }
        }
    }

    public static boolean checkStu() {
        boolean isPos = true;

        for(int i = 0; i<teacherPos.size(); i++) {
            int cy = teacherPos.get(i).y;
            int cx = teacherPos.get(i).x;

            for(int j = 0; j<4; j++) {
                int ny = cy + y[j];
                int nx = cx + x[j];
                while(true) {
                    if(ny < 0 || nx < 0 || ny >= N || nx >= N) break;
                    if(map[ny][nx] == 'O') break;
                    if(map[ny][nx] == 'S') {
                        isPos = false;
                        break;
                    }
                    ny += y[j];
                    nx += x[j];
                }
                if(!isPos) break;
            }
        }
        return isPos;
     }
}
