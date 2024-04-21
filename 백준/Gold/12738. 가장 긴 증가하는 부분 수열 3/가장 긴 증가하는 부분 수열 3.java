
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
	static StringBuilder sb = new StringBuilder();
	static int N;
	static int[] arr;
	static List<Integer> list;
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(in.readLine());
		arr = new int[N + 1];
		list = new ArrayList<>();
		list.add(Integer.MIN_VALUE);
		
		String[] input = in.readLine().split(" ");
		for(int i = 1; i<=N; i++) {
			arr[i] = Integer.parseInt(input[i-1]);
		}
		
		for(int i = 1; i<=N; i++) {
			int num = arr[i];
			int start = 1;
			int end = list.size() - 1;
			int mid = 0;
			
			if(num > list.get(list.size() - 1)) list.add(num);
			else {
				while(start < end) {
					mid = (start + end) / 2;
					
					if(list.get(mid) < num) start = mid + 1;
					else {
						end = mid ;
					}
				}
				list.set(end, num); // 인덱스, 값
			}
		}
		
		sb.append(list.size() - 1);
		System.out.println(sb);
	}
}
