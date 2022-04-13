#include <bits/stdc++.h>
using namespace std;

string s;
bool ispalindrome(){
    for(int i=0;i<s.length()/2;i++){
        int j = s.length()-i-1;
        if(s[i] == s[j]){
            continue;
        }
        return false;
    }
    return true;
}
bool isdouble(){
    string s1 = s.substr(0,(s.length()/2));
    string s2 = s.substr((s.length()%2==0)?s.length()/2:s.length()/2+1,s.length());
    if(s1 == s2) return true;
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> s;
    for(int i=0;i<s.length();i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] = tolower(s[i]);
        }
    }
    if(ispalindrome()){
        if(isdouble()){
            cout << "Double Palindrome";
        }
        else cout << "Palindrome";
    }
    else cout << "No";
    return 0;
}
