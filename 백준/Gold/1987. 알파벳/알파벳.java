import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class Main {
	public static class Pair {
		int x;
		int y;
		
		Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	private static StringBuilder sb = new StringBuilder();
	private static int[] x = {1, 0, -1, 0};
	private static int[] y = {0, 1, 0, -1};
	private static int R, C;
	private static int[] visited;
	private static char[][] map;
	//private static Queue<Pair> q;
	private static int result;
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		String[] input = in.readLine().split(" ");
		R = Integer.parseInt(input[0]);
		C = Integer.parseInt(input[1]);
		
		map = new char[R][C];
		visited = new int[26];
		
		for(int i = 0; i<R; i++) {
			String tmp = in.readLine();
			for(int j = 0; j<C; j++) {
				map[i][j] = tmp.charAt(j);
			}
		}
		
		result = Integer.MIN_VALUE;
		visited[map[0][0] - 'A'] = 1;
		dfs(0, 0, 1);
		sb.append(result + "\n");
		System.out.println(sb);
	}
	
	private static void dfs(int cx, int cy, int sum) {
		for(int i = 0; i<4; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];
			
			if(ny < 0 || nx < 0 || ny >= R || nx >= C) continue;
			if(visited[map[ny][nx] - 'A'] == 1) continue;
			visited[map[ny][nx] - 'A'] = 1;
			dfs(nx, ny, sum+1);
			visited[map[ny][nx] - 'A'] = 0;
		}
		
		result = Math.max(result, sum);
	}
}