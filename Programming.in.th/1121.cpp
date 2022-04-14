#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int q;cin >> q;
    while(q--){
        string s;cin >> s;
        stack<char> st;
        int ch = 1;
        for(int i=0;i<s.length();i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            if(st.empty()){
                ch = 0;
                break;
            }
            else if(s[i] == ')'){
                if(st.top() == '('){
                    st.pop();
                }
                else{
                    ch = 0;
                    break;
                }
            }
            else if(s[i] == '}'){
                if(st.top() == '{'){
                    st.pop();
                }
                else{
                    ch = 0;
                    break;
                }
            }
            else if(s[i] == ']'){
                if(st.top() == '['){
                    st.pop();
                }
                else{
                    ch = 0;
                    break;
                }
            }
        }
        if(ch && st.empty()) cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
    return 0;
}
