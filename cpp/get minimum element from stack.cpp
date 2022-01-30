/*returns min element from stack*/
int _stack :: getMin()
{
   //Your code here
    if(s.size()!= 0)
    {
        return s.top();
    }   
    return -1;
}

/*returns poped element from stack*/
int _stack ::pop()
{
   //Your code here
   if(s.size()!= 0)
    {
        s.pop();
        int topVal = s.top();
        s.pop();
        return topVal;
    }
    return -1;
}

/*push element x into the stack*/
void _stack::push(int x)
{
   //Your code here
   
   if(s.size() == 0 || s.top()>x)
    {   
        s.push(x);
        s.push(x);
    }
    else
    {
        int topVal = s.top();
        s.push(x);
        s.push(topVal);
    }
}