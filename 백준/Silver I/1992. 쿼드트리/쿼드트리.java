

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
	private static StringBuilder sb = new StringBuilder();
	private static int N;
	private static char[][] map;
	private static Queue<Character> result;
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(in.readLine());
		map = new char[N][N];
		result = new LinkedList<Character>();
		
		for(int i = 0; i<N; i++) {
			String input = in.readLine();
			for(int j = 0; j<N; j++) {
				map[i][j] = input.charAt(j);
			}
		}
		
		quadTree(N, 0, 0);
		
		while(!result.isEmpty()) {
			sb.append(result.poll());
		}
		System.out.println(sb);
	}
	
	// 1 2
	// 3 4
	private static void quadTree(int N, int y, int x) {
		char start = map[y][x];
		boolean checkDiv = false;
		
		for(int i = y; i<N+y; i++) {
			for(int j = x; j<N+x; j++) {
				if(start != map[i][j]) {
					result.offer('(');
					checkDiv = true;
					// 1
					quadTree(N/2, y, x);
					// 2
					quadTree(N/2, y, x+N/2);
					// 3
					quadTree(N/2, y+N/2, x);
					// 4
					quadTree(N/2, y+N/2, x+N/2);
					result.offer(')');
					break;
				}
			}
			if(checkDiv) break;
		}
		if(!checkDiv) result.offer(start);
	}
}
