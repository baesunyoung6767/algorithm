

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Vector;

public class Main {
    private static StringBuilder sb = new StringBuilder();
    private static int N; // 선거구 종류
    private static int[] area;
    private static Vector<Vector<Integer>> v;
    private static boolean[] selected;
    private static Vector<Integer> area1;
	private static Vector<Integer> area2;
	private static Queue<Integer> q;
	private static int result;
	
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(in.readLine());
        area = new int[N+1];
        selected = new boolean[N+1];
        v = new Vector<>();
        for(int i = 0; i<N+1; i++) v.add(new Vector<>());
        result = Integer.MAX_VALUE;
        
        String[] data = in.readLine().split(" ");
        for(int i = 1; i<=N; i++) {
        	area[i] = Integer.parseInt(data[i-1]);
        }
        
        for(int i = 1; i<=N; i++) {
        	String[] input = in.readLine().split(" ");
        	int count = Integer.parseInt(input[0]);
        	
        	for(int j = 1; j<=count; j++) {
        		v.get(i).add(Integer.parseInt(input[j]));
        	}
        }
        
        divArea(0);
        if(result == Integer.MAX_VALUE) sb.append(-1 + "\n");
        else sb.append(result);
        System.out.println(sb);
    }
    
    // 조합으로 선거구 나누기
    private static void divArea(int cnt) {
    	if(cnt == N) {
    		area1 = new Vector<>();
    		area2 = new Vector<>();
    		
    		for(int i = 1; i<=N; i++) {
    			if(selected[i]) {
    				area1.add(i);
    			}
    			else {
    				area2.add(i);
    			}
    		}
    		
    		
    		if(area1.size() == 0 || area2.size() == 0) return;
    		if(connect(area1) && connect(area2)) {
    			// 차 구하기
    			areaDiff();
    		}
    		return;
    	}
    	
    	selected[cnt] = true;
    	divArea(cnt+1);
    	selected[cnt] = false;
    	divArea(cnt+1);
    }
    
    // 나눈 선거구가 서로 연결되어 있는지 확인
    private static boolean connect(Vector<Integer> checkArea) {
    	boolean[] visited = new boolean[N+1];
    	q = new ArrayDeque<>();
    	q.offer(checkArea.get(0));
    	visited[checkArea.get(0)] = true;
    	int checkCnt = 1;
    	
    	while(!q.isEmpty()) {
    		int current = q.poll();
    		for(int i = 0; i<v.get(current).size(); i++) {
    			int next = v.get(current).get(i);
    			if(visited[next] || checkArea.indexOf(next) == -1) continue;
    			
    			visited[next] = true;
    			q.offer(next);
    			checkCnt++;
    		}
    	}
    	
    	if(checkCnt == checkArea.size()) return true;
    	else return false;
    }
    
    // 차 구하기
    private static void areaDiff() {
    	int hap1 = 0, hap2 = 0;
    	
    	for(int i = 1; i<=N; i++) {
    		if(selected[i]) {
    			hap1 += area[i];
    		}
    		else {
    			hap2 += area[i];
    		}
    	}
    	
    	int temp = Math.abs(hap1 - hap2);
    	result = Math.min(result, temp);
    }
}