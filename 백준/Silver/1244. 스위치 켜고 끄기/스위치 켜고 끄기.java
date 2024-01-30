

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(in.readLine());
		int[] arr = new int[N+1];
	
		String[] readLine = in.readLine().split(" ");
		for(int i = 1; i<=N; i++) {
			arr[i] = readLine[i-1].charAt(0) - '0';
		}
		
		int personNum = Integer.parseInt(in.readLine());
		int[][] person = new int[personNum][personNum];
		
		for(int i = 0; i<personNum; i++) {
			String[] personRead = in.readLine().split(" ");
			int gender = personRead[0].charAt(0) - '0';
            int num = Integer.parseInt(personRead[1]);
            
            if(gender == 1) { // 남학생인 경우
				int cnt = 1;
				for(int j = 1; j<=N; j++) {
					if(j % num == 0) {
						if(arr[j] == 0) arr[j] = 1;
						else arr[j] = 0;
					}
				}
				
			} else { // 여학생인 경우
				int left = num - 1;
				int right = num + 1;
				
				while(left > 0 && right <= N) {
					if(arr[left] != arr[right]) {
						break;
					}
					else {
						left--;
						right++;
					}
				}
				for(int j = left+1; j<=right-1; j++) {
					if(arr[j] == 0) arr[j] = 1;
					else arr[j] = 0;
				}
			}
		}
		
		
		
		for(int i = 1; i<=N; i++) {
			sb.append(arr[i] + " ");
			if(i % 20 == 0) sb.append("\n");
		}
		sb.append("\n");
		
		System.out.println(sb);
	}
}
