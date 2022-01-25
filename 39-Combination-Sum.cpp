class Solution {
public:
    vector<int>temp;
    vector<vector<int>>ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,target,0,0);
        return ans;
    }
    void backtrack(vector<int>& candidates,int target,int sum,int index){

        if(target == sum){
            ans.push_back(temp);

        }
        if(sum > target){
            return;
        }

        for(int i = index; i < candidates.size();i++){
            sum += candidates[i]; 
            temp.push_back(candidates[i]);
            backtrack(candidates,target,sum,i);
            sum -= candidates[i];
            temp.pop_back();
        }
        
        
        
    }
};