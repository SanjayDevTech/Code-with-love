void SortedStack :: sort()
{
   //Your code here
    
    stack<int> temp;
   
    int t;
    
    while(!s.empty()){
        t = s.top();
        s.pop();
        
        if(temp.empty()){
            temp.push(t);                       //if temp is empty
        }else{
            
            if(temp.top()>t){
                while(temp.top()>t ){
                    s.push(temp.top());         //until the top of the temp is large push it to s
                    temp.pop();
                    
                    if(temp.empty()) break;

                }
                
                temp.push(t);
            }else{
                temp.push(t);
            }
        }
    }
    
    s.swap(temp);                               //at last swap the two stacks.
    
}