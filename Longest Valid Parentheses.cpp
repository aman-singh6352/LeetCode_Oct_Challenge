class Solution {
    public:
        int longestValidParentheses(string s) {
            int close = 0, open = 0, ans = 0;
            for(auto& it:s){
                if(it == '(') open++;
                else close++;
                if(close > open) {
                    close = open = 0;
                    continue;
                }
                else if(open == close) {
                    ans = max(ans, open+close);
                }
            }
            open = close = 0;
            for(int i = s.size()-1;i >= 0;i--){
                if(s[i] == '(') open++;
                else close++;
                if(open > close) {
                    close = open = 0;
                    continue;
                }
                else if(open == close) {
                    ans = max(ans, open+close);
                }
            }
            return ans;
        }
    };

/* --------------------------------------------------------- JAVA CODE -------------------------------------------------------*/
class Solution {
    public int longestValidParentheses(String s) {
        int close = 0, open = 0, ans = 0;
        for(char it:s.toCharArray()){
            if(it == '(') open++;
            else close++;
            if(close > open) {
                close = open = 0;
                continue;
            }
            else if(open == close) {
                ans = Math.max(ans, open+close);
            }
        }
        open = close = 0;
        for(int i = s.length()-1;i >= 0;i--){
            if(s.charAt(i) == '(') open++;
            else close++;
            if(open > close) {
                close = open = 0;
                continue;
            }
            else if(open == close) {
                ans = Math.max(ans, open+close);
            }
        }
        return ans;
    }
}