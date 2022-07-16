class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map<int, int> m;
        for(int i = 0; i < nums.size(); ++i){
            map<int, int>::iterator it = m.find(nums[i]);
            if(it == m.end()){
                m.insert({target - nums[i], i});
            }else{
                ans.push_back(m[nums[i]]);
                ans.push_back(i);
            }
        }
        return ans;
    }
};