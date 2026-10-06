class Solution {
    public:
        int minAddToMakeValid(string s) {
            int ans = 0, cntofclose = 0;
            for(int i = 0;i < s.size();i++){
                if(s[i] == '(') cntofclose++;
                else {
                    if(!cntofclose) ans++;
                    else cntofclose--;
                }
            }
            return ans + cntofclose;
        }
    };

/* --------------------------------------------- JAVA CODE --------------------------------------------*/
class Solution {
    public int minAddToMakeValid(String s) {
        int ans = 0, cntofclose = 0;
        for(int i = 0;i < s.length();i++){
            if(s.charAt(i) == '(') cntofclose++;
            else {
                if(cntofclose == 0) ans++;
                else cntofclose--;
            }
        }
        return ans + cntofclose;
    }
}