

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Vector;

public class Main {
    private static StringBuilder sb = new StringBuilder();
    private static int innings;
	private static int[][] result;
	private static boolean[] visited;
	private static int[] selected;
	private static int outcome;
	
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        innings = Integer.parseInt(in.readLine());
        result = new int[innings][10];
        visited = new boolean[10];
        selected = new int[10];
        outcome = Integer.MIN_VALUE;
        
        for(int i = 0; i<innings; i++) {
        	String[] data = in.readLine().split(" ");
        	for(int j = 1; j<=9; j++) {
        		result[i][j] = Integer.parseInt(data[j-1]);
        	}
        }
        
        selected[4] = 1; // 4번타자 - 1번선수
        visited[4] = true; // 인덱스가 선수 번호
        orderCheck(2);
        sb.append(outcome);
        System.out.println(sb);
    }
    
   
    // 순열
    private static void orderCheck(int cnt) { // 선수 번호
    	if(cnt == 10) {
    		int output = play();
    		outcome = Math.max(outcome, output);
    		return;
    	}
    	
    	for(int i = 1; i<=9; i++) { // 각 타자 자리
    		if(visited[i]) continue; 
    		visited[i] = true;
    		selected[i] = cnt;
    		orderCheck(cnt+1);
    		visited[i] = false;
    	}
    }
    
    private static int play() {
    	int sum = 0;
    	int idx = 1; // 1번 타자 부터
    	for(int i = 0; i<innings; i++) {
        	int out = 0;
    		int currentScore = 0;
    		boolean[] base = new boolean[4];
    		while(out < 3) {
    			switch (result[i][selected[idx]]) {
				case 0: // 아웃
					out++;
					break;
				case 1: // 안타
					if(base[3]) {
						base[3] = false;
						currentScore++;
					}
					if(base[2]) {
						base[3] = true;
						base[2] = false;
					}
					if(base[1]) {
						base[2] = true;
						base[1] = false;
					}
					base[1] = true;
					break;
				case 2: // 2루타
					if(base[3]) {
						base[3] = false;
						currentScore++;
					}
					if(base[2]) {
						base[2] = false;
						currentScore++;
					}
					if(base[1]) {
						base[3] = true;
						base[1] = false;
					}
					base[2] = true;
					break;
				case 3: // 3루타
					if(base[3]) {
						base[3] = false;
						currentScore++;
					}
					if(base[2]) {
						base[2] = false;
						currentScore++;
					}
					if(base[1]) {
						base[1] = false;
						currentScore++;
					}
					base[3] = true;
					break;
				case 4: // 홈런
					if(base[3]) {
						base[3] = false;
						currentScore++;
					}
					if(base[2]) {
						base[2] = false;
						currentScore++;
					}
					if(base[1]) {
						base[1] = false;
						currentScore++;
					}
					currentScore++;
					break;
				default:
					break;
				}
    			idx++;
    			if(idx >= 10) {
    				idx = 1;
    			}
    		}
    		sum+=currentScore;
    	}
    	return sum;
    }
}