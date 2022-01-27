class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int middle = left+(right-left)/2;
            int middleVal = nums[middle];
            if(middleVal == target) return middle;
            // 1 2 3 4 5 6 7 8 9 0  [4,5,6,7,0,1,2],
            else if(middleVal >= nums[left]){
                if(target >= nums[left]  && target < middleVal){
                    right = middle-1;
                }else{
                    left = middle+1;
                }
            }
            else{
                if(target <= nums[right] && target > middleVal){
                    left = middle+1;
                }else{
                    right = middle-1;
                }
            }

        }
        
        return -1;
    }
};