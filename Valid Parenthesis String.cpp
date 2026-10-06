class Solution {
    public:
        bool checkValidString(string s) {
            int mine = 0, maxe = 0;
            for(int i = 0;i < s.size();i++){
                if(s[i] == '(') mine++, maxe++;
                else if(s[i] == ')') mine--, maxe--;
                else {
                    mine = mine-1;
                    maxe = maxe+1;
                }
                if(mine < 0) mine = 0;
                if(maxe < 0) return false;
            }
            return mine == 0;
        }
    };

/* -------------------------------------------------- JAVA CODE ------------------------------------------------ */
class Solution {
    public boolean checkValidString(String s) {
        int mine = 0, maxe = 0;
        for(int i = 0;i < s.length();i++){
            if(s.charAt(i) == '(') {
                mine++;
                maxe++;
            }
            else if(s.charAt(i) == ')') {
                mine--;
                maxe--;
            }
            else {
                mine = mine-1;
                maxe = maxe+1;
            }
            if(mine < 0) mine = 0;
            if(maxe < 0) return false;
        }
        return mine == 0;
    }
}