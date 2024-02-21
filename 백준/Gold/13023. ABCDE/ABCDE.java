
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Vector;

public class Main {
	private static StringBuilder sb = new StringBuilder();

	private static int N,M;
	private static Vector<Vector<Integer>> v;
	private static boolean[] visited;
	private static boolean resultPov;
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] input = in.readLine().split(" ");
		N = Integer.parseInt(input[0]);
		M = Integer.parseInt(input[1]);
		v = new Vector<>();
		for(int i = 0; i<N; i++) {
			v.add(new Vector<>());
		}
		visited = new boolean[N];
		
		int a, b;
		for(int i = 0; i<M; i++) {
			String[] temp = in.readLine().split(" ");
			a = Integer.parseInt(temp[0]);
			b = Integer.parseInt(temp[1]);
			
			v.get(a).add(b);
			v.get(b).add(a);
		}
		
		for(int i = 0; i<N; i++) {
			check(i, 0);
			
			if(resultPov) {
				sb.append(1);
				break;
			}
		}
		
		if(!resultPov) sb.append(0);
		
		System.out.println(sb);
	}
	
	private static void check(int start, int depth) {
		
		if(depth == 4) {
			resultPov = true;
			return;
		}
		
		visited[start] = true;
		
		for(int i = 0; i<v.get(start).size(); i++) {
			if(visited[v.get(start).get(i)]) continue;
			check(v.get(start).get(i), depth+1);
		}
		
		visited[start] = false;
	}
}