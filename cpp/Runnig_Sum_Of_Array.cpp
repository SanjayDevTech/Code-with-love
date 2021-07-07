//Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

//Return the running sum of nums.


//Input: nums = [1,2,3,4]
//Output: [1,3,6,10]
//Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].


vector<int> runningSum(vector<int>& nums) {
        int sum=0;
        vector<int> ans;
        for(auto it:nums) {
            sum+=it;
            ans.push_back(sum);
            
        }
         return ans;
    }
