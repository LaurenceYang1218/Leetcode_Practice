### Approach 1 合併後找中位數:
####  Time Complexity: O(m + n)
      
      vector<int> merge(vector<int> nums1, vector<int> nums2){
        vector<int> result;
        int i1 = 0, i2 = 0;
        int len1 = nums1.size(), len2 = nums2.size();
        while(i1 < len1 || i2 < len2){
            if(i1 == len1){
                result.push_back(nums2[i2++]);
            }else if(i2 == len2){
                result.push_back(nums1[i1++]);
            }else{
                if(nums1[i1] < nums2[i2]){
                    result.push_back(nums1[i1++]);
                }else{
                    result.push_back(nums2[i2++]);
                }                
            }
        }
        return result;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> newNums = merge(nums1, nums2);
        double ans = 0.0;
        int mid = newNums.size() / 2;
        if(newNums.size() % 2 == 0){
            ans = (double)(newNums[mid - 1] + newNums[mid]) / 2;
        }else{
            ans = (double)newNums[mid];
        }
        return ans;
    }
    
