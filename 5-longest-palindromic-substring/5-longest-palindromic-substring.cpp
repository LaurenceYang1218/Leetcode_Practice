class Solution {
public:
    
    int palindromeLength(string s, int start, int end){
        while(start >= 0 && end < s.length() && s[start] == s[end]){
            start--;
            end++;
        }
        return end - start - 1;
    }
    
    string longestPalindrome(string s) {
        int maxLength = 0, length = 1;
        int start = 0;
        if(s.length() == 0) return "";
        else if(s.length() == 1) return s;
        
        for(int i = 0; i < s.length(); ++i){
            int len1 = palindromeLength(s, i, i);
            int len2 = palindromeLength(s, i, i + 1);
            int maxLength = max(len1, len2);
            if(maxLength > length){
                length = maxLength;
                start = i - (length-1) / 2;
            }
        }
        return s.substr(start, length);
    }
};