public class Stack
{
	private int arr[];
	private int top;
	private int capacity;

	// Constructor to initialize stack
	Stack(int size)
	{
		arr = new int[size];
		capacity = size;
		top = -1;
	}

	// Utility function to add an element x in the stack
	public void push(int x)
	{
		if (top==capacity-1)
		{
			System.out.println("OverFlow\nProgram Terminated\n");
			
		}else{

		System.out.println("Inserting " + x);
		arr[++top] = x;
	}}

	// Utility function to pop top element from the stack
	public int pop()
	{
		// check for stack underflow
		if (top==-1)
		{
			System.out.println("UnderFlow\nProgram Terminated");
			return 0;
			
		}else{

		System.out.println("Removing " + returnTop());

		// decrease stack size by 1 and (optionally) return the popped element
		return arr[top--]; 
	}}

	// Utility function to return top element in a stack
	public int returnTop()
	{
		if (top!=-1)
			return arr[top];
		else
			return -1;

		
	}

	// Utility function to return the size of the stack
	public int size()
	{
		return top + 1;
	}

	
	public static void main (String[] args)
	{
		Stack stack = new Stack(5);

		stack.push(10);		// Inserting 1 in the stack
		stack.push(20);
		stack.push(30);
		stack.push(40);// Inserting 2 in the stack

		stack.pop();		// removing the top 2
		stack.pop();
		stack.pop();     // removing the top 1

		stack.push(50);		// Inserting 3 in the stack

		System.out.println("Top element is: " + stack.returnTop());
		System.out.println("Stack size is " + stack.size());

		stack.pop();
		stack.pop();   // removing the top 3

		// check if stack is empty
		if (stack.top==-1)
			System.out.println("Stack Is Empty");
		else
			System.out.println("Stack Is Not Empty");
	}
}
