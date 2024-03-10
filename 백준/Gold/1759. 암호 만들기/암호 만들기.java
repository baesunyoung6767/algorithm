import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.Vector;


public class Main {
	private static StringBuilder sb = new StringBuilder();

	private static int N, M;
	private static char[] arr;
	private static int[] checked;
	private static Vector<String> v;
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] input = in.readLine().split(" ");
		N = Integer.parseInt(input[0]);
		M = Integer.parseInt(input[1]);
		arr = new char[M];
		v = new Vector<>();
		checked = new int[M];
		
		String[] tmp = in.readLine().split(" ");
		for(int i = 0; i<M; i++) {
			arr[i] = tmp[i].charAt(0);
		}
		Arrays.sort(arr);
		
		check(0, 0);
		
		for(int i = 0; i<v.size(); i++) {
			sb.append(v.get(i) + "\n");
		}

		System.out.println(sb);
	}
	
	private static void check(int cnt, int start) {
		if(cnt == N) {
			String output = "";
			for(int i = 0; i<cnt; i++) {
				output += arr[checked[i]];
			}
			
			int x = 0, y = 0;
			
			for(int i = 0; i<output.length(); i++) {
				if(output.charAt(i) == 'a' || output.charAt(i) == 'e' || output.charAt(i) == 'i' || output.charAt(i) == 'o' || output.charAt(i) == 'u') {
					x++;
				} else { 
					y++;
				}
			}
			
			if(x < 1 || y < 2) return;
			else {
				v.add(output);
			}
		}
		
		for(int i = start; i<M; i++) {
			checked[cnt] = i;
			check(cnt+1, i+1);
		}
		
	}
}