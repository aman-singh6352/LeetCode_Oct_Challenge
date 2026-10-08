class Solution {
    public:
        vector<string> ans;
    
        bool isValid(const string& s) {
            int cnt = 0;
            for (char ch : s) {
                if (ch == '(') cnt++;
                else if (ch == ')') {
                    if (--cnt < 0) return false;
                }
            }
            return cnt == 0;
        }
    
        void solve(string s, int start, int l, int r) {
            if (l == 0 && r == 0) {
                if (isValid(s)) ans.push_back(s);
                return;
            }
            for (int i = start; i < s.size(); i++) {
                if (i > start && s[i] == s[i - 1]) continue;
    
                if (s[i] == '(' && l > 0) {
                    solve(s.substr(0, i) + s.substr(i + 1), i, l - 1, r);
                } else if (s[i] == ')' && r > 0) {
                    solve(s.substr(0, i) + s.substr(i + 1), i, l, r - 1);
                }
            }
        }
    
        vector<string> removeInvalidParentheses(string s) {
            int l = 0, r = 0;
            for (char ch : s) {
                if (ch == '(') l++;
                else if (ch == ')') {
                    if (l > 0) l--;
                    else r++;
                }
            }
            solve(s, 0, l, r);
            return ans;
        }
    };

/* -------------------------------------------------- JAVA CODE -----------------------------------------------*/
class Solution {
    List<String> ans = new ArrayList<>();
    boolean isValid(String s) {
        int cnt = 0;
        for (char ch : s.toCharArray()) {
            if (ch == '(') cnt++;
            else if (ch == ')') {
                if (--cnt < 0) return false;
            }
        }
        return cnt == 0;
    }
    void solve(String s, int start, int l, int r) {
        if (l == 0 && r == 0) {
            if (isValid(s)) {
                ans.add(s);
            }
            return;
        }
        for (int i = start; i < s.length(); i++) {
            if (i > start && s.charAt(i) == s.charAt(i - 1)) {
                continue;
            }
            if (s.charAt(i) == '(' && l > 0) {
                String newString = s.substring(0, i) + s.substring(i + 1);
                solve(newString, i, l - 1, r);

            } else if (s.charAt(i) == ')' && r > 0) {
                String newString = s.substring(0, i) + s.substring(i + 1);
                solve(newString, i, l, r - 1);
            }
        }
    }
    public List<String> removeInvalidParentheses(String s) {
        int l = 0, r = 0;
        for (char ch : s.toCharArray()) {
            if (ch == '(') l++;
            else if (ch == ')') {
                if (l > 0) l--;
                else r++;
            }
        }
        solve(s, 0, l, r);
        return ans;
    }
}