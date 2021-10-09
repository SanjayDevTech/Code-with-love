**Problem Statement:** You are given an array consisting of some integer values, you have to find the next greater element for every element, if not found, print -1.


// Function to print next greater element for each array element 
void findNextGreater(int arr[], int n) {
    stack<int>st;
    st.push(arr[0]);
    for(int i = 1; i < n; i++){
        while(!st.empty() && st.top() < arr[i]) {
            cout<<arr[i]<<" ";
            st.pop();
        }
        st.push(arr[i]);
    }
    while(!st.empty()) {
        cout<<"-1"<<" ";
        st.pop();
    }
}

// Time Complexity : O(n)
