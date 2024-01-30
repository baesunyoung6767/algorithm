import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(in.readLine());
		int[] arr = new int[N];
	
		String[] readLine = in.readLine().split(" ");
		for(int t = 0; t<N; t++) {
			arr[t] = readLine[t].charAt(0) - '0';
		}
		
		int personNum = Integer.parseInt(in.readLine());
		int gender;
		int number;
		for(int t = 0; t<personNum; t++) {
			String[] personRead = in.readLine().split(" ");
			gender = personRead[0].charAt(0) - '0';
			number = Integer.parseInt((personRead[1]));
			
			if(gender == 1) { // 남학생인 경우
				for(int i = 0; i<N; i++) {
					if((i+1) % number == 0) arr[i] = arr[i] == 0 ? 1 : 0;
				}
			}
			
			else if(gender == 2) { // 여학생인 경우
				arr[number - 1] = arr[number - 1] == 0 ? 1 : 0;
				
				for(int i = 1; i<=N/2; i++) {
					if(number - i - 1 < 0 || number + i - 1 >= N) break; // 범위 벗어나면 종료
					if(arr[number - i - 1] == arr[number + i - 1]) {
						arr[number - i - 1] = arr[number - i - 1] == 0 ? 1 : 0;
						arr[number + i - 1] = arr[number + i - 1] == 0 ? 1 : 0;
					}
					else break;
				}
			}
		}
		
		
		for(int t = 0; t<N; t++) {
			sb.append(arr[t] + " ");
			if((t+1) % 20 == 0) sb.append("\n");
		}
		sb.append("\n");
		
		System.out.println(sb);
	}
}
