#include <stack>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<char> s_char;
        stack<int> s_int;
        string ans;
        for(int i = 0; i < s.length(); ++i) {
            string s_i = "";
            while(isdigit(s[i])) {
                s_i += s[i++];
            }
            if(s_i != "") {
                s_int.push(std::stoi(s_i));
            }
            if(s[i] != ']') s_char.push(s[i]);
            else {
                string temp = "";
                while(s_char.top() != '[') {
                    temp += s_char.top();
                    s_char.pop();
                }
                s_char.pop();
                string temp_new = "";
                for(int j = 0; j < s_int.top(); ++j) {
                    temp_new += temp;
                }
                s_int.pop();
                std::reverse(temp_new.begin(), temp_new.end());
                for(char c:temp_new) s_char.push(c);
            }
        }
        while(!s_char.empty()) {
            ans += s_char.top();
            s_char.pop();
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "3[a]2[bc]";
    string ans = sol.decodeString(s);
    cout << ans;
}
