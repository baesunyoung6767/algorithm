import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;

public class Main {
	public static boolean[] visited;
	public static int[] arr;
	public static int N;
	public static int M;
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		String[] tmp = in.readLine().split(" ");
		N = Integer.parseInt(tmp[0]);
		M = Integer.parseInt(tmp[1]);
		visited = new boolean[N+1];
		arr = new int[M];
		fun(0);

		System.out.println(sb);
	}

	private static void fun(int cnt) {
		if(cnt == M) {
			for(int i = 0; i<M; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			return;
		}
		
		for(int i = 1; i<=N; i++) {
			if(visited[i]) continue;
			arr[cnt] = i;
			visited[i] = true;
			fun(cnt+1);
			visited[i] = false;
		}
	}
}