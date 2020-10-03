/* 
import java.util.Scanner;
import java.util.Queue;

public class Main {

    public static void main(String args[]){
        StackUsingQueue<Integer> s = new StackUsingQueue<>();
        Scanner sc = new Scanner(System.in);
        int choice; 
        int input;

        while(true){

            choice = sc.nextInt();

            switch(choice){
                case 1:
                    input = sc.nextInt();
                    s.push(input);
                    break;
                case 2:

                    Integer ele = s.pop();

                    if(ele != null) {
                        System.out.println(ele);
                    } else {
                        System.out.println(-1);
                    }
                    break;
                case 3:
                    Integer elem = s.top();
                    if(elem != null) {
                        System.out.println(elem);
                    } else {
                        System.out.println(-1);
                    }
                    break;
                case 4 :
                    System.out.println(s.getSize());
                    break;
                case 5 : // Test
                    Queue<Integer> q = s.getQueue();
                    while(!q.isEmpty()) {
                        Integer e = q.peek();
                        q.remove();
                        System.out.print(e + " ");
                    }   
                    System.out.println();
                    return;
                default:
                    return;
            }
        }
    }
}
*/

import java.util.Stack;}
public class StackUsingQueue<T> {
    private Stack front;
    private
        //Implement the class here
        Stack <T> newStack=new Stack<>();
    StackUsingQueue(){
        front=null;
        rear =null;

    }


    public T top(){

    }
    public int getSize(){
        return size;
    }

}