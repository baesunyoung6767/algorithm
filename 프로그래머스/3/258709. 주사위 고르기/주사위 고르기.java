import java.util.*;

class Solution {
    public static int[] answer;
    public static int N;
    public static int[][] dices;
    public static int[] selected;
    public static List<Integer> arrA;
    public static List<Integer> arrB;
    public static int maxVal = -1;
    
    public int[] solution(int[][] dice) {
        N = dice.length;
        dices = dice;
        answer = new int[N / 2];
        selected = new int[N];    
        
        selectA(0, 0);
        
        return answer;
    }
    
    public static void selectA(int dep, int len) {
        if(dep == N / 2) {
            // 선택한 조합으로 a가 승리할 수 있는 경우의 수 구하기
            int winCnt = chkResult();
            
            if(winCnt > maxVal) {
                maxVal = winCnt;
                
                int idx = 0;
                for(int i = 0; i<N; i++) {
                    if(selected[i] == 1) {
                        answer[idx] = i + 1;
                        idx++;
                    }
                }
            }
            return;
        }
        
        for(int i = len; i<N; i++) {
            selected[i] = 1;
            selectA(dep + 1, i + 1);
            selected[i] = 0;
        }
    }
    
    public static int chkResult() {
        int count = 0;
        
        makeArr();
        
        Collections.sort(arrB);
        
        for(int i = 0; i<arrA.size(); i++) {
            int target = arrA.get(i);
            
            // arrB에서 target보다 작은 값이 몇 개인지 구함
            int start = 0;
            int end = arrB.size() - 1;
            int idx = -1;
            
            while(start <= end) {
                int mid = (start + end) / 2;
                
                if(arrB.get(mid) < target) {
                    start = mid + 1;
                    idx = Math.max(idx, mid);
                } else {
                    end = mid - 1;
                }
            }
            
            if(idx != -1) {
                count += idx + 1;
            }
        }
        
        return count;
    }
    
    public static void makeArr() {
        arrA = new ArrayList<>();
        arrB = new ArrayList<>();
        
        int[][] diceA = new int[N/2][6];
        int[][] diceB = new int[N/2][6];
        
        int a = 0;
        int b = 0;
        
        for(int i = 0; i<N; i++) {
            if(selected[i] == 1) {
                diceA[a] = dices[i];
                a++;
            } else {
                diceB[b] = dices[i];
                b++;
            }
        }
        
        makeArrSum(diceA, 0, 0, arrA);
        makeArrSum(diceB, 0, 0, arrB);
    }
    
    public static void makeArrSum(int[][] dice, int depth, int sum, List<Integer> arr) {
        if(depth == N/2) {
            arr.add(sum);
            return;
        }
        
        for(int i = 0; i<6; i++) {
            int newSum = sum + dice[depth][i];
            makeArrSum(dice, depth + 1, newSum, arr);
        }
    }
}