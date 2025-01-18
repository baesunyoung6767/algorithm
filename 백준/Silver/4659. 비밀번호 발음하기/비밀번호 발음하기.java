import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws Exception{
        while(true) {
            String input = bf.readLine();
            int[] alpha = new int[26];

            if(input.equals("end")) break;

            for(int i = 0; i<input.length(); i++) {
                alpha[input.charAt(i) - 'a']++;
            }

            if(alpha['a' - 'a'] == 0 && alpha['e' - 'a'] == 0 && alpha['i' - 'a'] == 0 && alpha['o' - 'a'] == 0 && alpha['u' - 'a'] == 0) {
                System.out.println("<" + input + ">" + " is not acceptable.");
                continue;
            }

            boolean isOk = true;
            for(int i = 2; i<input.length(); i++) {
                if(checkVowels(input.charAt(i-2)) && checkVowels(input.charAt(i-1)) && checkVowels(input.charAt(i))) {
                     isOk = false;
                     break;
                }

                if(checkConsonants(input.charAt(i-2)) && checkConsonants(input.charAt(i-1)) && checkConsonants(input.charAt(i))) {
                    isOk = false;
                    break;
                }
            }

            if(!isOk) {
                System.out.println("<" + input + ">" + " is not acceptable.");
                continue;
            }

            isOk = true;
            for(int i = 1; i < input.length(); i++) {
                if(input.charAt(i-1) == input.charAt(i)) {
                    if(input.charAt(i) != 'e' && input.charAt(i) != 'o')  {
                        isOk = false;
                        break;
                    }
                }
            }

            if(!isOk) {
                System.out.println("<" + input + ">" + " is not acceptable.");
                continue;
            }

            System.out.println("<" + input + ">" + " is acceptable.");
        }
    }

    public static boolean checkVowels(char target) {
        if(target == 'a' || target == 'e' || target == 'i' || target == 'o' || target == 'u') return true;
        else return false;
    }

    public static boolean checkConsonants(char target) {
        if(target != 'a' && target != 'e' && target != 'i' && target != 'o' && target != 'u') return true;
        else return false;
    }
}
