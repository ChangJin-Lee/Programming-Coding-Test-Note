// 자바에서는 링크드 리스트를 활용해서 큐를 만들어야함
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
public class bj2161_card1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        if(n == 1) System.out.print(n);
        else{
            Queue<Integer> queue = new LinkedList<>();
            for(int i=0; i<n; i++){
                queue.add(i+1);
            }
            while (true){
                System.out.print(queue.poll()+" ");
                if(queue.size() == 0) break;
                queue.add(queue.poll());
                if(queue.size() == 0) break;
            }
        }
    }
}

