
/* Execution time 0.01 sec.  solved using two stack in O(n) time */

void printSpiral(Node *root)
{
    //Your code here
    
    if(root == NULL) return;
    
    stack<Node *>s1;
    stack<Node *> s2;
    
    s1.push(root);
    
    while(!s1.empty() || !s2.empty()){
        
        while(!s1.empty()){
            
            Node* top  = s1.top();
            s1.pop();
            
            cout<<top->data<<" ";
            
            if(top->right) s2.push(top->right);
            if(top->left) s2.push(top->left);
        }
        
        while(!s2.empty()){
            
            Node*top = s2.top();
            s2.pop();
            
            cout<<top->data<<" ";
            
            if(top->left) s1.push(top->left);
            if(top->right) s1.push(top->right);
        }
    }
}
