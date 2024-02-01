

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
			private static StringBuilder sb = new StringBuilder();
			private static int N, S, B; 
			private static int[] arrS, arrB;
			private static int minResult = Integer.MAX_VALUE;

			public static void main(String[] args) throws Exception {
				BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
				N = Integer.parseInt(in.readLine());

				arrS = new int[N]; // 신맛
				arrB = new int[N]; // 쓴맛
				
				for(int i = 0; i<N; i++) {
					String[] tmp = in.readLine().split(" ");
					arrS[i] = Integer.parseInt(tmp[0]);
					arrB[i] = Integer.parseInt(tmp[1]);
				}
				
				for(int i = 1; i< (1<<N) ; i++) {
					int s = 1; 
					int b = 0;
					
					for(int j = 0; j<N; j++) {
						if((i & (1 << j)) != 0) {
							s *= arrS[j];
							b += arrB[j];
						}
					}
					
					minResult = Math.min(minResult, Math.abs(s - b));
				}
				sb.append(minResult);
				System.out.println(sb);
			}
			
}
