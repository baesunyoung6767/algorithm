import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

public class Main {
    public static BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
    public static int N;
    public static List<String> words = new ArrayList<>();
    public static Map<String, Integer> wordCnt = new LinkedHashMap<>();

    public static void main(String[] args) throws Exception{
        N = Integer.parseInt(bf.readLine());

        for(int i = 0; i<N; i++) {
            String word = bf.readLine();
            words.add(word);
        }

        //Collections.sort(words);

        for(int i = 0; i<N; i++) {
            String word = words.get(i);
            for(int j = 1; j<=word.length(); j++) {
                String temp = word.substring(0, j);
                int cnt = 1;
                if(wordCnt.get(temp) != null) {
                    cnt = wordCnt.get(temp) + 1;
                }
                wordCnt.put(temp, cnt);
            }
        }

        String maxWord = "";

        for(Entry<String, Integer> elem : wordCnt.entrySet()) {
            String targetWord = elem.getKey();
            int targetCnt = elem.getValue();

            //System.out.println("map >> " + targetWord + " : " + targetCnt);

            if(targetCnt >= 2) {
                if(targetWord.length() > maxWord.length()) {
                    maxWord = targetWord;
                }
            }
        }

        String resultA = "";
        String resultB = "";

        for(int i = 0; i<N; i++) {
            String word = words.get(i);

            if(word.length() < maxWord.length()) continue;

            String wordCut = word.substring(0, maxWord.length());

            if(wordCut.equals(maxWord)) {
                if(resultA.equals("")) {
                    resultA = word;
                } else {
                    if(resultA.equals(word)) continue;
                    resultB = word;
                }
            }

            if(!resultA.equals("") && !resultB.equals("")) break;
        }

        System.out.println(resultA);
        System.out.println(resultB);
    }
}
