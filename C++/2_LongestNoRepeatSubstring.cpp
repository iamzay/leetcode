class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        unordered_map<char,int> m;
        for(int i = 0, j = 0; j < s.length(); ++j) {
            if(m.find(s[j]) != m.end() && m[s[j]] >= i) {
                i = m[s[j]] + 1;
            } else {
                maxLen = max(maxLen, j - i + 1);
            }
            m[s[j]] = j;
        }
        return maxLen;
    }
};