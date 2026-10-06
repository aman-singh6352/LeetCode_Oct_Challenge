class Solution {
    public:
        int scoreOfParentheses(string s) {
            int n = s.size();
            vector<int> vec;
            int score = 0;
            for(int i = 0;i < n;i++){
                if(s[i] == '('){
                    vec.push_back(score);
                    score = 0;
                }
                else{
                    if(s[i-1] == '(') score = vec.back() + 1;
                    else {
                        score = vec.back() + score * 2;
                    }
                    vec.pop_back();
                }
            }
            return score;
        }
    };

/* --------------------------------------- OPTIMISED CODE -----------------------------------*/
class Solution {
    public:
        int scoreOfParentheses(string s) {
            int n = s.size();
            int depth = 0, score = 0;
            for(int i = 0;i < n;i++){
                if(s[i] == '(') depth++;
                else {
                    depth--;
                    if(s[i-1] == '(') {
                        score += (1 << depth);
                    }
                }
            }
            return score;
        }
    };

/* ----------------------------------------- JAVA CODE -----------------------------------------*/
class Solution {
    public int scoreOfParentheses(String s) {
        int depth = 0, score = 0;
        for(int i = 0;i < s.length();i++){
            if(s.charAt(i) == '(') depth++;
            else {
                depth--;
                if(s.charAt(i-1) == '(') {
                    score += (1 << depth);
                }
            }
        }
        return score;
    }
}