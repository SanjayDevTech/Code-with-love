void topView(struct Node *root)
{
    //Your code here
    
    if(root == NULL) return;
    
    map<int, vector<int>> mp;
    
    queue<pair<Node*, int>> q;
    
    q.push({root, 0});
    
    while(!q.empty()){
        int count = q.size();
        
        for(int i = 0;i<count;i++){
            auto temp = q.front();
            
            q.pop();
            
            mp[temp.second].push_back(temp.first->data);
            
            if(temp.first->left != NULL){
                q.push({temp.first->left, temp.second -1});
            }
            
            if(temp.first->right != NULL){
                q.push({temp.first->right, temp.second +1});
            }
        }
    }
    
    for(auto it = mp.begin(); it != mp.end(); it++){
        cout<<(it->second)[0]<<" ";
    }

}
