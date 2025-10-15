import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    public static class Shark {
        int r;
        int c;
        int m;
        int d;
        int s;

        public Shark(int r, int c, int m, int d, int s) {
            this.r = r;
            this.c = c;
            this.m = m;
            this.d = d;
            this.s = s;
        }
    }

    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M, K;
    public static ArrayList<Shark> sharks = new ArrayList<>();
    public static ArrayList<Shark>[][] map;
    public static int[] x = {0, 1, 1, 1, 0, -1, -1, -1};
    public static int[] y = {-1, -1, 0, 1, 1, 1, 0, -1};

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        K = Integer.parseInt(input[2]);

        map = new ArrayList[N][N];
        for(int i = 0; i<N; i++) {
            for(int j = 0; j<N; j++) {
                map[i][j] = new ArrayList<>();
            }
        }

        for(int i = 0; i<M; i++) {
            String[] sharkInfo = bf.readLine().split(" ");
            int r = Integer.parseInt(sharkInfo[0]) - 1;
            int c = Integer.parseInt(sharkInfo[1]) - 1;
            int m = Integer.parseInt(sharkInfo[2]);
            int s = Integer.parseInt(sharkInfo[3]);
            int d = Integer.parseInt(sharkInfo[4]);

            Shark newShark = new Shark(r, c, m, d, s);
            sharks.add(newShark);
        }

        while(true) {
            if(K == 0) break;

            for(int i = 0; i<sharks.size(); i++) {
                Shark curShark = sharks.get(i);
                int my = (curShark.r + N + y[curShark.d] * (curShark.s % N)) % N;
                int mx = (curShark.c + N + x[curShark.d] * (curShark.s % N)) % N;
                
                curShark.r = my;
                curShark.c = mx;

                map[curShark.r][curShark.c].add(curShark);
            }

            for(int i = 0; i<N; i++) {
                for(int j = 0; j<N; j++) {
                    if(map[i][j].size() < 2) {
                        map[i][j].clear();
                        continue;
                    }

                    int mtotal = 0;
                    int stotal = 0;
                    int size = map[i][j].size();
                    int oddCnt = 0;
                    int evenCnt = 0;

                    for(Shark s : map[i][j]) {
                        mtotal += s.m;
                        stotal += s.s;

                        if(s.d % 2 == 0) evenCnt++;
                        else oddCnt++;

                        sharks.remove(s);
                    }
                    map[i][j].clear();

                    int divMtotal = mtotal / 5;
                    int divStotal = stotal / size;

                    if(divMtotal == 0) continue;

                    if(evenCnt == size || oddCnt == size) {
                        for(int k = 0; k<8; k+=2) {
                            sharks.add(new Shark(i, j, divMtotal, k, divStotal));
                        }
                    } else {
                        for(int k = 1; k<8; k+=2) {
                            sharks.add(new Shark(i, j, divMtotal, k, divStotal));
                        }
                    }
                }
            }

            K--;
        }

        int result = 0;
        for(Shark s : sharks) {
            result += s.m;
        }

        System.out.println(result);
    }
}
