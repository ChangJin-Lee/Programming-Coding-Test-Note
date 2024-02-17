// 2022KAKAO_TECH_INTERNSHIP성격유형검사하기.java
// survey	choices	result
// ["AN", "CF", "MJ", "RT", "NA"]	[5, 3, 2, 7, 5]	"TCMA"
// ["TR", "RT", "TR"]	[7, 1, 3]	"RCJA"

import java.util.HashMap;

class 프로그래머스_KAKAO_TECH_INTERNSHIP_2022_checkpersonaltype {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        int temp = 0;
        HashMap<Character, Integer> dic = new HashMap<Character, Integer>();
        dic.put('R', 0);
        dic.put('T', 0);
        dic.put('C', 0);
        dic.put('F', 0);
        dic.put('J', 0);
        dic.put('M', 0);
        dic.put('A', 0);
        dic.put('N', 0);

        for (int i = 0; i < survey.length; i++) {
            // System.out.println(survey[i].getClass().getName());
            if (choices[i] < 4) {
                char target = survey[i].charAt(0);
                temp = dic.get(target);
                dic.put(target, temp + 4 - choices[i]);
            } else if (choices[i] > 4) {
                char target = survey[i].charAt(1);
                temp = dic.get(target);
                dic.put(target, temp + choices[i] - 4);
            }
        }

        if (dic.get('R') >= dic.get('T')) {
            answer += 'R';
        } else {
            answer += 'T';
        }
        if (dic.get('C') >= dic.get('F')) {
            answer += 'C';
        } else {
            answer += 'F';
        }
        if (dic.get('J') >= dic.get('M')) {
            answer += 'J';
        } else {
            answer += 'M';
        }
        if (dic.get('A') >= dic.get('N')) {
            answer += 'A';
        } else {
            answer += 'N';
        }
        return answer;
    }

    public static void main(String[] args) {
        String[] a = new String[] { "AN", "CF", "MJ", "RT", "NA" };
        int[] b = new int[] { 5, 3, 2, 7, 5 };

        프로그래머스_KAKAO_TECH_INTERNSHIP_2022_checkpersonaltype k = new 프로그래머스_KAKAO_TECH_INTERNSHIP_2022_checkpersonaltype();
        System.out.println(k.solution(a, b));
    }

}