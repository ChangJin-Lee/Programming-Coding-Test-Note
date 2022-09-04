import java.util.HashMap;
class Solution {
    public String solution(String[] survey, int[] choices) {
        String answer = "";
        int temp = 0;
        HashMap<Character, Integer> dic = new HashMap<Character, Integer>();
        dic.put('R',0);
        dic.put('T',0);
        dic.put('C',0);
        dic.put('F',0);
        dic.put('J',0);
        dic.put('M',0);
        dic.put('A',0);
        dic.put('N',0);
        
        for(int i=0; i < survey.length;i++){
            // System.out.println(survey[i].getClass().getName());
            if(choices[i]<4){
                char target = survey[i].charAt(0);
                temp = dic.get(target);
                dic.put(target,temp+4-choices[i]);
            }
            else if(choices[i]>4){
                char target = survey[i].charAt(1);
                temp = dic.get(target);
                dic.put(target,temp+choices[i]-4);
            }
        }
        
        if(dic.get('R') >= dic.get('T')){
            answer+='R';
        }
        else{
            answer+='T';
        }
        if(dic.get('C') >= dic.get('F')){
            answer+='C';
        }
        else{
            answer+='F';
        }if(dic.get('J') >= dic.get('M')){
            answer+='J';
        }
        else{
            answer+='M';
        }if(dic.get('A') >= dic.get('N')){
            answer+='A';
        }
        else{
            answer+='N';
        }
        return answer;
    }
}