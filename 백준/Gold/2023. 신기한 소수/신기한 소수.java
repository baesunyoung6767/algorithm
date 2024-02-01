//package algoTest;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class Main {
			private static StringBuilder sb = new StringBuilder();
		
			private static int N;
			
			public static void main(String[] args) throws Exception {
				BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
				N = Integer.parseInt(in.readLine());
				
				int[] tmp = {2, 3, 5, 7};
				
				for(int i = 0; i<tmp.length; i++) {
					check(tmp[i], 1);
				}
				System.out.println(sb);
			}
			
			private static boolean isPrime(int num) {
				for(int i = 2; i<num; i++) {
					if(num % i == 0) return false; 
				}
				return true;
			}
			
			private static void check(int num, int length) {
				if(length == N) {
					sb.append(num + "\n");
					return;
				}
					
				for(int i = 1; i<=9; i++) {
					int test = num * 10 + i;
					if(isPrime(test)) check(test, length + 1);
				}
			}
			
}
