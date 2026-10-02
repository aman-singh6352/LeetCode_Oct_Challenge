class Solution {
    public:
        void generate(int open, int close, string temp, vector<string> &ans, int n){
            if(open == close && open == n) {
                ans.push_back(temp);
                return;
            }
            if(open < n) {
                temp.push_back('(');
                generate(open+1, close, temp, ans, n);
                temp.pop_back();
            }
            if(open  > close) {
                temp.push_back(')');
                generate(open, close+1, temp, ans, n);
                temp.pop_back();
            }
        }
        vector<string> generateParenthesis(int n) {
           vector<string> ans;
           string temp = "";
           generate(0, 0, temp, ans, n); // open close vector n
           return ans;
        }
    };

/* ----------------------------------------- JAVA CODE ------------------------------------------*/
class Solution {
    public void generate(int open, int close, StringBuilder temp, List<String> ans, int n){
        if(open == close && open == n) {
            ans.add(temp.toString());
            return;
        }
        if(open < n) {
            temp.append('(');
            generate(open+1, close, temp, ans, n);
            temp.deleteCharAt(temp.length()-1);
        }
        if(open  > close) {
            temp.append(')');
            generate(open, close+1, temp, ans, n);
            temp.deleteCharAt(temp.length()-1);
        }
    }
    public List<String> generateParenthesis(int n) {
       List<String> ans = new ArrayList<>();
       StringBuilder temp = new StringBuilder();
       generate(0, 0, temp, ans, n);// open close vector n
       return ans;
    }
}