#include<bits/stdc++.h>
using namespace std ; 
class Solution {
public:    int minOperations(vector<int>& nums, int x) {
        int n = nums.size() ; 
        int sum = accumulate(nums.begin(),nums.end(),0) ; 
        if(sum < x) return -1 ; 
        if(sum == x) return n ; 
        int target = sum - x ; 
        int curr_sum = 0 ; 
        int max_len = -1 ; 
        int j = 0 ; 
        for(int i=0;i<n;i++){
            curr_sum += nums[i] ; 
            while(curr_sum > target){
                curr_sum -= nums[j] ; 
                j++ ; 
            }
            if(curr_sum == target){
                max_len = max(max_len,i-j+1) ; 
            }
        }
        return max_len == -1 ? -1 : n - max_len ; 
    }
};