import java.util.Scanner;
public class bj23303_D2 {
    public static boolean checkstr(String str){
        for( int i =0 ; i<str.length() - 1 ; i++){
            if((str.charAt(i) == 'D' || str.charAt(i) == 'd') && str.charAt(i+1) == '2'){
                return true;
            }
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        if(checkstr(str)) System.out.print("D2");
        else System.out.print("unrated");
    }
}