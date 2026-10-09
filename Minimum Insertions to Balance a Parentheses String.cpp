class Solution {
    public:
        int minInsertions(string s) {
            int open = 0, ans = 0, n = s.size();
            for(int i = 0;i < n;i++){
                if(s[i] == '(') open++;
                else if(s[i] == ')' && i < n-1 && s[i+1] == ')') {
                    if(open) open--;
                    else ans++;
                    i++;
                }
                else {
                    if(open) {
                        ans++;
                        open--;
                    }
                    else ans += 2;
                }
            }
            return ans + 2 * open;
        }
    };

/* ------------------------------------------- JAVA CODE -----------------------------------------*/
class Solution {
    public int minInsertions(String s) {
        int open = 0, ans = 0, n = s.length();
        for(int i = 0;i < n;i++){
            if(s.charAt(i) == '(') open++;
            else if(s.charAt(i) == ')' && i < n-1 && s.charAt(i+1) == ')') {
                if(open != 0) open--;
                else ans++;
                i++;
            }
            else {
                if(open != 0) {
                    ans++;
                    open--;
                }
                else ans += 2;
            }
        }
        return ans + 2 * open;
    }
}