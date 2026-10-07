class Solution {
public:
    int minAddToMakeValid(string s) {
        int openBrackets = 0;
        int minAdds = 0;
        
        for (char c : s) {
            if (c == '(') {
                openBrackets++;
            } else {
                if (openBrackets > 0) {
                    openBrackets--;
                } else {
                    minAdds++;
                }
            }
        }
        
        return minAdds + openBrackets;
    }
};