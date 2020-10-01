// Program to implement Generic MinStack
// Which does push() ,pop() ,top() and getMin() in O(1)

#include <iostream>
#include <stack>
using namespace std;

template<class T>
class MinStack
{
	stack<T>data;
	/* The Idea is to push two values into the stack
	 * each time you do a push for MinStack
	 * One for the original one and 
	 * The other for the current Min Value
	*/
	
	/*
	 * |------|-----------|-----|-----
	 * | Val1 | Min1=Val1 | Val2| Min2=min(Min1,Val2)    and So on . . . 
	 * |------|-----------|-----|-----
	  */
	public:
		MinStack(){}
		
		void push(T val)
		{
			if(data.empty())
			{
				data.push(val);
				data.push(val);
			}
			else
			{
				T new_min=min(data.top(),val);
				data.push(val);
				data.push(new_min);
			}
		}
		
		// You need to pop twice
		T pop()
		{
			data.pop();
			T ret_val = data.top();
			data.pop();
			return ret_val;
		}
		
		T top()
		{
			T top_min=data.top();
			data.pop();
			T ret_val=data.top();
			data.push(top_min);
			return ret_val;
		}
		
		
		// Just Pop the top value which
		// maintains the min by default
		T getMin()
		{
			return data.top();
		}
};


int main()
{
	MinStack<int>M1;
	M1.push(2);
	M1.push(5);
	M1.push(7);
	M1.push(3);
	/*
	 * The Final MinStack looks like this:
	 * |---|---|---|---|---|---|---|---|
	 * | 2 | 2 | 5 | 2 | 7 | 2 | 3 | 2 |
	 * |---|---|---|---|---|---|---|---|
	 *                           ^   ^
	 *                           |   |
	 *                          Top Min
	  */
	
	
	cout<<"Min: "<<M1.getMin()<<" "<<"Top: "<<M1.top()<<endl;
	
	int ret = M1.pop();
	
	/*
	 * The Resultant MinStack looks like this:
	 * |---|---|---|---|---|---|
	 * | 2 | 2 | 5 | 2 | 7 | 2 |  
	 * |---|---|---|---|---|---|
	  */
	  
	cout<<"Min: "<<M1.getMin()<<" "<<"Top: "<<M1.top()<<" Popped Val: "<<ret<<endl;
	return 0;
}
