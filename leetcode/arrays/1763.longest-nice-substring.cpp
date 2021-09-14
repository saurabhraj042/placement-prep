
class Solution {
public:
    string longestNiceSubstring(string s) {
        return soln_2(s);
    }
    // Optimal
    string soln_2 (string &s) {
        unordered_set <int> st (begin(s), end(s));
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (st.count(tolower(s[i])) && st.count(toupper(s[i]))) continue;

            string left = soln_2(s.substr(0, i));
            string right = soln_2(s.substr(i + 1));

            return left.size() >= right.size() ? left : right;   
        }

        return s;
    }

    // Brute force
     bool isNice (string &s) {
        unordered_set<char> st(begin(s), end(s)); // Intialize set with all elements of s
        
        for(char &ch : s) {
            if(!st.count(tolower(ch)) || !st.count(toupper(ch)))
                return false;
        }
        return true;
    }
    string soln_1 (string s) {
        string result = "";
        int n = s.length();
        
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                string temp = s.substr(i, j-i+1);
                if(isNice(temp) && temp.length() > result.length())
                    result = temp;
            }
        }
        
        return result;
    }
};

