// 1. 각 큐의 합을 구한다
// 1-1. 큐의 합이 같으면 종료
// 2. 큐의 합이 큰 것을 작은 것으로 값을 하나씩 옮기고 카운트 증가
import java.util.*;

class Solution {
    public static Queue<Long> q1 = new LinkedList<>();
    public static Queue<Long> q2 = new LinkedList<>();
    
    public long solution(int[] queue1, int[] queue2) {
        long answer = 0;
        
        for(int i = 0; i<queue1.length; i++) {
            q1.add((long)queue1[i]);
        }
        
        for(int i = 0; i<queue2.length; i++) {
            q2.add((long)queue2[i]);
        }
        
        long s1 = calcSum(q1);
        long s2 = calcSum(q2);
        
        int limit = queue1.length > queue2.length ? queue1.length : queue2.length;
        
        while(true) {
            if(s1 == s2) break;
            
            if((s1 + s2) % 2 != 0) {
                answer = -1;
                break;
            }
            
            if(q1.size() == 0 || q2.size() == 0) {
                answer = -1;
                break;
            }
            
            if(answer >= limit * 4) {
                answer = -1;
                break;
            }
            
            if(s1 > s2) {
                long target = q1.poll();
                s1 -= target;
                s2 += target;
                q2.add(target);
            } else if(s1 < s2) {
                long target = q2.poll();
                s1 += target;
                s2 -= target;
                q1.add(target);
            }
            
            answer += 1;
        }
        
        return answer;
    }
    
    public long calcSum(Queue<Long> q) {
        long s = 0;
        
        for(long temp : q) {
            s += temp;
        }
        
        return s;
    }
}