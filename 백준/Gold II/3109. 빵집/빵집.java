
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	private static StringBuilder sb = new StringBuilder();
	private static int R, C;
	private static char[][] map;
	private static int[] x = {1, 1, 1};
	private static int[] y = {-1, 0, 1};
	private static int cnt;
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] input1 = in.readLine().split(" ");
		R = Integer.parseInt(input1[0]);
		C = Integer.parseInt(input1[1]);
		map = new char[R][C];

		for(int i = 0; i<R; i++) {
			String tmp = in.readLine();
			for(int j = 0; j<tmp.length(); j++) {
				map[i][j] = tmp.charAt(j);
			}
		}
		
		for(int i = 0; i<R; i++) {
			checkPipe(i, 0);
		}
		
		sb.append(cnt + "\n");
		System.out.println(sb);
	}
	
	private static boolean checkPipe(int cy, int cx) {
		if(cx == C-1) {
			cnt++;
			return true;
		}
	
		map[cy][cx] = 'x';
		
		for(int i = 0; i<3; i++) {
			int ny = cy + y[i];
			int nx = cx + x[i];
			if(ny < 0 || nx < 0 || ny >= R || nx >= C || map[ny][nx] == 'x') continue;
			if(checkPipe(ny, nx)) return true;
		}
		return false;
	}
	
	
}
