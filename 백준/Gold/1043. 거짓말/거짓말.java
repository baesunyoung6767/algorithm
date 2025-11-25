import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M;
    public static int[] isKnow;
    public static int result;
    public static int[] parent;
    public static List<Integer>[] partyPeopleList;

    public static int find(int x) {
        if(parent[x] == x) return x;
        return find(parent[x]);
    }

    public static void union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(isKnow[py] == 1) {
            int temp = px;
            px = py;
            py = temp;
        }

        parent[py] = px;
    }

    public static void main(String[] args) throws Exception{
        String[] input = bf.readLine().split(" ");

        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);

        isKnow = new int[N + 1];
        parent = new int[N + 1];

        String[] knowTrue = bf.readLine().split(" ");
        int knowTrueCnt = Integer.parseInt(knowTrue[0]);

        for(int i = 1; i<=knowTrueCnt; i++) {
            int personNum = Integer.parseInt(knowTrue[i]);
            isKnow[personNum] = 1;
        }

        for(int i = 1; i<=N; i++) {
            parent[i] = i;    
        }

        partyPeopleList = new ArrayList[M];
        for(int i = 0; i<M; i++) {
            partyPeopleList[i] = new ArrayList<>();
        }

        for(int i = 0; i<M; i++) {
            String[] partyInfo = bf.readLine().split(" ");
            int peopleLen = Integer.parseInt(partyInfo[0]);
            int x  = Integer.parseInt(partyInfo[1]);
            partyPeopleList[i].add(x);

            for(int j = 2; j<=peopleLen; j++) {
                int y = Integer.parseInt(partyInfo[j]);
                partyPeopleList[i].add(y);
                union(x, y);
            }
        }

        /*for(int i = 1; i<=N; i++) {
            System.out.print(parent[i] + " ");
        }
        System.out.println();
*/
        for(int i = 0; i<M; i++) {
            boolean isPos = true;
            for(int num : partyPeopleList[i]) {
                //System.out.println("num >>> " + num);
                int parentNum = find(parent[num]);
               // System.out.println("parent >>> " + isKnow[parentNum]);
                if(isKnow[parentNum] == 1) {
                    isPos = false;
                    break;
                }
            }

            if(isPos) result++;
        }

        System.out.println(result);
    }
}
