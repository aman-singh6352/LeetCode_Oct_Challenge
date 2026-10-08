class Solution {
    public:
        string removeOuterParentheses(string s) {
            string ans;
            int left = 0, right = 0, i = 0, indx = 1;
            while(s[i] != '\0') {
                if(s[i] == '(') right++;
                else left++;
                if(right==left) {
                    if(right > 1) ans += s.substr(indx, (right-1)*2);
                    right = 0,left = 0;
                    indx = i+2;
                }
                i++;
            }
            return ans;
        }
    };

/* --------------------------------------------------- JAVA CODE -----------------------------------------------------*/
class Solution {

    public String removeOuterParentheses(String s) {
        String ans = "";
        int left = 0, right = 0, indx = 1;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(')
                right++;
            else
                left++;
            if (right == left) {
                if (right > 1)
                    ans += s.substring(indx, i);
                right = 0;
                left = 0;
                indx = i + 2;
            }
        }

        return ans;
    }
}