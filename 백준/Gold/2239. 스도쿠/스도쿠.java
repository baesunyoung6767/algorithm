

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static StringBuilder sb = new StringBuilder();
    static int[][] map;
    static int blank = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        map = new int[9][9];

        for(int i = 0; i<9; i++) {
            String temp = in.readLine();
            for(int j = 0; j<9; j++) {
                map[i][j] = temp.charAt(j) - '0';
            }
        }

        check(0, 0);
    }

    public static boolean isPossible(int cy, int cx, int num) {

        // 가로
        for(int i = 0; i<9; i++) {
        	if(map[cy][i] == num) return false;
        }
        
        // 세로
        for(int i = 0; i<9; i++) {
        	if(map[i][cx] == num) return false;
        }
        
        // 네모
        int startY = cy / 3 * 3;
        int startX = cx / 3 * 3;
        for(int i = startY; i< startY + 3; i++) {
            for(int j = startX; j<startX + 3; j++) {
              if(map[i][j] == num) return false;
            }
        }

        return true;
    }

    public static void check(int row, int col) {
    	if(col == 9) {
    		check(row+1, 0);
    		return;
    	}

    	if(row == 9) {
    		for(int i = 0; i<9; i++) {
    			for(int j = 0; j<9; j++) {
    				sb.append(map[i][j]);
    			}
    			sb.append("\n");
    		}
    		System.out.println(sb);
    		System.exit(0);
    	}

    	if(map[row][col] == 0) {
            for(int k = 1; k<=9; k++) {
            	if(isPossible(row, col, k)) {
            		map[row][col] = k;
            		check(row, col+1);
            	}
            }
            map[row][col] = 0;
            return;
        }
    	check(row, col+1);
    }
}
