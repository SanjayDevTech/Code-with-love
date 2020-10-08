import java.io.*;
/***************
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		Queue<Integer> st = new Queue<Integer>();

		int choice = s.nextInt();
		int input;

		while (choice !=-1) {
			if(choice == 1) {
				input = s.nextInt();
				st.enqueue(input);
			}
			else if(choice == 2) {
				try {
					System.out.println(st.dequeue());
				} catch (QueueEmptyException e) {
					System.out.println(-1);
				}
			}
			else if(choice == 3) {
				try {
					System.out.println(st.front());
				} catch (QueueEmptyException e) {
					System.out.println(-1);
				}
			}
			else if(choice == 4) {
				System.out.println(st.size());
			}
			else if(choice == 5) {
				System.out.println(st.isEmpty());
			}
			choice = s.nextInt();
		}
	}
}

class Node<T> {
	T data;
	Node<T> next;

	public Node(T data) {
		this.data = data;
        
	}
}


 ***********/



class QueueEmptyException extends Exception {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;


}



public class Queue<T> {
    private Node<T> rear;
        private Node <T> front;
        int size;

	public Queue() {
        rear=null;
        front =null;
        size=0;

	}

	public void enqueue(T data) {
        
       Node<T> curr = new Node<> (data);
        size++;
        if(rear==null){
            front=curr;
        	rear=curr;
            
        }
            
        else{
            rear.next=curr;
        	rear=curr;
        }
        // size++;

	}

	public int size() {
       return size;

	}

	public boolean isEmpty() {
       return size==0;
	}

	public T dequeue() throws QueueEmptyException {
        if(front==null){
            throw new QueueEmptyException();
        }
        T temp= front.data;
        front=front.next;
        if(front ==null){
            rear=null;
        }
        size--;
        return temp;
        

	}

	public T front() throws QueueEmptyException {
        if(front==null){
            throw new QueueEmptyException();
        }
        return front.data;

	}
   
}
