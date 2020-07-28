vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;        
        if (nums.size() < 3)
            return result;
        
        //What if the vector size is exactly 3??
        
        sort(nums.begin(), nums.end());
        
        int i =  0;
        int j = i + 1;
        int k = nums.size() - 1;
        
        for (i; i < nums.size() - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            
            int num = nums[i];
            int target = 0 - num;
            
            for (k  = nums.size() - 1; k > i + 1; k--) {
                if (k != nums.size() - 1 && nums[k] == nums[k+1])
                    continue;
                
                int target2  =  target - nums[k];
                if (target2 > nums[k-1]  || target2 < nums[i+1])
                    continue;
                
                if (isTargetPresent(nums, target2, i + 1, k - 1)) {
                    //If the  target is present
                    result.push_back({nums[i], target - nums[k], nums[k]});
                }
            }
                
        }
        
        return result;
    }    
    
    
    //This is just a binary search
    bool isTargetPresent(const vector<int> nums, const int target, int l, int r) {
        if (l > r || nums.size() == 0)
            return false;
        
        if (l == r) {
            if (nums[l] == target)
                return true;
            else
                return false;
        }
        
        int midPoint = (l + r ) /2;
        if (target < nums[midPoint]) {
            int newR = midPoint - 1;
            return isTargetPresent(nums, target, l, newR);
        }
        else if (target > nums[midPoint]) {
            int newL = midPoint + 1;
            return isTargetPresent(nums, target, newL, r);
        }
        else  {
            return true;
        }
        
        return false;
    }