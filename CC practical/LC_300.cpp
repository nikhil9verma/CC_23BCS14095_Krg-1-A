class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> arr(n,1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
                if(nums[i]>nums[prev]){
                    
                    arr[i]=max(arr[i],1+arr[prev]);
                }
            }
        }
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
        }
        return maxi;
    }
};