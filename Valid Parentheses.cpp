class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it:s){
            if(it == '(' || it == '{' || it == '[') st.push(it);
            else if(it == ')') {
                if(st.empty() || st.top() != '(') return false;
                st.pop();
            }
            else if(it == '}') {
                if(st.empty() || st.top() != '{') return false;
                st.pop();
            }
            else{
                if(st.empty() || st.top() != '[') return false;
                st.pop();
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};

/* ------------------------------------------- JAVA CODE ---------------------------------------*/
class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for (char it : s.toCharArray()) {
            if (it == '(' || it == '{' || it == '[') {
                st.push(it);
            } 
            else if (it == ')') {
                if (st.empty() || st.peek() != '(') return false;
                st.pop();
            } 
            else if (it == '}') {
                if (st.empty() || st.peek() != '{') return false;
                st.pop();
            } 
            else {
                if (st.empty() || st.peek() != '[') return false;
                st.pop();
            }
        }

        if (!st.empty()) return false;
        return true;
    }
}