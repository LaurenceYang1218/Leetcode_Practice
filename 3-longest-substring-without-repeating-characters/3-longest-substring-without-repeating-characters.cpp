class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, ans = 0;
        set<char> st;
        while(i < s.length()){
            char c = s[i];
            while (st.find(c) != st.end()){
                st.erase(st.find(s[j]));
                j++;
            }
            st.insert(c);
            ans = max(ans, i - j + 1);
            i++;  
          
            
        }
        return ans;
    }
};