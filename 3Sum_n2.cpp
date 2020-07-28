#include  <iostream>
#include <vector>

using namespace  std;

vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;        
        if (nums.size() < 3)
            return result;
        
        sort(nums.begin(), nums.end());
        
        int i =  0;
        int j = i + 1;
        int k = nums.size() - 1;
        
        for  (int  i = 0; i < nums.size() - 2; i++)    {
            if  (i  !=  0  &&  nums[i] == nums[i-1])
                continue;
            
            j = i + 1;
            k = nums.size() - 1;
            
            int target = 0 - nums[i];
            
            while (j < k) {
                if (k  !=  nums.size()  -  1  && nums[k]  ==  nums[k+1])  {
                    --k;
                    continue;
                }
                
                if  (target > nums[j] +  nums[k])  {
                    ++j;
                }
                else if  (target  < nums[j] +  nums[k])  {
                    --k;
                }
                else {
                    result.push_back({nums[i],  nums[j],  nums[k]});
                    --k;
                }
            }
        }
        
        return result;
    }
    
    int  main() {
    
    return 0;
    
    }
